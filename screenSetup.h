#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
#include <AxeFxControl.h>
#include <JPEGDecoder.h>

  // USE the ini_files
#include "ini_files/Teensy_SD_ini.h"
#include "ini_files/Teensy_PIN_ini.h"
#include "ini_files/Teensy_Image.h"

  // USE the tabs
#include "axeSystemWorker.h"
#include "axeEffect.h"
#include "Screenstyle.h"
#include "Presetrange.h"




/*=======================================================================================================================================*/
//      BOOT SCREENS 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

/*=======================================================================================================================================*/

void bootscreen_setup()  // This shows the AXE FX III on the bootup
{
/*=======================================================================================================================================*/
//    SETUP MEMORY INFO
/*---------------------------------------------------------------------------------------------------------------------------------------*/
 
debug("\n");
debug("\n"); debug(" =====  * AXELMAN8 *  =====");
debug("\n"); debug(" PARI Axe FX III controller");
debug("\n"); debug(" ==============================");
debug("\n"); debug(" MEMORY INFORMATION ON START-UP");
debug("\n"); debug(" ==============================");
debug("\n"); debug("\n"); debug(" Max Used RAM STATIC: ");
debug("\n"); debug(" freeram = "); debug(freeram());
 volatile char *p = (char *)malloc(152000);
 *p = 0;
debug("\n"); debug(" freeram = "); debug(freeram());
debug("\n"); debug(" ==============================");

/*=======================================================================================================================================*/

  debug("\n"); debug(" ====================    BOOTUP   ===================");  
  debug("\n"); debug(" * function boot_screensetup started on screenSetup.h");

     
      //setup the 15 LCD screens
      pinMode(CS1, OUTPUT), pinMode(CS2, OUTPUT), pinMode(CS3, OUTPUT),  pinMode(CS4, OUTPUT), pinMode(CS5, OUTPUT),  
      pinMode(CS6, OUTPUT), pinMode(CS7, OUTPUT), pinMode(CS8, OUTPUT),  pinMode(CS9, OUTPUT), pinMode(CS10,OUTPUT),  
      pinMode(CS11,OUTPUT), pinMode(CS12,OUTPUT), pinMode(CS13,OUTPUT),  pinMode(CS14,OUTPUT), pinMode(CS15,OUTPUT);

      tft.begin();

      // setup font for all the screens:
      clearAllScreens();
      CS5L; CS11L; fractal_picture(); CS5H; CS11H;
      CS8L; axelman8_startup_picture(); CS8H;
      delay(1000);
      clearAllScreens();
}


/*=======================================================================================================================================*/
//      First start initializing screens
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_screens()  //clear all screens after 1st boot
{ 
  debug("\n");  debug("\n");  debug(" * function ini_screens started on screenSetup.h");
  scenepageRebuild();  
  strcpy(page, "scene");
  debug("\n"); debug(" * PAGE is set to: "); debug(page);
  CS11L; Screen_11; CS11H;
  CS12L; Screen_12; CS12H;
  CS14L; Screen_14; CS14H;
  CS15L; Screen_15; CS15H;
  CS13L; Screen_13; CS13H;

if (!tunerScreen15_radius)
{strcpy(tuner_type, " PYRAMID");}
else
{strcpy(tuner_type, " RADIUS ");}
}


/*=======================================================================================================================================*/
//      PRESET initializing screens
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_preset()
{
      debug("\n");  debug("\n");  debug(" * function ini_preset started on screenSetup.h");
      presetBank_settings(); // go to the page Axe_handler.h for building the preset screens
      debug("\n");debug(" -> ini_preset has succesfully loaded");
}


/*=======================================================================================================================================*/
//     LOOPER 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_looper()
{

  debug("\n"); debug("\n");   debug(" * function ini_looper started on screenSetup.h");  

  CS1L,  CS2L,  CS3L,  CS4L,  CS5L, CS6L,  CS7L,  CS8L,  CS9L,  CS10L,
  tft.fillScreen(looper_screen_fillscreen);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H, CS6H,  CS7H,  CS8H,  CS9H,  CS10H,

  CS1L;  looperStyle1();  tft.println("UNDO");    CS1H;
  CS3L;  looperStyle1();  tft.println("PLAY");    CS3H;
  CS5L;  looperStyle1();  tft.println("RECORD");  CS5H;
  CS6L;  looperStyle1();  tft.println("ONCE");    CS6H;
  CS8L;  looperStyle1();  tft.println("REVERSE"); CS8H;
  CS10L; looperStyle1();  tft.println("HALFSPD"); CS10H;

}


/*=======================================================================================================================================*/
//     NUMBERS SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_numbers()
{
  debug("\n");debug("\n");  debug(" * function ini_numbers started on screenSetup.h");
  lcd.setCursor(0, 1); lcd.print(" Number =        ");

  CS1L,  CS2L,  CS3L,  CS4L,  CS5L,  CS6L, CS7L,  CS8L,  CS9L,  CS10L;  
  tft.fillScreen(numberSelect_screen_fillscreen);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H,  CS6H, CS7H,  CS8H,  CS9H,  CS10H;  
  
  CS1L;  numbersStyle1();  tft.println("0");  CS1H;
  CS2L;  numbersStyle1();  tft.println("1");  CS2H;
  CS3L;  numbersStyle1();  tft.println("2");  CS3H;
  CS4L;  numbersStyle1();  tft.println("3");  CS4H;
  CS5L;  numbersStyle1();  tft.println("4");  CS5H;
  CS6L;  numbersStyle1();  tft.println("5");  CS6H;
  CS7L;  numbersStyle1();  tft.println("6");  CS7H;
  CS8L;  numbersStyle1();  tft.println("7");  CS8H;
  CS9L;  numbersStyle1();  tft.println("8");  CS9H;
  CS10L; numbersStyle1();  tft.println("9"); CS10H;
}


 void ini_functionPage()
 {
  debug("\n");debug("\n");  debug(" * function ini_functionPage started on screenSetup.h");
  CS1L,  CS2L,  CS3L,  CS4L,  CS5L,  CS6L, CS7L,  CS8L,  CS9L,  CS10L;  
  tft.fillScreen(sceneScreenBuildUp);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H,  CS6H, CS7H,  CS8H,  CS9H,  CS10H; 
    tuner_selectionScreen();
    tapTempo_flash_selection_screen();
    preset_updateScreen();
    matrixScreen();
    MTPconnectionScreen();
    CS8L; axelman8_picture(); CS8H;
    strcpy(page, "extras");  
  delay(30);
  }


/*=======================================================================================================================================*/
//      Build-up EFFECT Screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void effectSettings()
{
  AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effectindex);
  
 if (effectindex ==0)
 {  //this gets rid of the useless effect that crashes the peddleboard :) 
 switch (effectindex) {
    case 1: CS = CS1; thisEffect = effect_ids[0]; break;
    case 2: CS = CS2; thisEffect = effect_ids[1]; break;
    case 3: CS = CS3; thisEffect = effect_ids[2]; break;
    case 4: CS = CS4; thisEffect = effect_ids[3]; break;
    case 5: CS = CS5; thisEffect = effect_ids[4]; break;
    case 6: CS = CS6; thisEffect = effect_ids[5]; break;    
    case 7: CS = CS7; thisEffect = effect_ids[6]; break;
    case 8: CS = CS8; thisEffect = effect_ids[7]; break;
    case 9: CS = CS9; thisEffect = effect_ids[8]; break;
    case 10: CS = CS10; thisEffect = effect_ids[9]; break;
  }           
      digitalWriteFast (CS, LOW);
      thisEffect = (effect->getEffectId());
      if (effect->isBypassed()) 
      {effectStyle1(); effect->printEffectName(tft);}
      else 
      {effectStyle2(); effect->printEffectName(tft);}
      digitalWriteFast (CS, HIGH);   
  }
  
}

/*=======================================================================================================================================*/
//       EFFECT initializing screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_effect()

{

  //================== EFFECTS ===========================
  CS1L,  CS2L,  CS3L,  CS4L,  CS5L,  CS6L, CS7L,  CS8L,  CS9L,  CS10L;  
  tft.fillScreen(TFT_BLACK);
  CS1H,  CS2H,  CS3H,  CS4H,  CS5H,  CS6H, CS7H,  CS8H,  CS9H,  CS10H; 
  
  switch (effectindex)
  {
    case 1:      effectSettings();      break; // = effect1
    case 2:      effectSettings();      break; // = effect2
    case 3:      effectSettings();      break; // = effect3
    case 4:      effectSettings();      break; // = effect4
    case 5:      effectSettings();      break; // = effect5
    case 6:      effectSettings();      break; // = effect6
    case 7:      effectSettings();      break; // = effect7
    case 8:      effectSettings();      break; // = effect8
    case 9:      effectSettings();      break; // = effect9
    case 10:     effectSettings();      break; // = effect10
  }
}

/*=========================================================================================================================
       AMP / CAB EFFECT SETTINGS
  ========================================================================================================================*/

void AMP_ABCD()
{
  debug("\n");debug("\n");  debug(" * function AMP ABCD started on screenSetup.h");
  
  CS1L,CS2L,CS4L,CS5L;
  ampabcdStyle_blackBezelLine();
  CS1H,CS2H,CS4H,CS5H;

  CS6L,CS7L,CS8L,CS9L;
  ampabcdStyle3();
  CS6H,CS7H,CS8H,CS9H;

  CS6L;  ampabcdStyle4();  tft.println("A");  CS6H;
  CS7L;  ampabcdStyle4();  tft.println("B");  CS7H;
  CS8L;  ampabcdStyle4();  tft.println("C");  CS8H;
  CS9L;  ampabcdStyle4();  tft.println("D");  CS9H;

}

/*=========================================================================================================================
     ABCD selection updating in screens 
  ========================================================================================================================*/

void channelSwitch()
{
  debug("\n");  debug("\n");  debug(" * function channelSwitch started on screenSetup.h");
  switch (changeCurrentEffect)
  {
    case 17: {CS1L; effectchannelswitchStyle1(); CS1H;          //AMP1
              if (effect19 == 62)
             {CS4L; effectchannelswitchStyle1(); CS4H;}} break; //CAB1
    case 18: {CS2L; effectchannelswitchStyle1(); CS2H;          //AMP2
              if (effect20 == 63)
             {CS5L; effectchannelswitchStyle1(); CS5H;}} break; //CAB2
    case 19: {CS4L; effectchannelswitchStyle1(); CS4H;}  break;
    case 20: {CS5L; effectchannelswitchStyle1(); CS5H;}  break;
  }
  delay(100);
}


/*=======================================================================================================================================*/
/*Axelman8*/