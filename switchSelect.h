#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
  
#include <AxeFxControl.h>

  // USE the ini_files
#include "ini_files/Teensy_SD_ini.h"

  // USE the tabs
#include "Screenstyle.h"
#include "axeEffect.h"
#include "axeSystemWorker.h"
#include "Presetrange.h"
#include "screenSetup.h"
#include "Tuner.h"


/*=======================================================================================================================================*/
//   +++++    SCREEN SELECT     +++++     DO NOT EDIT THESE CODES   +++++     
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void scenePage_selection()
{
  Axe.refresh(); 
  if (holdAction == 0)
  {
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);  
  debug("\n"); debug("\n"); debug(" * function scenePage_selection started on switchSelect.h");

  if (auditionMode == true)
  {
    exit_auditionmodeTopscreens();
  }
  debug("\n");debug(" -> auditionmode set to: ");debug(auditionMode);
  currentEffect = 0;
  Counter = 0;
  getScenes = true;
  effectCycle = true;
  debug("\n"); debug(" -> effectcycle set to: ");  debug(effectCycle);
  debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);  
  if (strcmp(page, "effects") == 0)
  {
    if (RESET_EFFECT == true)  // when going to scenepage, reset effects true or false? 
    {
      reset_effectbypass_state = true;
      }
  }
  sceneTopscreens(); 
  scenepageRebuild();
  holdAction = 0;
  void ini_scenes(const SceneNumber number);
  delay(5);
  }
}


/*==================   OR  ========================*/
void presetPage_selection()
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);  
  debug("\n"); debug("\n"); debug(" * function presetPage_selection started on switchSelect.h");

  if (strcmp(page, "presets") == 0)
    {scenePage_selection();}
    else
    {
      strcpy(page, "presets"); 
      debug("\n"); debug(" * PAGE is set to: "); debug(page);   
      getScenes = false;
      effectCycle = true;
      presetRange();
      ini_preset();
    
      debug("\n"); debug (" -> auditionmode set to: ");  debug(auditionMode);
      debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
      debug("\n"); debug(" -> getScenes set to: ");   debug(getScenes); 
    }
}

/*==================   OR  ========================*/
void looperPage_selection() 
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);  
  debug("\n"); debug("\n"); debug(" * function looperPage_selection started on switchSelect.h"); 

  strcpy(page, "looper");
  debug("\n"); debug(" * PAGE is set to: ");debug(page);
  ini_looper();
}


/*==================   OR  ========================*/

void ampabcdPage_selection() 
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter); 
  debug("\n"); debug("\n"); debug(" * function ampabcdPage_selection started on switchSelect.h");

  CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L;
  tft.fillScreen(TFT_BLACK);
  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H;

    getScenes = false;
    effectCycle = true;
    debug("\n"); debug(" -> getScenes set to:  false");
    debug("\n"); debug(" -> effectcycle set to:  true");
    auditionMode = false;
    debug("\n"); debug(" -> auditionmode set to:  false");
    currentEffect = 0;
    debug("\n"); debug(" currenteffect = "); debug(currentEffect);
    Axe.refresh(); 
    strcpy(page, "AMP_effect");
    AMP_ABCD();
}


/*==================   OR  ========================*/
void effectPage_selection() 
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter); 
  debug("\n"); debug("\n"); debug(" * function effectPage_selection started on switchSelect.h");

  if (auditionMode == 0)  // On auditionMode leave topscreens as is....
  {
  strcpy(page, "effects");
  debug("\n"); debug(" * PAGE is set to: ");debug(page);
  }
  reset_effectbypass_state = false;
  auditionMode = false;
  getScenes = false;
  effectCycle = true;
  Axe.refresh();
  ini_effect();
  
  debug("\n"); debug(" -> auditionmode set to: ");debug(auditionMode);
  debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
  debug("\n"); debug(" -> effectcycle set to: ");  debug(effectCycle);
}

/*==================   OR  ========================*/
void taptempoPage_selection() 
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);  
  debug("\n"); debug("\n"); debug(" * function taptempoPage_selection started on switchSelect.h");   

  if (tapSwitch == false) 
  {
    Axe.sendTap();
    tapSwitch = true;
    tapTempo_selectionScreen(); 
  }
  else
  {
    Axe.sendTap();
    tapSwitch = false;
    tapTempoClearSprite();  // cosmetics for tapscreen.
    tapTempo_screen();
  }
}


void taptempo_AdjustSelection()
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);  
  debug("\n"); debug("\n"); debug(" * function taptempo_AdjustSelection started on switchSelect.h");  
  
  if (tempoflash_bar == false)
    {
    tempoflash_bar = true;
    }
      else
      {
      tempoflash_bar = false;
      }
  tempoflash.deleteSprite();
  delay(5);
  tapTempo_flash_selection_screen();  
}



/*==================   OR  ========================*/

void tunerPage_selection()
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter); 
  debug("\n"); debug("\n"); debug(" * function tunerPage_selection started on switchSelect.h");
  debug("\n"); debug(" -> TUNER started");
  tuner_startScreens();
  if (!Axe.isTunerEngaged()) 
    {if (tunerScreen15_radius == true) {buildTuner();} }
  Axe.toggleTuner();
}

/* =======================================================================================================================================*/
//   Build-up SCENE selection Screen  
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void sceneSelection()
{
  //rebuild all scene TFT to default
    debug("\n"); debug("\n"); debug(" * function sceneSelection() started on switchSelect.h");
      
      CS1L, CS2L, CS3L, CS4L,CS6L, CS7L, CS8L, CS9L;
      sceneStyle0();
      CS1H, CS2H, CS3H, CS4H,CS6H, CS7H, CS8H, CS9H;

      printSceneNumbers();
  
      switch (HOLDSWITCH) 
      {
      case SWITCH1: CS = CS1; sceneNumber = 1; break;
      case SWITCH2: CS = CS2; sceneNumber = 2; break;
      case SWITCH3: CS = CS3; sceneNumber = 3; break;
      case SWITCH4: CS = CS4; sceneNumber = 4; break;
      case SWITCH6: CS = CS6; sceneNumber = 5; break;
      case SWITCH7: CS = CS7; sceneNumber = 6; break;
      case SWITCH8: CS = CS8; sceneNumber = 7; break;
      case SWITCH9: CS = CS9; sceneNumber = 8; break;
      }
      
   strcpy(page, "scene");
   effectCycle = true;
   Axe.fetchEffects(true);
   setupHOLDSWITCH();
   Axe.refresh();

 
  Axe.sendSceneChange(sceneNumber);
  debug("\n"); debug(" -> Pressed Switch = "); debug(sceneNumber); debug(" | Buttonpin = "); debug(SWITCH);
  debug("\n"); debug(" -> Screenpin = "); debug(CS);
  debug("\n"); debug(" -> Active sceneNumber = "); debug(sceneNumber);

  digitalWriteFast (CS, LOW);
  activesceneStyle1();
  tft.println(sceneNumber);
  scene_ACTIVEbezel();
  digitalWriteFast (CS, HIGH);
}

/* =======================================================================================================================================*/
//   Build-up PRESET selection Screens  
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void auditionmodeEnd_Selection()
  {
    debug("\n"); debug("\n"); debug(" * function auditionmodeEnd_Selection started on switchSelect.h");
    Axe.refresh();
    exit_auditionmodeTopscreens();    
    scenepageRebuild();
    sceneTopscreens();
    getScenes = true;
    effectCycle = true;
    debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
    debug("\n"); debug(" -> effectcycle set to:"); debug(effectCycle);
    CurPreset = (active_Preset);
    ini_scenes();            
    debug("\n"); debug(" Auditionmode OFF CurPreset = "); debug(CurPreset);            
    debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
  }


void presetSelection()
{
      debug("\n"); debug("\n"); debug(" * function presetSelection started on switchSelect.h");
      if (auditionMode == true)
          {
           if (exitFromNumbers == true)
          {CurPreset = CurPreset;}
           else
           {
          presetRange();  
          CurPreset = (PresetNumb + selectedSwitch);
           }
          if (CurPreset > lastPreset) 
            {
              CurPreset = 0;
              PresetNumb = 0;
            debug("\n"); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
            debug("\n"); debug(" While Auditionmode ON PresetNumb = "); debug(PresetNumb);
            presetRange();
            }
          debug("\n"); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
          debug("\n"); debug(" While Auditionmode ON PresetNumb = "); debug(PresetNumb);  
          effectCycle = true;
          getScenes = true;
        /*====== Here is if you reselect the preset, it will exit auditionMode =======*/
          if (CurPreset == active_Preset)
          {
            auditionmodeEnd_Selection();
            }
            else
            {
            Axe.sendPresetChange(CurPreset);
            debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
            debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);        
            debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
            }
          }

 //NOT AUDITIONMODE           
            else
              {
              debug("\n"); debug(" CurPreset = "); debug(CurPreset);
              CurPreset = (PresetNumb + selectedSwitch);
              debug("\n"); debug(" selectedSwitch = "); debug(selectedSwitch);
              debug("\n"); debug(" CurPreset + selectedSwitch = "); debug(CurPreset);
              
              if (CurPreset > lastPreset)
                {
                CurPreset = selectedSwitch;
                debug("\n"); debug(" PresetSelection CurPreset = "); debug(CurPreset);
                debug("\n"); debug(" PresetSelection PresetNumb = "); debug(PresetNumb);    
                  } 
              debug("\n"); debug(" PresetSelection CurPreset = "); debug(CurPreset);
              debug("\n"); debug(" PresetSelection PresetNumb = "); debug(PresetNumb);             
              getScenes = true;
              effectCycle = true;

        
        /*====== Here is if you reselect the preset, it will exit to scenepage =======*/
          if (CurPreset == active_Preset)
          {
            scenePage_selection();
              holdAction = 1;
            }
            else
            {              
              Axe.sendPresetChange(CurPreset);
              strcpy(page, "scene");
              scenepageRebuild();
              debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
              debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
              debug("\n"); debug(" -> effectcycle set to: ");  debug(effectCycle);
              selectedSwitch = 0;
              sceneTopscreens();
              }
          }
    Axe.requestTempo();
}

/* =======================================================================================================================================*/
//   Build-up EFFECT selection Screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void effectSelection() 
{
    switch (HOLDSWITCH) {
        case SWITCH1: CS = CS1; thisEffect = effect_ids[0]; break;
        case SWITCH2: CS = CS2; thisEffect = effect_ids[1]; break;
        case SWITCH3: CS = CS3; thisEffect = effect_ids[2]; break;
        case SWITCH4: CS = CS4; thisEffect = effect_ids[3]; break;
        case SWITCH5: CS = CS5; thisEffect = effect_ids[4]; break;
        case SWITCH6: CS = CS6; thisEffect = effect_ids[5]; break;
        case SWITCH7: CS = CS7; thisEffect = effect_ids[6]; break;
        case SWITCH8: CS = CS8; thisEffect = effect_ids[7]; break;
        case SWITCH9: CS = CS9; thisEffect = effect_ids[8]; break;
        case SWITCH10: CS = CS10; thisEffect = effect_ids[9]; break;
    }

    debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
    if (thisEffect > 0) {
        AxeEffect *effect = Axe.getCurrentPreset().getEffectById(thisEffect);
        if (effect != nullptr) {
            effect->toggle();
            digitalWriteFast(CS, LOW);
            if (effect->isBypassed()) {
                effectStyle1(); //on Screenstyle.h
                effect->printEffectName(tft);
            } else {
                effectStyle2(); //on Screenstyle.h
                effect->printEffectName(tft);
            }
            digitalWriteFast(CS, HIGH);
        } 
    }
}

/* =======================================================================================================================================*/
//   Build-up EFFECT selection Screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


void scene_effectSelection() {
    switch (HOLDSWITCH) {
        case SWITCH1: CS = CS1; thisEffect = effect_ids[0]; upDown = false; sceneNumber = SWITCH2; break;
        case SWITCH2: CS = CS2; thisEffect = effect_ids[1]; upDown = false; sceneNumber = SWITCH3; break;
        case SWITCH3: CS = CS3; thisEffect = effect_ids[2]; upDown = false; sceneNumber = SWITCH4; break;
        case SWITCH4: CS = CS4; thisEffect = effect_ids[3]; upDown = false; sceneNumber = SWITCH5; break;
        case SWITCH5: CS = CS5; thisEffect = effect_ids[4]; upDown = true;  sceneNumbers = ""; break;
        case SWITCH6: CS = CS6; thisEffect = effect_ids[5]; upDown = false; sceneNumber = SWITCH6; break;
        case SWITCH7: CS = CS7; thisEffect = effect_ids[6]; upDown = false; sceneNumber = SWITCH7; break;
        case SWITCH8: CS = CS8; thisEffect = effect_ids[7]; upDown = false; sceneNumber = SWITCH8; break;
        case SWITCH9: CS = CS9; thisEffect = effect_ids[8]; upDown = false; sceneNumber = SWITCH9; break;
        case SWITCH10: CS = CS10; thisEffect = effect_ids[9]; upDown = true; sceneNumbers = ""; break;
    }

    debug("\n"); debug(" -> Pressed Switch = "); debug(sceneNumber);
    debug("\n"); debug(" -> Pressed Switch button number = "); debug(HOLDSWITCH);
    debug("\n"); debug(" -> Effect = "); debug(thisEffect);

    if (thisEffect != 0) {
        AxeEffect *effect = Axe.getCurrentPreset().getEffectById(thisEffect);

        if (effect != nullptr) {
            debug("\n"); debug(" Effect BEFORE toggle value is: "); debug(effect->isBypassed());
            effect->toggle();
            debug("\n"); debug(" Effect AFTER toggle value is now: "); debug(effect->isBypassed());

            digitalWriteFast(CS, LOW);
            if (effect->isBypassed()) {
                if (upDown != false) { // screen 5 and 10 for preset up/down
                    effectOnPageUpDownBypass();
                    effect->printEffectName(tft);
                } else {
                    effectOnSceneBypass();
                    effect->printEffectName(tft);
                }
            } else {
                if (upDown != false) { // screen 5 and 10 for preset up/down
                    effectOnPageUpDownActive();
                    effect->printEffectName(tft);
                } else {
                    effectOnSceneActive();
                    effect->printEffectName(tft);
                }
            }
            digitalWriteFast(CS, HIGH);
            debug("\n"); debug(" -> END scene_effectSelection() ");
        } 
    }
    thisEffect = 0;
}


/* =======================================================================================================================================*/
//   +++++++     END SCREEN SELECT     +++++++++        
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


void bankDown_selection()
{ 
  if (presetBank != 1)
  {
  if (strcmp(page, "presets") != 0)  // -->>  NOT on presetpage
        { 
          PresetNumb = (PresetNumb - 10);
          debug("\n"); debug(" presetNumb - 10 = "); debug(PresetNumb); 
          if (PresetNumb < 0) 
          {
            PresetNumb = (PresetNumb + correction1);  // 520 or 1020 is first passible number in the next bank, but doesnt exist
            if (PresetNumb > lastPreset) {PresetNumb = (PresetNumb - 10);}  // 511 or 1023 is last passible number}
            } 
          CurPreset = PresetNumb;
          debug("\n"); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          getScenes = true;
          effectCycle = true;
          scenepageRebuild();
          Axe.sendPresetChange(CurPreset);
          
          debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
          debug("\n"); debug(" -> effectcycle set to: ");  debug(effectCycle);
          debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter - 10);  
        }
          else // -->> ON presetpage
        {  
         { 
           PresetNumb = (PresetNumb - 10);
          debug("\n"); debug(" presetNumb - 10 = "); debug(PresetNumb); 
          if (PresetNumb < 0) 
          {
          PresetNumb = (PresetNumb + correction1);  // 1029 is first passible number in the next bank, but doesnt exist
          if (PresetNumb > lastPreset) {PresetNumb = (PresetNumb - 10);}  // 511 or 1023 is last passible number}
           } 
           if (auditionMode == true)
          {
          CurPreset = PresetNumb;          
          debug("\n"); debug(" auditionmode preset bankDown CurPreset = "); debug(CurPreset);   
          }
          else
            {
          CurPreset = PresetNumb;
          debug("\n"); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          debug("\n"); debug(" Switch-6");
          presetRange();
            }
          ini_preset();
        }
     }    
   }
    delay(10); 
}  
/*==================   OR  ========================*/   //  +10 

void bankUp_selection()
{
    if (presetBank != 1)
        {        
         if (strcmp(page, "presets") != 0) // NOT on presetpage
          {
            if ((PresetNumb + 10) > lastPreset) 
            {
              PresetNumb = (0 + (CurPreset - PresetNumb));
              } // 511 or 1023 is first passible number in the next bank, but doesnt exist
            else
            {
              PresetNumb = (PresetNumb + 10);
              }      
          CurPreset = PresetNumb;
          debug("\n"); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          getScenes = true;
          effectCycle = true;
          scenepageRebuild();
          Axe.sendPresetChange(CurPreset);
          
          debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
          debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
          debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter + 10);
          }
          else  // ON presetpage
          {
            PresetNumb = (PresetNumb + 10);  
          if (PresetNumb >= (correction1)) 
          {
            PresetNumb = (0 + (PresetNumb - correction1)); // 511 or 1023 is first passible number in the next bank, but doesnt exist
            } 
            else if (PresetNumb > lastPreset) 
          {
            PresetNumb = (0 + (PresetNumb - correction2)); // 511 or 1023 is first passible number in the next bank, but doesnt exist
            }            
          if (auditionMode == true)
          {
          CurPreset = PresetNumb;
          debug("\n"); debug(" preset bankUp CurPreset = "); debug(CurPreset);  
            }
          else
          {
          CurPreset = PresetNumb;
          debug("\n"); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          debug("\n"); debug(" Switch-12 ");
          presetRange();
            }
          ini_preset();

          }
    }
          delay(10); 
}

/*==================   OR  ========================*/   //  -1
void presetDown_selection()
{
          getScenes = true;
          debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
          debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter + 1);
          scenepageRebuild();
          if ((CurPreset-1) < 0)
          {Axe.sendPresetChange(lastPreset);}
          else 
          {Axe.sendPresetDecrement();}
}

/*==================   OR  ========================*/   //  +1
void presetUp_selection()
{
          getScenes = true;
          debug("\n"); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
          debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter + 1);
          scenepageRebuild();
          if ((CurPreset+1) > lastPreset)
          {Axe.sendPresetChange(0);}
          else 
          {Axe.sendPresetIncrement();}  
}


void auditionmodePage_selection()          
        {
          clearSceneScreens();
          effectCycle = true;          
          auditionmodeTopscreens();
          debug("\n");  debug("\n");  debug(" * function Auditionmode_settings()started from switchSelect.h");
          presetBank_settings();      
          debug("\n");debug(" -> Auditionmode_settings() has succesfully loaded");     
        }



/*=======================================================================================================================================
                                            _   _ _    _ __  __ ____  ______ _____   _____ 
                                           | \ | | |  | |  \/  |  _ \|  ____|  __ \ / ____|
                                           |  \| | |  | | \  / | |_) | |__  | |__) | (___  
                                           | . ` | |  | | |\/| |  _ <|  __| |  _  / \___ \ 
                                           | |\  | |__| | |  | | |_) | |____| | \ \ ____) |
                                           |_| \_|\____/|_|  |_|____/|______|_|  \_\_____/ 
  =======================================================================================================================================
                                                      NUMBERS  BUTTONS           
 ---------------------------------------------------------------------------------------------------------------------------------------*/

 void selectNumbers()
 {
            debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
                   
            switch (Counter)
              {
              case 0: delay(200); 
              case 1: getScenes = true; effectCycle = true; CurPreset = n1; delay(200);  
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n1);
                debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
                debug("\n"); debug (" Selected number = "); debug(n1); break;
              case 2: getScenes = true; effectCycle = true; CurPreset = n2;delay(200); 
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n2);
                debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
                debug("\n"); debug (" Selected number = "); debug(n2); break;
              case 3: getScenes = true; effectCycle = true; CurPreset = n3;delay(200);  
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n3);
                debug("\n"); debug(" -> effectcycle set to: "); debug(effectCycle);
                debug("\n"); debug (" Selected number = "); debug(n3); break;
/* in case */  case 4: 
                if (n4 >= 1024)
                {lcd.clear(); lcd.setCursor(0, 0); lcd.print("SUM= "); lcd.print(n4); lcd.print(" - 1024");
                n4 = n4 - 1024;}
                getScenes = true; effectCycle = true; CurPreset = n4; delay(200); 
                lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n4);
                debug("\n"); debug(" -> effectcycle set to:  true");
                debug("\n"); debug (" Selected number = ");  debug(n4);
/* in case*/   case 5: 
                if (n4 >= 1024)
                {lcd.clear(); lcd.setCursor(0, 0); lcd.print("SUM= "); lcd.print(n4); lcd.print(" - 1024");
                n4 = n4 - 1024;}
                getScenes = true; effectCycle = true;  CurPreset = n4; delay(200); 
                lcd.setCursor(0, 1); lcd.print("Selected = "); lcd.print(n4);
                debug("\n"); debug(" -> effectcycle set to:  true");
                debug("\n"); debug (" Selected number = ");  debug(n4);
               }

//=================== IF NO NUMBER IS ENTERED, GO BACK TO SCENEPAGE               
               if (Counter == 0)
                {  
                if (auditionMode == true) 
                  {
                  auditionmodeTopscreens();
                  CurPreset = active_Preset;
                  Axe.sendPresetChange(CurPreset); 
                  Auditionmode_settings();
                  }
                  else
                    {
                     sceneSwitch_13;
                    }
                  }
//=================== END IF NO NUMBER IS ENTERED, GO BACK TO SCENEPAGE 
                    
//=================== ON AUDITIONMODE JUMPING TO ANOTHER BANK                    
                    else
                    {
                        if (auditionMode == true) // AUDITIONMODE
                         {
                          auditionSelectPreset = active_Preset - CurPreset;
                          debug("\n"); debug(" auditionSelectPreset value = ");  debug(auditionSelectPreset);                          
                            if ((auditionSelectPreset < 11)  && (auditionSelectPreset >= 0))
                            {
                            auditionmodeTopscreens();
                            exitFromNumbers = true;
                            presetSelection(); //numberswitch_19; //presetSelection();
                            exitFromNumbers = false;
                            }
                                else
                                {
                                auditionmodeTopscreens();
                                getScenes = false;
                                effectCycle = false;
                                presetBank_settings();
                                }
                           }  
//=================== END ON AUDITIONMODE JUMPING TO ANOTHER BANK


//=================== ON PRESETPAGE JUMPING TO ANOTHER BANK                                               
                          else
                          {
                        if (comeFromPreset == true)  
                         {
                          auditionSelectPreset = active_Preset - CurPreset;
                          debug("\n"); debug(" OnPresetSelectPreset value = ");  debug(auditionSelectPreset);                          
                            if ((auditionSelectPreset < 11)  && (auditionSelectPreset >= 0))
                            {
                            exitFromNumbers = true;
                            presetSelection(); //numberswitch_19; //presetSelection();
                            exitFromNumbers = false;
                            }
                                else
                                {
                                strcpy(page, "presets");
                                auditionMode = true;
                                getScenes = false;
                                effectCycle = false;
                                presetBank_settings();
                                }
                             comeFromPreset = false;
                            }                      
                          else
                          {                            
                          Axe.sendPresetChange(CurPreset);     
                          strcpy(page, "scene");scenepageRebuild();
                          }
                        }
//=================== END ON PRESETPAGE JUMPING TO ANOTHER BANK  
                      
                        Axe.refresh();
                        Counter = 0;
                        delay(200);
                        }
                        
          }


/*==================   OR  ========================*/

void numberPage_selection() 
{
  debug("\n"); debug(" -> Pressed Switch = "); debug(HOLDSWITCH); 
  debug("\n");debug("\n");  debug(" * function numberPage_selection started on switchSelect.h");   
    if (strcmp(page, "numbers") == 0)
    {
      selectNumbers();
    }
    else
      {
        strcpy(page, "numbers");
        ini_numbers();
        debug("\n"); debug(" * PAGE is set to: "); debug(page);
        Counter = 0;
      }
  }




/*=======================================================================================================================================*/
/*Axelman8*/