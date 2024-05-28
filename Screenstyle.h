#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
  // USE the tabs
#include "presetrange.h"

  // USE the ini_files
#include "ini_files/Teensy_Image.h"
#include "ini_files/Teensy_SD_ini.h"



/*---------------------------------------------------------------------------------------------------------------------------------------*/

TFT_eSprite tempoflash = TFT_eSprite(&tft);  // Declare Sprite object "spr" with pointer to "tft" object

/*=========================================================
    Serial monitor text: RAM MEMORY CALCULATION   
  =========================================================*/

extern unsigned long _heap_start;
extern unsigned long _heap_end;
extern char *__brkval;

int freeram() {
  return (char *)&_heap_end - __brkval;
}


void serialprint_memory_info() //Serial monitor text: RAM MEMORY CALCULATION 
{
  debug("\n");debug("\n"); 
  debug("\n");debug(" =======================");
  debug("\n");debug(F(" -->> Free RAM = "));   //F function does the same and is now a built in library, in IDE > 1.0.0
  debug(freeram());
  debug("\n");debug(" =======================");  // print how much RAM is available in bytes.
}



/*==========================================================================================================================
 

       _ _____  ______ _____    ______ _____ _      ______  _____    ____  _    _ _____ _      _____         _    _ _____  
      | |  __ \|  ____/ ____|  |  ____|_   _| |    |  ____|/ ____|  |  _ \| |  | |_   _| |    |  __ \       | |  | |  __ \ 
      | | |__) | |__ | |  __   | |__    | | | |    | |__  | (___    | |_) | |  | | | | | |    | |  | |______| |  | | |__) |
  _   | |  ___/|  __|| | |_ |  |  __|   | | | |    |  __|  \___ \   |  _ <| |  | | | | | |    | |  | |______| |  | |  ___/ 
 | |__| | |    | |___| |__| |  | |     _| |_| |____| |____ ____) |  | |_) | |__| |_| |_| |____| |__| |      | |__| | |     
  \____/|_|    |______\_____|  |_|    |_____|______|______|_____/   |____/ \____/|_____|______|_____/        \____/|_|     
                                                                                                                           


  ===========================================================================================================================*/
  
    void axelman8_screen13_picture()
    {
      tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness
      debug("\n"); debug(" -> JPEG = "); debug("Axelman8");
      drawArrayJpeg(Axelman8, sizeof(Axelman8),35, 30); // Draw a jpeg image stored in memory at x,y
    }
  
  void axelman8_startup_picture()
    {
      tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness
      debug("\n"); debug(" -> JPEG = "); debug("Axelman8");
      drawArrayJpeg(Axelman8, sizeof(Axelman8),35, 10); // Draw a jpeg image stored in memory at x,y
    }

void axelman8_emptyScene_picture()
    {
      tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness
      debug("\n"); debug(" -> JPEG = "); debug("Axelman8");
      drawArrayJpeg(Axelman8, sizeof(Axelman8),35, 0); // Draw a jpeg image stored in memory at x,y
    }


void axelman8_picture()
    {
      tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness
      debug("\n"); debug(" -> JPEG = "); debug("Axelman8");
      drawArrayJpeg(Axelman8, sizeof(Axelman8),35, 10); // Draw a jpeg image stored in memory at x,y
    }

void fractal_picture()
    {
      tft.setSwapBytes(true); // Swap the byte order for pushImage() - corrects endianness
      debug("\n"); debug(" -> JPEG = "); debug("fractal_audio");
      drawArrayJpeg(fractal__audio, sizeof(fractal__audio), 0, 0); // Draw a jpeg image stored in memory at x,y
    }



/*==========================================================================================================================


  _      _____ _____      _____  _____ _____  ______ ______ _   _    ____  _    _ _____ _      _____         _    _ _____  
 | |    / ____|  __ \    / ____|/ ____|  __ \|  ____|  ____| \ | |  |  _ \| |  | |_   _| |    |  __ \       | |  | |  __ \ 
 | |   | |    | |  | |  | (___ | |    | |__) | |__  | |__  |  \| |  | |_) | |  | | | | | |    | |  | |______| |  | | |__) |
 | |   | |    | |  | |   \___ \| |    |  _  /|  __| |  __| | . ` |  |  _ <| |  | | | | | |    | |  | |______| |  | |  ___/ 
 | |___| |____| |__| |   ____) | |____| | \ \| |____| |____| |\  |  | |_) | |__| |_| |_| |____| |__| |      | |__| | |     
 |______\_____|_____/   |_____/ \_____|_|  \_\______|______|_| \_|  |____/ \____/|_____|______|_____/        \____/|_|     
                                                                                                                           
                                                                                                                           
  ===========================================================================================================================*/                                                                                                                           

/*=========================================================
    16*2 LCD text: RAM MEMORY CALCULATION   
  =========================================================*/
  void availablememory()
{
    lcd.setCursor(0, 1); lcd.print("Free RAM: "); lcd.print(freeram()); lcd.print(" ");
}

  time_t getTeensy3Time() 
{ return Teensy3Clock.get(); }



/*=========================================================
    16*2 LCD text: CLOCK SETTINGS   
  =========================================================*/
  
  void digitalClockDisplay()
  {
    // digital clock display of the time
    if (millis() - lastMillis >= 1 * 1 * 1000UL)
    {
  char s[20];
    snprintf(s,sizeof(s),"%02d:%02d:%02d", hour(), minute(), second());
    lastMillis = millis();  //get ready for the next iteration
    lcd.setCursor(0, 0); lcd.print("    ");  lcd.print(s); lcd.print("     ");
    }
  }

/*=========================================================
    16*2 LCD text: Startup Message 
  =========================================================*/

  lcdStartup_Message()
  {
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Music In Control");
  lcd.setCursor(0, 1);
  lcd.print("|- AXE-FX-III -|");
  }



/*=========================================================
    16*2 LCD text: Matrix Message 
  =========================================================*/

    String scrollText = "If You take the red pill - you stay in Wonderland and I show you how deep the rabbit hole goes...............";
    String staticText = "NEO!.. WAKE UP!! ";
    const int lcdWidth = 16;
    const int lcdRows = 2;
    const int scrollDelay = 300;
    const int blinkInterval = 1500;  // Knipperinterval voor de eerste regel

    int scrollPosition = 0;
    unsigned long previousMillis = 0;
    unsigned long previousScrollMillis = 0;
    unsigned long previousBlinkMillis = 0;
    boolean blinkState = false;
    unsigned long currentMillis = 0; // Verplaats de declaratie hier

void lcdMatrixMessage()
{
   // Controleer of het tijd is om de eerste regel te laten knipperen
  unsigned long currentMillis = millis();
  if (currentMillis - previousBlinkMillis >= blinkInterval) 
    {
      previousBlinkMillis = currentMillis;
      blinkState = !blinkState;
      
      // Schakel de cursor in of uit om de eerste regel te laten knipperen
      lcd.setCursor(0, 0);  // Zet de cursor naar de eerste regel
      if (blinkState) 
      {
        lcd.cursor();
        lcd.print(staticText);
      } else 
        {
          lcd.noCursor();
          lcd.print("                  ");  // Wis de eerste regel
        }
    }

    // Controleer of het tijd is om de tekst te scrollen (voor de tweede regel)
    unsigned long currentScrollMillis = millis();
    if (currentScrollMillis - previousScrollMillis >= scrollDelay) 
      {
        previousScrollMillis = currentScrollMillis;
        
        lcd.setCursor(0, 1);
        String displayText = scrollText.substring(scrollPosition, scrollPosition + lcdWidth);
        
        // Toon de substring op de tweede rij van het LCD-scherm
        lcd.print(displayText);
        
        // Verplaats de scrollpositie
        scrollPosition++;
        
        // Als we het einde van de tekst bereiken, ga terug naar het begin
        if (scrollPosition > (scrollText.length() - lcdWidth)) 
          {
            scrollPosition = 0;
            lcd.setCursor(0, 1);
            lcd.print(" ");  // Wis het laatste teken van de tweede regel
          }
      }
}




  void preset_updateScreen()
  {
    CS3L;
      tft.setTextColor(presetNumberStyle2_txt1_auditionMode_color, presetUpDown_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(1, 27);
      tft.println("PresetNames");
      tft.setCursor(5, 60);
      tft.println("Updating");
     CS3H;
  }


  void matrixScreen()
  {
    CS4L;
      tft.setTextColor(presetUpDown_screen_txt2_color, presetUpDown_screen_txt2_BG);
      tft.setTextSize(4); tft.setCursor(10, 48);
      tft.println("MatriX");
    CS4H;
  }


void MTPconnectionScreen()
{
      CS5L;
      tft.setTextColor(presetNumberStyle2_txt1_auditionMode_color, presetUpDown_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(1, 27);
      tft.println("   MTP   ");
      tft.setCursor(5, 60);
      if (MTP_connection)
      {tft.println("  STOP   ");}
      else
      {tft.println("  START  ");}
     CS5H;
}


/*=====================================================================================================================================================

           _   _          __  __ ______    _    _ ______ _      _____  ______ _____    ______ _    _ _   _  _____ _______ _____ ____  _   _  _____ 
          | \ | |   /\   |  \/  |  ____|  | |  | |  ____| |    |  __ \|  ____|  __ \  |  ____| |  | | \ | |/ ____|__   __|_   _/ __ \| \ | |/ ____|
          |  \| |  /  \  | \  / | |__     | |__| | |__  | |    | |__) | |__  | |__) | | |__  | |  | |  \| | |       | |    | || |  | |  \| | (___  
          | . ` | / /\ \ | |\/| |  __|    |  __  |  __| | |    |  ___/|  __| |  _  /  |  __| | |  | | . ` | |       | |    | || |  | | . ` |\___ \ 
          | |\  |/ ____ \| |  | | |____   | |  | | |____| |____| |    | |____| | \ \  | |    | |__| | |\  | |____   | |   _| || |__| | |\  |____) |
          |_| \_/_/    \_\_|  |_|______|  |_|  |_|______|______|_|    |______|_|  \_\ |_|     \____/|_| \_|\_____|  |_|  |_____\____/|_| \_|_____/ 
                                                                                                                                          
                                                                                                             
  ======================================================================================================================================================*/      


  void SceneName_helper(const char *name)
  {
    stringScene = name;
    stringScene.trim();
    row1 = stringScene.indexOf(' ');  //frows location of first ,
    str1 = stringScene.substring(0, row1);   //captures first data String
    row2 = stringScene.indexOf(' ', row1 + 1 ); //frows location of second ,
    str2 = stringScene.substring(row1 + 1, row2 + 1); //captures second data String
    row3 = stringScene.indexOf(' ', row2 + 1 );
    str3 = stringScene.substring(row2 + 1, row3 + 1);
  }
  
  void PresetName_helper()
  {
    stringPreset = active_PresetName;
    stringPreset.trim();
    prow1 = stringPreset.indexOf(' ');  //frows location of first ,
    pre1 = stringPreset.substring(0, prow1);   //captures first data String
    prow2 = stringPreset.indexOf(' ', prow1 + 1 ); //frows location of second ,
    pre2 = stringPreset.substring(prow1 + 1, prow2 + 1); //captures second data String
    prow3 = stringPreset.indexOf(' ', prow2 + 1 );
    pre3 = stringPreset.substring(prow2 + 1, prow3 + 1);
  
    P11 = pre1.length(); P12 = pre2.length(); P13 = pre3.length();
    pre1.toCharArray(PRE11, P11 + 1); pre2.toCharArray(PRE12, P12 + 1); pre3.toCharArray(PRE13, P13 + 1);
  }
  
  void presetNames_buildup()
  {
      if (P11 >= 10)
      {  tft.setCursor(1, 10); }
      else
      { tft.setCursor((80 - ((P11 * 9) - 6)), 10); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle1_txt1_color);
        tft.println(PRE11);
  
      //row 2
      if (P12 >= 10)
      { tft.setCursor(1, 39); }
      else
      { tft.setCursor((80 - ((P12 * 9) - 6)), 39); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle1_txt1_color);
        tft.println(PRE12);
  
      //row 3
      if (P13 >= 10)
      { tft.setCursor(1, 68); }    
      else
      { tft.setCursor((80 - ((P13 * 9) - 6)), 68); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle1_txt1_color);
        tft.println(PRE13);
  } 
  
  void active_presetNames_buildup()
  {
      if (P11 >= 10)
      {  tft.setCursor(1, 10); }
      else
      { tft.setCursor((80 - ((P11 * 9) - 6)), 10); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle2_txt1_color);
        tft.println(PRE11);
  
      //row 2
      if (P12 >= 10)
      { tft.setCursor(1, 39); }
      else
      { tft.setCursor((80 - ((P12 * 9) - 6)), 39); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle2_txt1_color);
        tft.println(PRE12);
  
      //row 3
      if (P13 >= 10)
      { tft.setCursor(1, 68); }    
      else
      { tft.setCursor((80 - ((P13 * 9) - 6)), 68); }
        tft.setTextSize(3);
        tft.setTextColor(presetNameStyle2_txt1_color);
        tft.println(PRE13);
  } 
  
  void preset_UP_DOWN_Names_buildup()
  {   //row 1
      if (P11 >= 10)
      {  tft.setCursor(1, 42); }
      else
      { tft.setCursor((80 - ((P11 * 9) - 6)), 42); }
        tft.setTextSize(3);
        tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BG);
        tft.println(PRE11);
  
      //row 2
      if (P12 >= 10)
      { tft.setCursor(1, 68); }
      else
      { tft.setCursor((80 - ((P12 * 9) - 6)), 68); }
        tft.setTextSize(3);
        tft.setTextColor(presetUpDown_screen_txt2_color,presetUpDown_screen_txt2_BG);
        tft.println(PRE12);
  }



/*================================================================================================================================================

         _____  _____ _____  ______ ______ _   _     _____ _________     ___      ______    _____ ______ _______ _______ _____ _   _  _____  _____ 
        / ____|/ ____|  __ \|  ____|  ____| \ | |   / ____|__   __\ \   / / |    |  ____|  / ____|  ____|__   __|__   __|_   _| \ | |/ ____|/ ____|
       | (___ | |    | |__) | |__  | |__  |  \| |  | (___    | |   \ \_/ /| |    | |__    | (___ | |__     | |     | |    | | |  \| | |  __| (___  
        \___ \| |    |  _  /|  __| |  __| | . ` |   \___ \   | |    \   / | |    |  __|    \___ \|  __|    | |     | |    | | | . ` | | |_ |\___ \ 
        ____) | |____| | \ \| |____| |____| |\  |   ____) |  | |     | |  | |____| |____   ____) | |____   | |     | |   _| |_| |\  | |__| |____) |
       |_____/ \_____|_|  \_\______|______|_| \_|  |_____/   |_|     |_|  |______|______| |_____/|______|  |_|     |_|  |_____|_| \_|\_____|_____/ 
                                                                                                                           
  =================================================================================================================================================*/ 


/*=======================================================================================================================================*/
//      SCREEN TEXT and COLOR styling settings 
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void presetNumberStyle()
  {
      if (presetNumberNames < 10)
          { Cursor = 60;  }
        else if ((presetNumberNames >= 10) && (presetNumberNames < 100))
        { Cursor = 45;  }
          else if ((presetNumberNames >= 100) && (presetNumberNames < 1000))
          { Cursor = 24;  }
            else if (presetNumberNames >= 1000)
            { Cursor = 0;  }
    tft.setTextColor(presetNumberStyle_txt1_color, presetNumberStyle_fillscreen);
    tft.setTextSize(8);  tft.setCursor(Cursor, 60);
  }

  void clearAllScreens()
  {
  CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L, CS11L, CS12L, CS13L, CS14L, CS15L;
  tft.setTextFont(0);
  tft.setTextWrap(false, false);
  tft.fillScreen(TFT_BLACK);  // screen is all black
  tft.setRotation(3);         //screen is rotated to width 160 x  hight 128 (landscape)
  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H, CS11H, CS12H, CS13H, CS14H, CS15H;
  }




/*=======================================================================================================================================*/
//    SCENE STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void scene_ACTIVEbezel()  // for scenes   x, y, w, h,
  {
     tft.drawRoundRect(0, 0, 160, 95, 20, sceneStyle_ACTIVEbezel);  // Draw bezel line
     tft.drawRoundRect(1, 1, 158, 93, 20, sceneStyle_ACTIVEbezel);  // Draw bezel line
     tft.drawRoundRect(2, 2, 156, 91, 20, sceneStyle_ACTIVEbezel);  // Draw bezel line   m
     tft.drawRoundRect(3, 3, 154, 89, 20, sceneStyle_ACTIVEbezel);  // Draw bezel line
  }
  
  void scene_notACTIVEbezel()  // for scenes
  {
     tft.drawRoundRect(0, 0, 160, 95, 20, sceneStyle_notACTIVEbezel);  // Draw bezel line
     tft.drawRoundRect(1, 1, 158, 93, 20, sceneStyle_notACTIVEbezel);  // Draw bezel line
     tft.drawRoundRect(2, 2, 156, 91, 20, sceneStyle_notACTIVEbezel);  // Draw bezel line   
     tft.drawRoundRect(3, 3, 154, 89, 20, sceneStyle_notACTIVEbezel);  // Draw bezel line
  }

  void preset_auditionMode_ACTIVEbezel()  // for preset
  {
     tft.drawRect(0, 0, 160, 128, presetStyle_auditionMode_ACTIVEbezel); // Draw bezel line
     tft.drawRect(1, 1, 158, 126, presetStyle_auditionMode_ACTIVEbezel); // Draw bezel line
     tft.fillRect(0, 95, 160, 33, presetStyle_auditionMode_ACTIVEbezel);  // Draw bezel line
  }

  void preset_auditionMode_notACTIVEbezel()  // for preset
  {
     tft.drawRect(0, 0, 160, 128, sceneStyle_notACTIVEbezel); // Draw bezel line
     tft.drawRect(1, 1, 158, 126, sceneStyle_notACTIVEbezel); // Draw bezel line
     tft.fillRect(0, 95, 160, 33, sceneStyle_notACTIVEbezel);  // Draw bezel line
  }

  void sceneCursor1()
  { tft.setTextSize(4); tft.setCursor(139, 100); }  
  
  void sceneCursor2()
  { tft.setTextSize(4); tft.setCursor(1, 103); }  
  
  void activesceneStyle1() // ACTIVE scene screen buildup 
    {tft.setTextColor(sceneStyle1_txt1_color); sceneCursor2(); sceneCursor1();}

  void sceneScreenBuildUp_ALL()
  { tft.fillScreen(sceneScreenBuildUp);}
  
  void sceneStyle0() // ALL scene screen buildup
  { scene_notACTIVEbezel(); sceneCursor2();}
  
    void sceneStyle1() // scenenumber buildup ALL screens
  { sceneCursor1(); tft.setTextColor(sceneStyle1_txt1_color);} 

  void sceneStyle2()
  { tft.setTextSize(3);tft.setCursor(5, 10);
    tft.setTextColor(sceneStyle2_txt2_color);} 
  
  void sceneStyle3()
  { tft.setTextSize(3); tft.setTextColor(sceneStyle2_txt2_color);}       
   
   void sceneStyle4()
  { tft.setTextSize(3); tft.setCursor(5, 10); 
    tft.setTextColor(sceneStyle2_txt3_color);} 

  void sceneStyle5()
  { tft.setTextSize(3); tft.setTextColor(sceneStyle2_txt3_color);}     
  
  void screen13Style()
  {
    if (auditionMode == true)
    {
    tft.fillScreen(presetNumberStyle_auditionMode_fillscreen); //screen13Style_fillscreen
    preset_auditionMode_ACTIVEbezel();
    tft.setTextColor(screen13Style_txt3_color,presetNumberStyle_auditionMode_fillscreen);
    tft.setTextSize(6); tft.setCursor(Cursor, 0);
//    tft.println("   ");
    tft.setTextSize(6); tft.setCursor(Cursor, 0);
    tft.setTextColor(screen13Style_txt3_color,presetNumberStyle_auditionMode_fillscreen); 
    }
    else
    {
    tft.fillScreen(screen13Style_fillscreen);
    tft.setTextColor(screen13Style_txt1_color,screen13Style_fillscreen);
    tft.setTextSize(6); tft.setCursor(Cursor, 0);
//    tft.println("   ");
    tft.setTextSize(6); tft.setCursor(Cursor, 0);
    tft.setTextColor(screen13Style_txt1_color,screen13Style_fillscreen); 
      }
    }


  void sceneBuildUpBigRectangle() //BIG BEZZLE
    {tft.fillRect(0, 0, 160, 95,  sceneScreenBuildUp);              //BIG BEZZEL
     tft.fillRect(0, 95, 160, 35, sceneScreenBuildUp);              //SMALL ONE
     tft.fillRoundRect(0, 0, 160, 95, 20,  sceneScreenBuildUp);}
  
  void sceneBigRectangle()  //BIG BEZZLE
      {tft.fillRoundRect(0, 0, 160, 95, 20, sceneStyle_RECT_fillscreen);} 


  void sceneSmallRectangle() //for effects in scenescreen
      {tft.fillRoundRect(0, 98, 140, 30, 12, sceneScreenBuildUp);}    //SMALL ONE



  void presetUpDownEffectRebuild()
    {
          // here is the clearing of presetUp / presetDown effect
          CS5L, CS10L;
          tft.fillRect(0, 0, 160, 35, presetUpDown_screen_fillscreen);
          tft.fillRect(0, 35, 160, 62, presetUpDown_screen_fillscreen1);
          tft.fillRect(0, 98, 160, 30, presetUpDown_screen_fillscreen); 
          CS5H, CS10H; 
      }


  void printSceneNumbers()
    {
        CS1L; sceneStyle1(); tft.println("1"); CS1H;
        CS2L; sceneStyle1(); tft.println("2"); CS2H;
        CS3L; sceneStyle1(); tft.println("3"); CS3H;
        CS4L; sceneStyle1(); tft.println("4"); CS4H;
        CS6L; sceneStyle1(); tft.println("5"); CS6H;
        CS7L; sceneStyle1(); tft.println("6"); CS7H;
        CS8L; sceneStyle1(); tft.println("7"); CS8H;
        CS9L; sceneStyle1(); tft.println("8"); CS9H;
    }

  void scenepageRebuild()
  {    
        strcpy(page, "scene");
        CS1L, CS2L, CS3L, CS4L, CS6L, CS7L, CS8L, CS9L;
        sceneBuildUpBigRectangle();
        sceneSmallRectangle();
        CS1H, CS2H, CS3H, CS4H, CS6H, CS7H, CS8H, CS9H;
        printSceneNumbers();
        presetUpDownEffectRebuild();
        delay(10);
      }

    void clearSceneScreens()
    {
    CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L;
    tft.fillScreen(TFT_BLACK);  // screen is all black
    CS1H, CS2H, CS3H, CS4H, CS5L, CS6H, CS7H, CS8H, CS9H, CS10H; 
    }


/*=======================================================================================================================================*/
//    PRESET STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void preset_ACTIVEbezel()  // for preset
  {
     tft.drawRect(0, 0, 160, 128, presetStyle_ACTIVEbezel); // Draw bezel line
     tft.drawRect(1, 1, 158, 126, presetStyle_ACTIVEbezel); // Draw bezel line
     tft.drawRect(0, 95, 160, 128, presetStyle_ACTIVEbezel);  // Draw bezel line 
     tft.fillRect(0, 95, 160, 128, presetStyle_ACTIVEbezel);  // Draw bezel line
  }
  
  void preset_notACTIVEbezel()  // for preset
  {
     tft.drawRect(0, 0, 160, 128, presetStyle_notACTIVEbezel); // Draw bezel line
     tft.drawRect(1, 1, 158, 126, presetStyle_notACTIVEbezel); // Draw bezel line
     tft.drawRect(0, 95, 160, 128, presetStyle_notACTIVEbezel);  // Draw bezel line 
     tft.fillRect(0, 95, 160, 128, presetStyle_notACTIVEbezel);  // Draw bezel line
  }
  
  
  void presetNumberStyle1() 
  { preset_notACTIVEbezel(); tft.setTextSize(3);
    tft.setCursor(PNtxtWidth, 100); tft.setTextColor(presetNumberStyle1_txt1_color, presetNumberStyle1_txt1_BG);}
  
  void presetNameStyle1()  //Not active preset settings
  {  tft.setTextSize(3);  tft.setCursor(3, 10); tft.setTextColor(presetNameStyle1_txt1_color, presetNameStyle1_txt1_BG);}
  
void presetNumberStyle2()
  {
  if (auditionMode == true)
   {preset_auditionMode_ACTIVEbezel(); tft.setTextSize(3);
    tft.setCursor(PNtxtWidth, 100); 
    tft.setTextColor(presetNumberStyle2_txt1_auditionMode_color, presetNumberStyle2_txt1_auditionMode_BG);
    }
   else
  { preset_ACTIVEbezel(); tft.setTextSize(3);
    tft.setCursor(PNtxtWidth, 100); tft.setTextColor(presetNumberStyle2_txt1_color, presetNumberStyle2_txt1_BG);
    }
  }

  
  void presetNameStyle2()
  { tft.setTextSize(3);  tft.setCursor(3, 10); tft.setTextColor(presetNameStyle2_txt1_color, presetNameStyle2_txt1_BG);}


/*=======================================================================================================================================*/
//    AMP ABCD   EFFECT STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void ampabcdStyle_blackBezelLine()
  {
    tft.drawLine(0, 1, 160, 1, TFT_BLACK);
    tft.drawLine(0, 2, 160, 2, TFT_BLACK);
    tft.drawLine(0, 3, 160, 3, TFT_BLACK);
    tft.drawLine(0, 125, 160, 125, TFT_BLACK);
    tft.drawLine(0, 126, 160, 126, TFT_BLACK);
    tft.drawLine(0, 127, 160, 127, TFT_BLACK);
    tft.drawRect(0, 0, 160, 128, TFT_BLACK); // Draw bezel line
  }
  
  void ampabcdStyle_greenBezelLine()
  {
    tft.drawLine(0, 1, 160, 1, TFT_GREEN);
    tft.drawLine(0, 2, 160, 2, TFT_GREEN);
    tft.drawLine(0, 3, 160, 3, TFT_GREEN);
    tft.drawLine(0, 125, 160, 125, TFT_GREEN);
    tft.drawLine(0, 126, 160, 126, TFT_GREEN);
    tft.drawLine(0, 127, 160, 127, TFT_GREEN);
    tft.drawRect(0, 0, 160, 128, TFT_GREEN); // Draw bezel line
  }

  
  void amp_abcd_GREENbezel() //for amp_abcd settings
  {
     tft.drawLine(0, 104, 160, 104, TFT_GREEN);  // draw single line looks nice
     tft.drawRect(0, 0, 160, 128, TFT_GREEN); // Draw bezel line
  }
  
  void amp_abcd_REDbezel()    // for amp_abcd settings
  {
     tft.drawLine(0, 104, 160, 104, TFT_RED);   // draw single line looks nice
     tft.drawRect(0, 0, 160, 128, TFT_RED);     // Draw bezel line 
  }
  
  void ampabcdStyle2()
  {
    tft.setTextColor(TFT_BLACK, TFT_GREEN);
    tft.setTextSize(3);  tft.setCursor(1, 105);
    tft.println(" CHANNEL ");
    amp_abcd_GREENbezel();
  }
  
  void ampabcdStyle3()
  {
    tft.setTextColor(TFT_BLACK, TFT_RED);
    tft.setTextSize(3); tft.setCursor(1, 105);
    tft.println(" CHANNEL ");
    amp_abcd_REDbezel(); 
  }
  
  void ampabcdStyle4()
  {
    tft.setTextColor(TFT_BLUE);
    tft.setTextSize(20); tft.setCursor(64, 25);
  }
  

/*=======================================================================================================================================*/
//    EFFECT STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/


    void effectStyle1() { //BYPASS
      tft.fillScreen(effectStyle1_fillscreen);
      tft.setTextSize(4); tft.setCursor(2, 50);
      tft.setTextColor(effectStyle1_txt1_color, effectStyle1_txt1_BG);
    }
    
    void effectStyle2() { //ACTIVE
      tft.fillScreen(effectStyle2_fillscreen);
      tft.setTextSize(4);  tft.setCursor(2, 50);
      tft.setTextColor(effectStyle2_txt1_color, effectStyle2_txt1_BG);
    }
    
    
// ===============    3 AND 4 ARE SCENES SCREEN: EFFECT IN BOTTOM OF SCREEN ========================
    void effectStyle3() { //BYPASS
      tft.setTextSize(3);  tft.setCursor(6, 102);
      tft.setTextColor(sceneEffectStyle1_txt1_color, effectStyle1_fillscreen);     //RED
      tft.drawRoundRect(0, 98, 135, 30, 12, sceneStyle_notACTIVEeffectBezelLine);  //RED
    }
    
    
    void effectStyle4() { //ACTIVE
      tft.setTextSize(3);  tft.setCursor(6, 102);
      tft.setTextColor(sceneEffectStyle1_txt1_color, effectStyle2_fillscreen); //GREEN
      tft.drawRoundRect(0, 98, 135, 30, 12, sceneStyle_ACTIVEeffectBezelLine);   //GREEN
    }

    void effectOnSceneBypass()
    {
      tft.fillRoundRect(0, 98, 135, 30, 12, effectStyle1_fillscreen); effectStyle3(); //RED
    }
  
    void effectOnSceneActive()
    {
      tft.fillRoundRect(0, 98, 135, 30, 12, effectStyle2_fillscreen); effectStyle4(); //Green
    }

    
// ===============    5 AND 6 PRESET UP/DOWN SCREEN: EFFECT IN BOTTOM OF SCREEN ========================
    void effectStyle5() { //BYPASS
      tft.setTextSize(3);  tft.setCursor(18, 103);
      tft.setTextColor(sceneEffectStyle1_txt1_color, effectStyle1_fillscreen); //RED
    }
    
    
    void effectStyle6() { //ACTIVE
      tft.setTextSize(3);  tft.setCursor(18, 103);
      tft.setTextColor(sceneEffectStyle1_txt1_color, effectStyle2_fillscreen); //GREEN
    }
 

    void effectOnPageUpDownBypass()
    {
      tft.fillRoundRect(12, 98, 135, 30, 12, sceneStyle_notACTIVEeffectBezelLine); effectStyle5(); //RED
    }
  
    void effectOnPageUpDownActive()
    {
      tft.fillRoundRect(12, 98, 135, 30, 12, sceneStyle_ACTIVEeffectBezelLine); effectStyle6();  //Green
    }


/*=======================================================================================================================================*/
//    EFFECT CHANNEL SWITCH STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/

    void effectchannelswitchStyle0()
    {
       tft.setTextSize(6); tft.setCursor(70, 10);
       tft.setTextColor(TFT_CYAN, TFT_BLACK);
      }  
    
    void effectchannelswitchStyle1()
    {
       tft.setTextSize(6); tft.setCursor(70, 10);
       tft.setTextColor(TFT_CYAN, TFT_BLACK);
       tft.println(channel);
      }
    
    void effectSwitchBypass()
    {  
      tft.setCursor(40, 70);
      tft.setTextSize(4);
      tft.setTextColor(TFT_RED, TFT_BLACK);
      }
    
    void effectSwitchActive()
    { 
      tft.setCursor(40, 70);
      tft.setTextSize(4);
      tft.setTextColor(TFT_GREEN, TFT_BLACK);
    }



/*=======================================================================================================================================*/
//    LOOPER STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/
    
    void looperStyle1()
    {
      tft.setTextColor(looper_screen_txt1_color, looper_screen_txt1_BG);
      tft.setTextSize(3); tft.setCursor(30, 50); 
      }  
    void looperStyle2()
    {
      tft.setTextColor(looper_screen_txt2_color, looper_screen_txt2_BG);
      tft.setTextSize(3);  tft.setCursor(30, 50);  
      } 

/*=======================================================================================================================================*/
//    NUMBER STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void numbersStyle1()
  {
    tft.setTextSize(20);  tft.setCursor(65, 40);
    tft.setTextColor(numberSelect_screen_txt1_color, numberSelect_screen_fillscreen);
    }





/*=======================================================================================================================================

      _______ ____  _____   _____  _____ _____  ______ ______ _   _  _____     ____  _    _ _____ _      _____         _    _ _____  
     |__   __/ __ \|  __ \ / ____|/ ____|  __ \|  ____|  ____| \ | |/ ____|   |  _ \| |  | |_   _| |    |  __ \       | |  | |  __ \ 
        | | | |  | | |__) | (___ | |    | |__) | |__  | |__  |  \| | (___     | |_) | |  | | | | | |    | |  | |______| |  | | |__) |
        | | | |  | |  ___/ \___ \| |    |  _  /|  __| |  __| | . ` |\___ \    |  _ <| |  | | | | | |    | |  | |______| |  | |  ___/ 
        | | | |__| | |     ____) | |____| | \ \| |____| |____| |\  |____) |   | |_) | |__| |_| |_| |____| |__| |      | |__| | |     
        |_|  \____/|_|    |_____/ \_____|_|  \_\______|______|_| \_|_____/    |____/ \____/|_____|______|_____/        \____/|_|     


=======================================================================================================================================*/
                                                                                                                               

  void sceneTopscreens()
  {
    auditionMode = false;
    debug("\n"); debug(" * sceneTopscreens started on Screenstyle.h");
    debug("\n"); debug(" * PAGE is set to: "); debug(page);
    strcpy(page, "scene");
    delay(5);    
    }
  
  
  void auditionmodeTopscreens()
  {
    debug("\n"); debug(" * auditionmodeTopscreens started on Screenstyle.h");
    strcpy(page, "presets");
    auditionMode = true;
    getScenes = false;
    debug("\n"); debug(" * PAGE is set to -> ");  debug(page); debug(" <- while in auditionMode");
    delay(5);
  }
  
  void exit_auditionmodeTopscreens()
  {
    debug("\n"); debug(" * exit_auditionmodeTopscreen started on Screenstyle.h");
    auditionMode = false;
    delay(5);
  }



/*=======================================================================================================================================*/
//     BOOTUP PRESET SCREEN BUILT UP         
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void bootUpscreen13()  // screen 13
  { 
      tft.setTextSize(3); tft.setCursor(10, 0);
      tft.println("  PARI  ");
      axelman8_screen13_picture();
  }


/*=======================================================================================================================================*/
//     SHOW WAH TOGGLE BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  
  void NOWAH_screen()
  {
    tft.fillRoundRect(0, 7, 160, 20, 5, NOWAH_screen_fillscreen);
    tft.setTextColor(NOWAH_screen_txt1_color);
    tft.setTextSize(2); tft.setCursor(2, 10);
    tft.println("WAH AVAILABLE");
    }
  
  void YESWAH_screen()
  {  
    tft.fillRoundRect(0, 7, 160, 20, 5, YESWAH_screen_fillscreen);
    tft.setTextColor(YESWAH_screen_txt1_color);
    tft.setTextSize(2); tft.setCursor(2, 10);
    tft.println("WAH AVAILABLE");
    }


/*=======================================================================================================================================*/
//      SHOW LOOPER TOGGLE BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/


  void NOLOOPER_screen()
  {
    tft.fillRoundRect(0, 7, 160, 20, 5, NOLOOPER_screen_fillscreen);
    tft.setTextColor(NOLOOPER_screen_txt1_color);
    tft.setTextSize(2); tft.setCursor(2, 10);
    tft.println("LOOPER ACTIVE");
    }
  
  void YESLOOPER_screen()
  {
    tft.fillRoundRect(0, 7, 160, 20, 5, YESLOOPER_screen_fillscreen);
    tft.setTextColor(YESLOOPER_screen_txt1_color);
    tft.setTextSize(2); tft.setCursor(2, 10);
    tft.println("LOOPER ACTIVE");
    }




/*=======================================================================================================================================


             _____  _____  ______  _____ ______ _______   _    _ _____        __  _____   ______          ___   _ 
            |  __ \|  __ \|  ____|/ ____|  ____|__   __| | |  | |  __ \      / / |  __ \ / __ \ \        / / \ | |
            | |__) | |__) | |__  | (___ | |__     | |    | |  | | |__) |    / /  | |  | | |  | \ \  /\  / /|  \| |
            |  ___/|  _  /|  __|  \___ \|  __|    | |    | |  | |  ___/    / /   | |  | | |  | |\ \/  \/ / | . ` |
            | |    | | \ \| |____ ____) | |____   | |    | |__| | |       / /    | |__| | |__| | \  /\  /  | |\  |
            |_|    |_|  \_\______|_____/|______|  |_|     \____/|_|      /_/     |_____/ \____/   \/  \/   |_| \_|
                                                                                                       

=======================================================================================================================================*/


/*=======================================================================================================================================*/
//    PRESET UP/DOWN STYLE
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  void presetDown_Style()
  {
    tft.fillRect(0, 35, 160, 62, presetUpDown_screen_fillscreen1);
    if (previousPreset < 10)
    { Cursor = 75;  }
    else if ((previousPreset >= 10) && (previousPreset < 100))
    { Cursor = 60;  }
    else if ((previousPreset >= 100) && (previousPreset < 1000))
    { Cursor = 42;  }
    else if (previousPreset >= 1000)
    { Cursor = 30;  } 
      tft.setTextSize(4); tft.setCursor(Cursor, 1);
      tft.setTextColor(presetUpDown_screen_txt1_color); //set the color of previous preset
  }
  
  void presetUp_Style()
  {
    tft.fillRect(0, 35, 160, 62, presetUpDown_screen_fillscreen1);
    if (nextPreset < 10)
    { Cursor = 75;  }
    else if ((nextPreset >= 10) && (nextPreset < 100))
    { Cursor = 60;  }
    else if ((nextPreset >= 100) && (nextPreset < 1000))
    { Cursor = 42;  } 
    else if (nextPreset >= 1000)
    { Cursor = 30;  }
    tft.setTextSize(4); tft.setCursor(Cursor, 1);
    tft.setTextColor(presetUpDown_screen_txt1_color); //set the color of next preset
  }
  
  
  void presetUpDown_Style1()
  { tft.setTextSize(2);  tft.setCursor(2, 2); tft.setTextColor(presetUpDown_screen_txt2_color);} 
  
/*=======================================================================================================================================*/
//    
/*---------------------------------------------------------------------------------------------------------------------------------------*/


  void presetDown_handler()
  {
    if (lastPreset == 1023)
    {
      if ((previousPreset) != 1023)
        {    
      PresetNumb = active_Preset;
      if ((previousPreset % 10) == 9)
      {PresetNumb = (PresetNumb - 10);}
        }
      else
          {
        PresetNumb = 1023;
          }
    }
    else if ((previousPreset) != 511)
        {    
      PresetNumb = active_Preset;
      if ((previousPreset % 10) == 9)
      {PresetNumb = (PresetNumb - 10);}
        }
      else
          {
        PresetNumb = 511;
          }
  }

//================================================

  void presetUp_handler()
  {
      if ((nextPreset) != 0)
        {
         PresetNumb = active_Preset; 
          if ((nextPresetnr % 10) == 0)
          {PresetNumb = (active_Preset + 10);}
        }
      else
      {
        PresetNumb = 0; 
          }
    }

//================================================

  void presetUp_screen()
  {
    if (strcmp(page, "scene") == 0)
    {
      nextPresetnr = (nextPreset % 10);
      presetUp_handler();
      presetRange(); delay(5); 
      preset_Names(); delay(5); 

      
    switch (nextPresetnr)
    {
    case 0:  strcpy(active_PresetName, PresetName0); debug("\n"); debug(" nextPresetName = "); debug(PresetName0); break;
    case 1:  strcpy(active_PresetName, PresetName1); debug("\n"); debug(" nextPresetName = "); debug(PresetName1); break;
    case 2:  strcpy(active_PresetName, PresetName2); debug("\n"); debug(" nextPresetName = "); debug(PresetName2); break;
    case 3:  strcpy(active_PresetName, PresetName3); debug("\n"); debug(" nextPresetName = "); debug(PresetName3); break;
    case 4:  strcpy(active_PresetName, PresetName4); debug("\n"); debug(" nextPresetName = "); debug(PresetName4); break;
    case 5:  strcpy(active_PresetName, PresetName5); debug("\n"); debug(" nextPresetName = "); debug(PresetName5); break;
    case 6:  strcpy(active_PresetName, PresetName6); debug("\n"); debug(" nextPresetName = "); debug(PresetName6); break;
    case 7:  strcpy(active_PresetName, PresetName7); debug("\n"); debug(" nextPresetName = "); debug(PresetName7); break;
    case 8:  strcpy(active_PresetName, PresetName8); debug("\n"); debug(" nextPresetName = "); debug(PresetName8); break;
    case 9:  strcpy(active_PresetName, PresetName9); debug("\n"); debug(" nextPresetName = "); debug(PresetName9); break;
    }
      debug("\n"); debug(" nextPresetnr = "); debug(nextPreset);  
      debug("\n"); debug(" Nextpreset PresetNumb = "); debug(PresetNumb);
        
  
      presetUp_Style(); tft.println(nextPreset);
      presetUpDown_Style1();
      PresetName_helper();
      preset_UP_DOWN_Names_buildup(); 
      PresetNumb = active_Preset;
    }
  }


  void presetDown_screen()
  {
    if (strcmp(page, "scene") == 0)
    {
    previousPresetnr = (previousPreset % 10); 
      presetDown_handler();
      presetRange(); delay(5);
      preset_Names(); delay(5);
          
    switch (previousPresetnr)
    {
    case 0:  strcpy(active_PresetName, PresetName0); debug("\n"); debug(" previousPresetName = "); debug(PresetName0); break;
    case 1:  strcpy(active_PresetName, PresetName1); debug("\n"); debug(" previousPresetName = "); debug(PresetName1); break;
    case 2:  strcpy(active_PresetName, PresetName2); debug("\n"); debug(" previousPresetName = "); debug(PresetName2); break;
    case 3:  strcpy(active_PresetName, PresetName3); debug("\n"); debug(" previousPresetName = "); debug(PresetName3); break;
    case 4:  strcpy(active_PresetName, PresetName4); debug("\n"); debug(" previousPresetName = "); debug(PresetName4); break;
    case 5:  strcpy(active_PresetName, PresetName5); debug("\n"); debug(" previousPresetName = "); debug(PresetName5); break;
    case 6:  strcpy(active_PresetName, PresetName6); debug("\n"); debug(" previousPresetName = "); debug(PresetName6); break;
    case 7:  strcpy(active_PresetName, PresetName7); debug("\n"); debug(" previousPresetName = "); debug(PresetName7); break;
    case 8:  strcpy(active_PresetName, PresetName8); debug("\n"); debug(" previousPresetName = "); debug(PresetName8); break;
    case 9:  strcpy(active_PresetName, PresetName9); debug("\n"); debug(" previousPresetName = "); debug(PresetName9); break;
    }
      debug("\n"); debug(" previousPresetnr = "); debug(previousPreset);
      debug("\n"); debug(" PreviousPreset PresetNumb = "); debug(PresetNumb); 
  
      presetDown_Style(); tft.println(previousPreset);
      presetUpDown_Style1();
      PresetName_helper();
      preset_UP_DOWN_Names_buildup();     
      PresetNumb = active_Preset;
    }
  }


/*=======================================================================================================================================*/
//     PRESET |  ADDITIONAL PAGE'S         
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void presetUpDownscreens()
  {
      CS5L;  sceneScreen_5;   CS5H;
      CS10L; sceneScreen_10;  CS10H;
    }


/*=======================================================================================================================================


                     _____  _____ _____  ______ ______ _   _  _____     ____  _    _ _____ _      _____         _    _ _____  
                    / ____|/ ____|  __ \|  ____|  ____| \ | |/ ____|   |  _ \| |  | |_   _| |    |  __ \       | |  | |  __ \ 
                   | (___ | |    | |__) | |__  | |__  |  \| | (___     | |_) | |  | | | | | |    | |  | |______| |  | | |__) |
                    \___ \| |    |  _  /|  __| |  __| | . ` |\___ \    |  _ <| |  | | | | | |    | |  | |______| |  | |  ___/ 
                    ____) | |____| | \ \| |____| |____| |\  |____) |   | |_) | |__| |_| |_| |____| |__| |      | |__| | |     
                   |_____/ \_____|_|  \_\______|______|_| \_|_____/    |____/ \____/|_____|______|_____/        \____/|_|     
                                                                                                                            
                                                                                                       

=======================================================================================================================================*/



/*=======================================================================================================================================*/
//    EFFECT SCREEN BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/ 
  void effect_screen()
  {
    tft.fillScreen(effect_screen_fillscreen);
    tft.fillRoundRect(0, 7, 160, 20, 5, NOWAH_screen_fillscreen);
    tft.fillRect(0, 35, 160, 63, effect_screen_RECT_fillscreen);
    tft.setTextColor(effect_screen_txt2_color, effect_screen_txt2_BG);
    tft.setTextSize(3); tft.setCursor(35, 40);
    tft.println("EFFECT");
    tft.setTextColor(effect_screen_txt2_color, effect_screen_txt2_BG);
    tft.setTextSize(3); tft.setCursor(40, 70);
    tft.println("STOMP");
      tft.setTextColor(effect_screen_txt1_color, effect_screen_txt1_BG);
      tft.setTextSize(2); tft.setCursor(2, 108);  
      tft.println("   METRONOME "); 
    }

/*=======================================================================================================================================*/
//    AMP/ABCD SCREEN BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  
  void ampABCD_screen()
  {
    tft.fillScreen(ampabcd_screen_black_fillscreen);
    tft.fillRoundRect(0, 7, 160, 20, 5, NOLOOPER_screen_fillscreen);
    tft.fillRect(0, 35, 160, 63, ampABCD_screenR_RECT_fillscreen);
    tft.setTextColor(ampABCD_screen_txt2_color, ampABCD_screen_txt2_BG);
    tft.setTextSize(3); tft.setCursor(20, 40);
    tft.println("AMP/CAB");
    tft.setTextColor(ampABCD_screen_txt2_color, ampABCD_screen_txt2_BG);
    tft.setTextSize(3); tft.setCursor(45, 70);  
    tft.println("ABCD");  
    tft.setTextColor(ampABCD_screen_txt1_color, ampABCD_screen_txt1_BG);
    tft.setTextSize(2); tft.setCursor(2, 108);  
    tft.println("    LOOPER   "); 
    }


/*=======================================================================================================================================*/
//    NUMBER SCREEN BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void numberSelect_screen()
  {
    tft.fillRect(0,35,160,63,number_screen_RECT_fillscreen);
    fractal_picture();
    tft.setTextColor(number_screen_txt3_color, number_screen_txt1_BG);
    tft.setTextSize(3); tft.setCursor(30, 45);
    tft.println("NUMBER");
    tft.setTextSize(3); tft.setCursor(30, 72);
    tft.setTextColor(number_screen_txt3_color, number_screen_txt1_BG);  
    tft.println("SELECT");  
      
      tft.setTextColor(number_screen_txt2_color, number_screen_txt2_BG);
      tft.setTextSize(2); tft.setCursor(2, 108);  
      tft.println("SPECIAL FUNCT"); 
    }
  
  void reset_numberSelect_screen()
  {
    lcd.clear(); lcd.setCursor(0, 0); lcd.print("Selected =      ");
    Counter = 0;
   delay(5);
  }

/*=======================================================================================================================================*/
//     MTP Connection for acces to the SD card from the pc/laptop/mac        
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void MTPconnection()
{
  debug("\n"); debug(" -> MTP_connection value = "); debug(MTP_connection);
  MTP_connection = !MTP_connection ? true : false;
  MTPconnectionScreen();
  }


/*=======================================================================================================================================*/
//     TUNER SCREEN | SCREEN 15 BUILT UP        
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void tuner_startScreens()
  {CS15L; tft.fillScreen(TFT_BLACK); CS15H;}



/*=======================================================================================================================================*/
//     TUNER SCREEN SELECTION BUILD-UP 
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void tuner_selectionScreen()
  {
      CS1L;
      tft.fillRect(0, 35, 160, 128, tuner_screen_fillscreen);    
      tft.setTextColor(tuner_screen_txt2_color, tuner_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(5, 20); tft.println(" TAP FOR");
      tft.setCursor(15, 47); tft.println(" TUNER ");
      tft.setTextColor(tuner_screen_txt2_color, tuner_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(5, 74); 
      tunerScreen15_radius = tunerScreen15_radius ? tft.println(" PYRAMID") : tft.println(" RADIUS ");
      CS1H;
    }

  
  void tuner_RADIUSSelection()
  {
      strcpy(tuner_type, " RADIUS ");
      debug("\n"); debug(" -> Tuner set to Radius on Screenstyle.h");
      CS1L;
      tft.setTextColor(tuner_screen_txt2_color, tuner_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(5, 74); tft.println(" PYRAMID");
      CS1H;
      delay(10);    
  } 
  
  void tuner_pyramidSelection()
  {
      strcpy(tuner_type, " PYRAMID");
      debug("\n"); debug(" -> Tuner set to Pyramid on Screenstyle.h");
      CS1L;
      tft.setTextColor(tuner_screen_txt2_color, tuner_screen_txt2_BG);
      tft.setTextSize(3); tft.setCursor(5, 74); tft.println(" RADIUS ");
      CS1H;
      delay(10); 
  } 


void tuner_selection()
{
    if (tunerScreen15_radius)
    {
     tunerScreen15_radius = false;
       tuner_RADIUSSelection();   
      debug("\n"); debug(" -> Tuner RadiusSelection started on Screenstyle.h");
     delay(10);   
    }
    else
      {
      tunerScreen15_radius = true;
     tuner_pyramidSelection();
     debug("\n"); debug(" -> Tuner PyramidSelection started on Screenstyle.h");
      }

}


/*=======================================================================================================================================
  

          _______       _____     _______ ______ __  __ _____   ____     ____  _    _ _____ _      _____         _    _ _____  
         |__   __|/\   |  __ \   |__   __|  ____|  \/  |  __ \ / __ \   |  _ \| |  | |_   _| |    |  __ \       | |  | |  __ \ 
            | |  /  \  | |__) |     | |  | |__  | \  / | |__) | |  | |  | |_) | |  | | | | | |    | |  | |______| |  | | |__) |
            | | / /\ \ |  ___/      | |  |  __| | |\/| |  ___/| |  | |  |  _ <| |  | | | | | |    | |  | |______| |  | |  ___/ 
            | |/ ____ \| |          | |  | |____| |  | | |    | |__| |  | |_) | |__| |_| |_| |____| |__| |      | |__| | |     
            |_/_/    \_\_|          |_|  |______|_|  |_|_|     \____/   |____/ \____/|_____|______|_____/        \____/|_|     
                                                                                                                       


  ---------------------------------------------------------------------------------------------------------------------------------------*/

  void tapTempoClearScreen()
  {
    tft.fillRect(0, 35, 160, 63, tapTempo_screen_RECT_fillscreen);
    }



  void tapTempo_screen()
  { 
      CS14L;
      Axe.requestTempo();
      tapTempoClearScreen();
      tft.setTextColor(tapTempo_screen_txt1_color, tapTempo_screen_txt1_BG);
      tft.setTextSize(3); tft.setCursor(45, 105);
      tft.println("TEMPO");
      tft.setTextColor(tapTempo_screen_txt2_color, tapTempo_screen_RECT_fillscreen);
      tft.setTextSize(5); tft.setCursor(tempoCursor, 48);
      tft.println(Axe.getTempo());  
      CS14H;
  }


    void tapTempo_selectionScreen()
  {
      CS14L;
      tapTempoClearScreen();
      tft.setTextColor(tapTempo_selectionScreen_txt1_color, tapTempo_selectionScreen_txt1_BG);
      tft.setTextSize(3); tft.setCursor(45, 105);
      tft.println("TEMPO");
      tft.setTextColor(tapTempo_selectionScreen_txt2_color, tapTempo_selectionScreen_txt2_BG);
      tft.setTextSize(5); tft.setCursor(tempoCursor, 48);
      tft.println(Axe.getTempo());
      CS14H;
  }




  void tapTempoClearSprite()
  {
    CS14L;
    tft.fillRect(0, 0, 160, 35, tapTempo_screen_flash_color1);  
    CS14H;
    }  
  
  

  void tapTempo_sprite()
  { 
    tempoflash.setColorDepth(8); // 1 = brightest.   choose 8 for 16 colours (all color variations)
    tempoflash.createSprite(160, 35);
  }
  
  void tapTempo_flash_ON() 
  {  
    if (tempoflash_bar == 1)
    {
      //(x,y,w,h,lenth,radius)
    tempoflash.drawRoundRect(35, 0, 90, 20, 6, tapTempo_screen_flash_color);
    tempoflash.fillRoundRect(37, 2, 86, 16, 6, tapTempo_screen_flash_color);
    CS14L;
    tempoflash.pushSprite(0, 0);
    CS14H;
      }
    else
    {
    tempoflash.drawRoundRect(0, 0, 30, 20, 6, tapTempo_screen_flash_color);
    tempoflash.drawRoundRect(43, 0, 30, 20, 6, tapTempo_screen_flash_color);
    tempoflash.drawRoundRect(86, 0, 30, 20, 6, tapTempo_screen_flash_color);
    tempoflash.drawRoundRect(129, 0, 30, 20, 6, tapTempo_screen_flash_color);
      
      switch (tempo_Counter)
      {
    case 1:
    tempoflash.fillRoundRect(2, 2, 26, 16, 6, tapTempo_screen_flash_color);
    break;
  
    case 2:  
    tempoflash.fillRoundRect(45, 2, 26, 16, 6, tapTempo_screen_flash_color);
    break;
    
    case 3:
    tempoflash.fillRoundRect(88, 2, 26, 16, 6, tapTempo_screen_flash_color);
    break;
    
    case 4:
    tempoflash.fillRoundRect(131, 2, 26, 16, 6, tapTempo_screen_flash_color);  
    break;
      }
    CS14L;
    tempoflash.pushSprite(0, 0);
    CS14H;   
    }
  }
  
  
  void tapTempo_flash_OFF()
  {
    if (tempoflash_bar == 1)
    {  
    tempoflash.drawRoundRect(35, 0, 90, 20, 6, tapTempo_screen_sprite_color);
    tempoflash.fillRoundRect(37, 2, 86, 16, 6, tapTempo_screen_flash_color1);
    CS14L;
    tempoflash.pushSprite(0, 0);
    CS14H;
    }
    else
    {
    tempoflash.fillRoundRect(2, 2, 26, 16, 6, tapTempo_screen_flash_color1);
    tempoflash.fillRoundRect(45, 2, 26, 16, 6, tapTempo_screen_flash_color1);
    tempoflash.fillRoundRect(88, 2, 26, 16, 6, tapTempo_screen_flash_color1);
    tempoflash.fillRoundRect(131, 2, 26, 16, 6, tapTempo_screen_flash_color1);  
    }
    CS14L;
    tempoflash.pushSprite(0, 0);
    CS14H;      
  }

  
  /* ========== IN AUDITIONMODE - CHANGE FLASH IN SCREEN 14 ===============*/
  
  void tapTempo_flash_selection_screen()
  {
      CS2L;
      tft.setTextColor(tapTempo_screen_txt1_color, tapTempo_screen_txt1_BG);
      tft.setTextSize(3); tft.setCursor(5, 20);
      tft.println(" TAP FOR");
      tft.setTextSize(3); tft.setCursor(5, 47);
      tft.println("  OTHER ");
      tft.setTextSize(3); tft.setCursor(5, 74);
      tft.println("  FLASH ");  
      CS2H; 

    }



 
/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/  