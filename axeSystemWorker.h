#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
#include <Timer.h>
#include <AxeFxControl.h>
#include "SdFat.h"

  // USE the ini_files
#include "ini_files/Teensy_Preset_helper.h"
#include "ini_files/Teensy_Scenes_helper.h"
#include "ini_files/Teensy_Image.h"

  // USE the tabs
#include "Screenstyle.h"
#include "axeEffect.h"
#include "presetrange.h"




/*=======================================================================================================================*/


/*=======================================================================================================================================*/
//       INITIALIZE FUNCTIONS
/*---------------------------------------------------------------------------------------------------------------------------------------*/

//Struct to hold information about each scene
struct SceneInfo 
{
  SceneNumber number = -1;
  const char *name;
};

//A list of all of the scenes for this preset
SceneInfo scenes[NUM_SCENES];

//Reset the scene list for the new preset
void onPresetChanging(const PresetNumber number) 
{
  for (byte i = 0; i < NUM_SCENES; i++) {
    scenes[i].number = -1;
  }
}

  void setupHOLDSWITCH()
  {
    debug("\n"); debug("\n"); debug(" * function setupHOLDSWITCH() started on axeSystemWorker.h");
    switch (sceneNumber)
    {
     case 1: previousHOLDSWITCH = SWITCH1; break; 
     case 2: previousHOLDSWITCH = SWITCH2; break; 
     case 3: previousHOLDSWITCH = SWITCH3; break; 
     case 4: previousHOLDSWITCH = SWITCH4; break; 
     case 5: previousHOLDSWITCH = SWITCH6; break; 
     case 6: previousHOLDSWITCH = SWITCH7; break; 
     case 7: previousHOLDSWITCH = SWITCH8; break; 
     case 8: previousHOLDSWITCH = SWITCH9; break;  
      }
     debug("\n"); debug(" previous HOLDSWITCH is set to: "); debug(previousHOLDSWITCH);
    } 



/*=======================================================================================================================================*/
//        This is for the TAP flashlight
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void turnOffFlashingLed()
{  
  {tapTempo_flash_OFF();}  //flashing screen 14
}

void flashLed(int flashDelay)
{ 
  {tapTempo_flash_ON();}   //flashing screen 14
  timer.after(flashDelay, turnOffFlashingLed);
}

void onTapTempo()
{
  if (strcmp(page, "matrix") != 0)
  {switch (tempo_Counter)
  {
    case 0: tempo_Counter = 1; break;
    case 1: tempo_Counter = 2; break;  
    case 2: tempo_Counter = 3; break;
    case 3: tempo_Counter = 4; break;
    case 4: tempo_Counter = 1; break;
  }
    tapTempo_sprite();
    flashLed(TAP_TEMPO_LED_DURATION);
  }
}


/*=======================================================================================================================================*/
//        This is for the metronome
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void metronomeStart()
{
  byte Metronome_start[23] = {0xf0, 0x00, 0x01, 0x74, 0x10, 0x01, 0x52, 0x00, 0x01, 0x00, 0x77, 0x00, 0x2b, 0x55, 0x2a, 0x79, 0x03, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xf7};
  debug("\n"); debug("->->->-> Metronome Started <-<-<-<-"); 
  MIDI.sendSysEx(23, Metronome_start);
}

void metronomeStop()
{
  byte Metronome_stop[23] = {0xf0, 0x00, 0x01, 0x74, 0x10, 0x01, 0x52, 0x00, 0x01, 0x00, 0x77, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0xf7};
  debug("\n"); debug("->->->-> Metronome Stopped <-<-<-<-"); 
  MIDI.sendSysEx(23, Metronome_stop);
}



void PresetNameCallback(const PresetNumber presetNumber, const char *presetName, const byte length) 
{
  //To keep the standard of the Fractal export file "preset names.txt" output, I need to edit the presetnumber and add 3 spaces
  //The equalisation of presetNumber == presetNumberNames  is because this is the only way the program prints all 1023 presetnames

  if (presetNumber == presetNumberNames) 
  {
    presetNameFile = sd.open("preset names.txt", O_WRITE | O_APPEND); 
    char formattedNumber[5];
    snprintf(formattedNumber, sizeof(formattedNumber), "%04d", presetNumber);

    debug("\n"); debug(formattedNumber); debug("   "); debug(presetName);

    digitalWriteFast(CS8, LOW);
    presetNumberStyle();
    tft.println(presetNumber);
    digitalWriteFast(CS8, HIGH);

    presetNumberNames++;
        
    if (presetNumberNames <= 1024) 
    {
      Axe.requestPresetName(presetNumberNames);
      if (presetNameFile) 
      {
        
        String formattedNumber = String(presetNumber);
        while (formattedNumber.length() < 4) {
          formattedNumber = "0" + formattedNumber;
        }
        
        String outputLine = formattedNumber + "   " + presetName + "\n";  
        presetNameFile.print(outputLine);  // 
        delay(10);
      }
    }
    presetNameFile.close();
  }
}




void printAllPresets() 
{
  PresetNumber presetNumberNames = 0;
    if (presetNameFile.open("preset names.txt", O_WRITE)) 
    {
    presetNameFile.truncate(0);
    presetNameFile.close();
    delay(10);
    Serial.println(" SD kaart bestand -> Preset Names.txt leeggemaakt.");
    } 
    clearSceneScreens(); 
    digitalWriteFast (CS8, LOW);
    tft.setTextColor(screen13Style_txt3_color,screen13Style_fillscreen);
    tft.setTextSize(3); tft.setCursor(12, 5);
    tft.println("Updating");
    tft.setTextSize(2); tft.setCursor(40, 35);
    tft.println("SD-CARD"); 
    digitalWriteFast (CS8, HIGH);
  Axe.requestPresetName(presetNumberNames);
}





/*=======================================================================================================================================*/
//        Display the current TEMPO at the TFT
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void onSystemChange() 
{
  newTempo = Axe.getTempo();
  delay(30);
  debug("\n"); debug("\n"); debug(" * function onSystemChange started on axeSystemWorker.h");
  Axe.fetchEffects(true);
  CS14L;
  tft.fillRect(0, 35, 160, 60, tapTempo_screen_RECT_fillscreen); //tapTempoClearScreen();
  tft.setTextColor(tapTempo_screen_txt2_color, tapTempo_screen_RECT_fillscreen);
   if ((newTempo >= 0) && (newTempo < 100))
    { tempoCursor = 60;}
    else if ((newTempo >= 100) && (newTempo < 1000))
    { tempoCursor = 42;} 
  tft.setTextSize(5); tft.setCursor(tempoCursor, 48);
  tft.println(Axe.getTempo());  
  CS14H;
}


//*=======================================================================================================================================*/
//       Set active presetname in screen 13
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void presetName_setting(AxePreset preset)   //Set active presetname in screen 13
{
  debug("\n");  debug("\n");  debug(" * function presetName_setting started on axeSystemWorker.h");


  PresetNumb = CurPreset;  //active_Preset;
  strcpy(active_PresetName, (preset.getPresetName()));
  PresetName_helper();  //on Screenstyle.h


  if (preset.getPresetNumber() < 10)
  { Cursor = 65;  }
  else if ((preset.getPresetNumber() >= 10) && (preset.getPresetNumber() < 100))
  { Cursor = 50;  }
  else if ((preset.getPresetNumber() >= 100) && (preset.getPresetNumber() < 1000))
  { Cursor = 29;  }
  else if (preset.getPresetNumber() >= 1000)
  { Cursor = 10;  }


  if (P13 == 0)
  {
    //Init screen 13
    CS13L;
    screen13Style();
    tft.println(preset.getPresetNumber());
    CS13H;

    if (strcmp(page, "scene") == 0) // On scenepage
    {
    debug("\n"); debug(" variable CurPreset = "); debug(CurPreset); 
    previousPreset = (CurPreset - 1);
    debug("\n"); debug(" variable CurPreset - 1 =  "); debug(CurPreset - 1); 
    if (CurPreset - 1 < 0){previousPreset = lastPreset;}
    nextPreset = (CurPreset + 1);
    debug("\n"); debug(" variable CurPreset + 1 =  "); debug(CurPreset + 1);
    if ((CurPreset + 1) > lastPreset){nextPreset = 0;}
    debug("\n"); debug(" variable active_Preset = "); debug(active_Preset); 
    debug("\n"); debug(" variable previousPreset = "); debug(previousPreset); 
    debug("\n"); debug(" variable nextPreset = "); debug(nextPreset);
    }

    CS13L;
    //row 1
    if (P11 > 10)
    {  tft.setCursor(1, 60); }
    else
    {  tft.setCursor((80 - ((P11 * 9) - 6)), 60); }
       tft.setTextSize(3);
       tft.setTextColor(screen13Style_txt2_color);
       tft.println(PRE11);

    //row 2

    if (P12 > 10)
    { tft.setCursor(1, 90); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 90); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE12);
    CS13H;
  }
  else {
    //Init screen 13
    CS13L;
    screen13Style();
    tft.println(preset.getPresetNumber());
    CS13H;
 
    if (strcmp(page, "scene") == 0) // On scenepage
    {
    debug("\n"); debug(" variable CurPreset = "); debug(CurPreset);   
    previousPreset = (CurPreset - 1);
    debug("\n"); debug(" variable CurPreset - 1 =  "); debug(CurPreset - 1);
    if (CurPreset -1 < 0){previousPreset = lastPreset;}
    nextPreset = (CurPreset + 1);
    debug("\n"); debug(" variable CurPreset + 1 =  "); debug(CurPreset + 1);
    if (CurPreset + 1 > lastPreset){nextPreset = 0;}
    debug("\n"); debug(" variable active_Preset = "); debug(active_Preset); 
    debug("\n"); debug(" variable previousPreset = "); debug(previousPreset); 
    debug("\n"); debug(" variable nextPreset = "); debug(nextPreset);
    }

    CS13L;
    //row 1
    if (P11 > 10)
    {  tft.setCursor(1, 49); }
    else
    { tft.setCursor((80 - ((P11 * 9) - 6)), 49);    }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE11);

    //row 2
    tft.println();
    if (P12 > 10)
    { tft.setCursor(1, 78); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 78); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE12);

    //row 3
    if (P13 > 10)
    { tft.setCursor(1, 107); }    
    else
    { tft.setCursor((80 - ((P13 * 9) - 6)), 107); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE13);
  }
  CS13H;
  presetUpDownscreens();
}


/*=======================================================================================================================================*/
//       IS LOOPER OR WAH AVAILABLE?
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void wah_looper()
{
  if (strcmp(page,"AMP_effect") !=0)
  {
    if (wahActive != true)
    { 
    CS11L; NOWAH_screen(); CS11H;
    debug("\n"); debug(" -> WAH not active");
    }
      else 
      {
      CS11L; YESWAH_screen(); CS11H;
      debug("\n"); debug(" -> WAH is active");
      }


    if (looperActive != true) 
    {
    CS12L; NOLOOPER_screen(); CS12H;
    debug("\n"); debug(" -> LOOPER not active");
    }
      else 
      {
      CS12L; YESLOOPER_screen(); CS12H;
      debug("\n"); debug(" -> Looper is active");
      }


      // restoring looper and wah pointer to false.  The code from the effect function will change it to true if so...
      looperActive = false; 
      debug("\n"); debug(" -> starting effects lookup | looperActive is reset to:  false");
      wahActive = false; 
      debug("\n"); debug(" -> starting effects lookup | wahActive is reset to:  false");
  }
}

/*=======================================================================================================================================

                                               _____  _____ ______ _   _ ______  _____ 
                                              / ____|/ ____|  ____| \ | |  ____|/ ____|
                                             | (___ | |    | |__  |  \| | |__  | (___  
                                              \___ \| |    |  __| | . ` |  __|  \___ \ 
                                              ____) | |____| |____| |\  | |____ ____) |
                                             |_____/ \_____|______|_| \_|______|_____/ 
                                           

   =======================================================================================================================================*/
//       INI SCENES build-up SCREENS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_scenes() 
{
    debug("\n"); debug("\n"); debug(" * function ini_scenes started on axeSystemWorker.h");  

    debug("\n"); debug(" -> Active scenenumber = "); debug(sceneNumber);
  
    /* =============== printing scenes on the screens ==============*/

    AxePreset preset = (Axe.getCurrentPreset());

    if (getScenes == true)
    {
      if (auditionMode != true)  // ON auditionmode we dont need scenes, only the wah and looper function at the end 
      {
      CS1L, CS2L, CS3L, CS4L, CS6L, CS7L, CS8L, CS9L;
      sceneStyle0();
      CS1H, CS2H, CS3H, CS4H, CS6H, CS7H, CS8H, CS9H;

          tft.setTextDatum(C_BASELINE);

            // Calculate the horizontal position to center the text
            int x = tft.width() / 2;
            int x2 = (tft.width() / 2) + 4;

            // Calculate the vertical positions for each line of text
            int y1 = 6;
            int y2 = 36;
            int y3 = 66;


          CS1L; if(sceneNumber == 1){scene_ACTIVEbezel();} sceneStyle3(); tft.drawString(SCE11, x, y1); tft.drawString(SCE12, x2, y2); tft.drawString(SCE13, x2, y3); CS1H;
          CS2L; if(sceneNumber == 2){scene_ACTIVEbezel();} sceneStyle5(); tft.drawString(SCE21, x, y1); tft.drawString(SCE22, x2, y2); tft.drawString(SCE23, x2, y3); CS2H;
          CS3L; if(sceneNumber == 3){scene_ACTIVEbezel();} sceneStyle3(); tft.drawString(SCE31, x, y1); tft.drawString(SCE32, x2, y2); tft.drawString(SCE33, x2, y3); CS3H;
          CS4L; if(sceneNumber == 4){scene_ACTIVEbezel();} sceneStyle5(); tft.drawString(SCE41, x, y1); tft.drawString(SCE42, x2, y2); tft.drawString(SCE43, x2, y3); CS4H;
          CS6L; if(sceneNumber == 5){scene_ACTIVEbezel();} sceneStyle3(); tft.drawString(SCE51, x, y1); tft.drawString(SCE52, x2, y2); tft.drawString(SCE53, x2, y3); CS6H;
          CS7L; if(sceneNumber == 6){scene_ACTIVEbezel();} sceneStyle5(); tft.drawString(SCE61, x, y1); tft.drawString(SCE62, x2, y2); tft.drawString(SCE63, x2, y3); CS7H;
          CS8L; if(sceneNumber == 7){scene_ACTIVEbezel();} sceneStyle3(); tft.drawString(SCE71, x, y1); tft.drawString(SCE72, x2, y2); tft.drawString(SCE73, x2, y3); CS8H;
          CS9L; if(sceneNumber == 8){scene_ACTIVEbezel();} sceneStyle5(); tft.drawString(SCE81, x, y1); tft.drawString(SCE82, x2, y2); tft.drawString(SCE83, x2, y3); 
                if (L81 == 0) {axelman8_emptyScene_picture();} CS9H;
          
        }
	}

      presetName_setting(preset);  //Fill screen 13 with active preset name and number
      wah_looper();
      tapTempo_screen();
      
      //restoring settings to false
      getScenes = false;  // scenes are allready printed
      debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
      debug("\n"); debug(" -> End scene page buildup");

}




/*=======================================================================================================================================*/
//       Fetch all scenes 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void onSceneName(const SceneNumber number, const char* name, const byte length)
{

  if (getScenes == 1)
  {
    /*=============================================================
       ======  ONLY operate if needed.  LIKE getScenes = true  ====*/

    debug("\n"); debug(" Scene "); debug(number); debug(": "); debug(name);


    SceneName_helper(name);

    /*debug("\nstr1: "); debug(str1);
    debug("\nstr2: "); debug(str2);
    debug("\nstr3: "); debug(str3);*/

    /*======================================
      =       SCENE names And SCREENS      =
      =             SCENE names            =
      ======================================*/
    switch (number) 
  {
  case 1: SceneName_helper(name); L11 = str1.length(); L12 = str2.length(); L13 = str3.length(); str1.toCharArray(SCE11, L11 + 1); str2.toCharArray(SCE12, L12 + 1); str3.toCharArray(SCE13, L13 + 1); break;
  case 2: SceneName_helper(name); L21 = str1.length(); L22 = str2.length(); L23 = str3.length(); str1.toCharArray(SCE21, L21 + 1); str2.toCharArray(SCE22, L22 + 1); str3.toCharArray(SCE23, L23 + 1); break;
  case 3: SceneName_helper(name); L31 = str1.length(); L32 = str2.length(); L33 = str3.length(); str1.toCharArray(SCE31, L31 + 1); str2.toCharArray(SCE32, L32 + 1); str3.toCharArray(SCE33, L33 + 1); break;
  case 4: SceneName_helper(name); L41 = str1.length(); L42 = str2.length(); L43 = str3.length(); str1.toCharArray(SCE41, L41 + 1); str2.toCharArray(SCE42, L42 + 1); str3.toCharArray(SCE43, L43 + 1); break;
  case 5: SceneName_helper(name); L51 = str1.length(); L52 = str2.length(); L53 = str3.length(); str1.toCharArray(SCE51, L51 + 1); str2.toCharArray(SCE52, L52 + 1); str3.toCharArray(SCE53, L53 + 1); break;
  case 6: SceneName_helper(name); L61 = str1.length(); L62 = str2.length(); L63 = str3.length(); str1.toCharArray(SCE61, L61 + 1); str2.toCharArray(SCE62, L62 + 1); str3.toCharArray(SCE63, L63 + 1); break;
  case 7: SceneName_helper(name); L71 = str1.length(); L72 = str2.length(); L73 = str3.length(); str1.toCharArray(SCE71, L71 + 1); str2.toCharArray(SCE72, L72 + 1); str3.toCharArray(SCE73, L73 + 1); break;
  case 8: SceneName_helper(name); L81 = str1.length(); L82 = str2.length(); L83 = str3.length(); str1.toCharArray(SCE81, L81 + 1); str2.toCharArray(SCE82, L82 + 1); str3.toCharArray(SCE83, L83 + 1); break;
  }

    /*===========================================
      =======   SCENE names from Axe-Fx    ======
      ===========================================*/

    //  //Record current scene in the list
    scenes[number - 1].number = number;
    scenes[number - 1].name = name;


    //----------This is the active scene number---------------

    //Request the first scene that we don't have yet.
    // Only request one at a time to avoid filling up RX buffer
    for (byte i = 0; i < NUM_SCENES; i++) {
      if (scenes[i].number == -1) {
        Axe.requestSceneName(i + 1);
        break;
      }
      if (i == 7) 
      {
        debug("\n"); debug("\n");   debug(" * function ini_scenes called from function onscenename() on axeSystemWorker.h");
        ini_scenes();  // build the scene page on the screens
        debug("\n"); debug("\n");   debug(" * function onscenename succesfully loaded on axeSystemWorker.h");
      }
    }
  }
}

/*=======================================================================================================================================
                                        ______ ______ ______ ______ _____ _______ _____ 
                                       |  ____|  ____|  ____|  ____/ ____|__   __/ ____|
                                       | |__  | |__  | |__  | |__ | |       | | | (___  
                                       |  __| |  __| |  __| |  __|| |       | |  \___ \ 
                                       | |____| |    | |    | |___| |____   | |  ____) |
                                       |______|_|    |_|    |______\_____|  |_| |_____/ 

   =======================================================================================================================================*/


                                                 
/*=======================================================================================================================================*/
//       EFFECT FILTER and LOOPER SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

bool onEffectFilter(const PresetNumber number, AxeEffect effect) 
{
  if  (strcmp(page, "AMP_effect") == 0) 
  {
    return effect.isCab() || effect.isDistort();
  }
    else
    {
      return  effect.isDelay()   || effect.isPhaser()    || effect.isMulticomp()  || effect.isChorus()  || effect.isDrive()    || 
              effect.isReverb()  || effect.isPlex()      || effect.isCompressor() || effect.isFlanger() || effect.isMultitap() || 
              effect.isMegatap() || effect.isMulticomp() || effect.isLooper()     || effect.isWah()     ||  effect.isParaEQ()  || 
              effect.isFilter()  || effect.isGrapheqEQ() || effect.isMultiplexer();
 
              /*effect.isPitch() || */
    }
 }

/*=======================================================================================================================================*/
//       SHOW EFFECTS ON SCREEN
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

  const size_t tagSz = 10;
  char tag[tagSz];
  const size_t sz = 25;
  char buf[sz];


void onEffectsReceived(PresetNumber number, AxePreset preset) {
    debug("\n * function onEffectsReceived started on axeSystemWorker.h");

    if (effectCycle) {
        effectCycle = false;
        debug("\n -> effectcycle is true and now set to: false");

        for (int effectindex = 0; effectindex < preset.getEffectCount(); effectindex++) {
            AxeEffect effect = preset.getEffectAt(effectindex);
            if (effectindex < 21) {
                effect_ids[effectindex] = effect.getEffectId();
                effect_bypass_states[effectindex] = effect.isBypassed();
                // Check for wah and looper effect IDs
                if (effect.getEffectId() == 94)
                {debug("\n"); debug(" YES tag is wah"); wahActive = true; continue;} 
                else if (effect.getEffectId() == 166)
                {debug("\n"); debug(" YES tag is looper"); looperActive = true; continue;} 
                effect.copyEffectTag(tag, tagSz);
            }

            char tag[10];
            effect.copyEffectTag(tag, sizeof(tag));

            char engaged = effect.isBypassed() ? ' ' : 'X';
            char buf[100];
            snprintf(buf, sizeof(buf), "\n%s(ch:%c) [%c]", tag, effect.getChannelChar(), engaged);
            debug(buf);
            snprintf(buf, sizeof(buf), "\n Effect: %s | effectId = %d | Channel: %c", tag, effect.getEffectId(), effect.getChannelChar());
            debug(buf);



            if (reset_effectbypass_state) {
                snprintf(buf, sizeof(buf), "\n Reset Effect bypassed value?: %d", effect_bypass_states[effectindex]); debug(buf);
                snprintf(buf, sizeof(buf), "\n Original Effect_bypass value?: %d", effect_variable_bypass[effectindex]);debug(buf);

                if (effect.isBypassed() != effect_variable_bypass[effectindex]) {
                    effect.toggle();
                    snprintf(buf, sizeof(buf), "\n Reset Effect by toggling and is now set to: %d", effect.isBypassed());
                    effect_bypass_states[effectindex] = effect.isBypassed();
                    debug(buf);
                }
                debug("\n");
            }
            
             if (effectindex < 16) {
                effect_variables[effectindex] = effect.getEffectId();
            }
            if (effectindex < 11) {
                effect_variable_bypass[effectindex] = effect.isBypassed();
            }

    
/*=======================================================================================================================================*/
//  SHOW EFFECTS PER SCENE IN SCENE TFT SCREEN 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


 
if (strcmp(page, "scene") == 0) // Only if page is scene, then get the effects to print on screen.
            {
                //int effect_id = effect_ids[effectindex]; // Effect-ID uit de array halen
                switch (effectindex)
                {
                    case 0: CS1L; break;
                    case 1: CS2L; break;
                    case 2: CS3L; break;
                    case 3: CS4L; break;
                    case 4: CS5L; break;
                    case 5: CS6L; break;
                    case 6: CS7L; break;
                    case 7: CS8L; break;
                    case 8: CS9L; break;
                    case 9: CS10L; break;
                }


                if (effectindex == 4 || effectindex == 9) 
                {
                    if (effect_bypass_states[effectindex]) {effectOnPageUpDownBypass();} 
                    else {effectOnPageUpDownActive();}
                }
                else
                {
                    if (effect_bypass_states[effectindex]) {effectOnSceneBypass();}
                    else {effectOnSceneActive();}
                }

                effect.printEffectName(tft);

                switch (effectindex)
                {
                    case 0: CS1H; break;
                    case 1: CS2H; break;
                    case 2: CS3H; break;
                    case 3: CS4H; break;
                    case 4: CS5H; break;
                    case 5: CS6H; break;
                    case 6: CS7H; break;
                    case 7: CS8H; break;
                    case 8: CS9H; break;
                    case 9: CS10H; break;
                }

                debug("\n"); debug(" Effect status: it is set to: "); debug(effect.isBypassed());
                debug("\n");
            }

 


/*=======================================================================================================================================*/
//  EFFECTPAGE BUILDUP
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

      if (strcmp(page, "effects") == 0)  // Only if page is effect, then get the effects to print on screen.
      {
          switch (effectindex)
          {
              case 0: CS1L; break;
              case 1: CS2L; break;
              case 2: CS3L; break;
              case 3: CS4L; break;
              case 4: CS5L; break;
              case 5: CS6L; break;
              case 6: CS7L; break;
              case 7: CS8L; break;
              case 8: CS9L; break;
              case 9: CS10L; break;
          }

          //bool effectBypass = effect.isBypassed();

          if (effect_bypass_states[effectindex]) {effectStyle1();}
          else {effectStyle2();}
        
          // Print effect name on screen
          effect.printEffectName(tft);

          // Set the corresponding CS pin high
          switch (effectindex)
          {
              case 0: CS1H; break;
              case 1: CS2H; break;
              case 2: CS3H; break;
              case 3: CS4H; break;
              case 4: CS5H; break;
              case 5: CS6H; break;
              case 6: CS7H; break;
              case 7: CS8H; break;
              case 8: CS9H; break;
              case 9: CS10H; break;
          }
      }
        
      

//==============================================================================================================
//=========================   HERE we go with the ABCD settings on AMP and CAB   ===============================
//==============================================================================================================

      if  (strcmp(page, "AMP_effect") == 0)
     {
        debug("\n"); debug("\n"); debug(" * function AMP_effect started on axeSystemWorker.h");

        switch (effectindex)
        {
          case 0:
        //== if its AMP1
            if (effect.getEffectId() == 58)
            {AMP1(effect);}

        //== if its AMP2
              else if (effect.getEffectId() == 59)
              {AMP2(effect);}            
              break;

          case 1:
        //== if its AMP2
            if (effect.getEffectId() == 59)  
            {AMP2(effect);}
            
        //== If its CAB1
              else if (effect.getEffectId() == 62) 
              {CAB1(effect);}            
              break;


          case 2:
        //== If its CAB1
            if (effect.getEffectId() == 62) 
            {CAB1(effect);}
            
        //== If its CAB2
              else if (effect.getEffectId() == 63) 
              {CAB2(effect);}             
              break;


          case 3:
        //== If its CAB2
            if (effect.getEffectId() == 63)  
            {CAB2(effect);}
            break;
           }
       }

               /*                                  WAH or LOOPER AVAILABLE?
===============================================================================================================
               Setting the parameters for screen 11 and 12:  is Wah or Looper available?
               if looper = true:  here we check if looper is available and print in screen 12 (id = 166)
               if wah = true:     here we check if wah is available and print in screen 11 (id = 94)
===============================================================================================================*/

      // End of index() search
    
    }
        
        if (getScenes != 1) 
          { 
            debug("\n"); debug("\n"); debug(" * function wah_looper is started from onEffectsReceived() on axeSystemWorker.h");
            wah_looper();
            }

  }
}


//       RESET EFFECTS VARIABLES  (set to zero)
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void effectvariable_reset()
{
 effect_ids[0] = 0; effect_ids[1] = 0; effect_ids[2] = 0; effect_ids[3] = 0; effect_ids[4] = 0; effect_ids[5] = 0; effect_ids[6] = 0; effect_ids[7] = 0; effect_ids[8] = 0; effect_ids[9] = 0; 
 effect_ids[10]= 0; effect_ids[11]= 0; effect_ids[12]= 0; effect_ids[13]= 0; effect_ids[14]= 0; effect_ids[15]= 0; effect_ids[16]= 0; effect_ids[17]= 0; effect_ids[18]= 0; effect_ids[19] = 0;
 effect_ids[20]= 0; 
 debug("\n"); debug(" effectvariable_reset() is started on axeSystemWorker.h  and restored effect to ZERO");
  
 // setupHOLDSWITCH();
}



/*=======================================================================================================================================

                                      _____  _____  ______  _____ ______ _______ _____ 
                                     |  __ \|  __ \|  ____|/ ____|  ____|__   __/ ____|
                                     | |__) | |__) | |__  | (___ | |__     | | | (___  
                                     |  ___/|  _  /|  __|  \___ \|  __|    | |  \___ \ 
                                     | |    | | \ \| |____ ____) | |____   | |  ____) |
                                     |_|    |_|  \_\______|_____/|______|  |_| |_____/ 
                                                   

/*=======================================================================================================================================*/
//       PRESET VIEW SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void presetBank_settings()
{
  debug("\n");debug("\n");  debug(" * function presetBank_settings started on axeSystemWorker.h");
  
  presetBank = 1;  // setting the number to 1 so it can finnish the job and in the end go to zero (0)
  debug("\n");debug("\n");  debug(" * presetBank is set to: "); debug(presetBank);

  
  CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L;
  tft.fillScreen(presetNumberStyle1_fillscreen);
  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H;


  if (auditionMode == true)
  {
    PresetNumb = CurPreset;
    presetRange();
    }

    if (PresetNumb < 10)
    {PNtxtWidth = 135;}
    else if (PresetNumb < 100)
    {PNtxtWidth = 123;}
    else if (PresetNumb < 1000)
    {PNtxtWidth = 105;}
    else if (PresetNumb >= 1000)
    {PNtxtWidth = 87;}

   CS1L; displayPreset(PresetName0, 0); CS1H;
   CS2L; displayPreset(PresetName1, 1); CS2H;
   CS3L; displayPreset(PresetName2, 2); CS3H;
   CS4L; displayPreset(PresetName3, 3); CS4H;
   CS5L; displayPreset(PresetName4, 4); CS5H;
   CS6L; displayPreset(PresetName5, 5); CS6H;
   CS7L; displayPreset(PresetName6, 6); CS7H;
   CS8L; displayPreset(PresetName7, 7); CS8H;
   CS9L; displayPreset(PresetName8, 8); CS9H;
   CS10L; displayPreset(PresetName9, 9); CS10H;
   
      presetBank = 0;
      debug("\n");debug("\n");  debug(" * presetBank is set to: "); debug(presetBank);
}

/*=======================================================================================================================================*/
//       AUDITIONMODE SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


void Auditionmode_settings()
{
  debug("\n");debug("\n");  debug(" * function Auditionmode_settings() started on axeSystemWorker.h");
  
  PresetNumb = CurPreset;
  CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L;
  preset_auditionMode_notACTIVEbezel();
  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H;
    presetRange();


   CS1L; displayPresetNumber(0); CS1H;
   CS2L; displayPresetNumber(1); CS2H;
   CS3L; displayPresetNumber(2); CS3H;
   CS4L; displayPresetNumber(3); CS4H;
   CS5L; displayPresetNumber(4); CS5H;
   CS6L; displayPresetNumber(5); CS6H;
   CS7L; displayPresetNumber(6); CS7H;
   CS8L; displayPresetNumber(7); CS8H;
   CS9L; displayPresetNumber(8); CS9H;
   CS10L; displayPresetNumber(9); CS10H;


switch(selectedSwitch)
{
   case 0: CS1L; displayPreset(PresetName0, 0); CS1H; break;
   case 1: CS2L; displayPreset(PresetName1, 1); CS2H; break;
   case 2: CS3L; displayPreset(PresetName2, 2); CS3H; break;
   case 3: CS4L; displayPreset(PresetName3, 3); CS4H; break;
   case 4: CS5L; displayPreset(PresetName4, 4); CS5H; break;
   case 5: CS6L; displayPreset(PresetName5, 5); CS6H; break;
   case 6: CS7L; displayPreset(PresetName6, 6); CS7H; break;
   case 7: CS8L; displayPreset(PresetName7, 7); CS8H; break;
   case 8: CS9L; displayPreset(PresetName8, 8); CS9H; break;
   case 9: CS10L; displayPreset(PresetName9, 9); CS10H; break;
}
      presetBank = 0;
      debug("\n");debug("\n");  debug(" * presetBank is set to: "); debug(presetBank);

}

/*=======================================================================================================================================*/
//       PRESET CHANGE
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void onPresetChange(AxePreset preset)
{
  debug("\n"); debug("\n");   debug(" * function onPresetChange started on axeSystemWorker.h");
  
  //const size_t sz = 150;
  //char buf[sz];

  //AxeSystem has notified that all requested information has arrived!
  debug("\n"); debug(" Preset number: "); debug(preset.getPresetNumber());

  //You can print directly to a Print object
  strcpy(active_PresetName, (preset.getPresetName()));
  debug("\n"); debug(" Preset name: "); debug(active_PresetName);

  //================================
  // fill Presets for use in screens
  //================================

  /* setting the active sceneNumber and active_Preset for other functions */
  active_Preset =  (preset.getPresetNumber()); //setting the AxeFX active presetnumber
  sceneNumber   =  (preset.getSceneNumber()); //setting the active scenenumber
  CurPreset = active_Preset;
  debug("\n"); debug(" variable active_sceneNumber = "); debug(sceneNumber);
  debug("\n"); debug(" variable active_Preset = "); debug(active_Preset);
  debug("\n"); debug(" variable CurPreset = "); debug(CurPreset);

  if (auditionMode)
  {
  PresetNumb = CurPreset;   //setting the Current preset like presetnumb
  debug("\n"); debug(" variable PresetNumb on auditionmode = "); debug(PresetNumb);
  Auditionmode_settings();  // build up presetscreens and stay on preset screen
  debug("\n"); debug("\n");   debug(" * function onSceneName started on axeSystemWorker.h");
  }
  else
    {
    PresetNumb = CurPreset; //setting the Current preset like presetnumb
    debug("\n"); debug(" variable PresetNumb = "); debug(PresetNumb);
    sceneHoldswitch();
    }
}

/*=======================================================================================================================================*/
/*Axelman8*/