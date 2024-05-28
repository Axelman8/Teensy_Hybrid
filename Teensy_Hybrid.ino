  /* 


  =======================================================================================================================================
  ======================================================================================================================================= 
   
                                                ██████╗░░█████╗░██████╗░██╗
                                                ██╔══██╗██╔══██╗██╔══██╗██║
                                                ██████╔╝███████║██████╔╝██║
                                                ██╔═══╝░██╔══██║██╔══██╗██║
                                                ██║░░░░░██║░░██║██║░░██║██║
                                                ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝
                                                           परी
                                                           
                                                =============================                                                                               
                                                -->> TEENSY 4.1 VERSION  <<--                                                                          
                                                =============================

                                            Axe-FXIII midi sysex foot controller
  
  
                                          Axelman8 |  - Rotterdam -  | Netherlands
                                                     
  
  =======================================================================================================================================
  !! using AxeFxControl libriary from @tysonIT -> Without this libriary, this project would be just a bunch of useless code.
  !! Started from scratch with help of the shared programming of: @prongs_386 | @tysonIT | @Piing from the Fractal audio forum.
  =======================================================================================================================================
  
  (on SD_ini.h)
  @@@  DEBUGGING the program:  
    -> DEBUG (serial) code OFF = 0  | DEBUG output is very usefull to see the flow of the program code 
    -> Set to DEBUG and flash to Arduino to see program output in the Serial monitor  
    -> The Serial.begin = baudrate...   make sure that the serial monitor has the same baudrate as the uncommented baudrate.
       For best serial and program use,  9600 or 115200 is advized.
    
    NOTE to the reader:   
    -> See changeLog.h for any changes in this version

  =======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/

  /*  USE the libriary  */
  //=======================
  #include <TimeLib.h>
  #include <Arduino.h>
  #include <AxeFxControl.h>
  #include <Wire.h>
  #include <malloc.h>
  #include "MUX74HC4067.h"
  #include <SD.h>
  #include <MTP_Teensy.h>
  #include <DigitalRainAnimation.hpp> 

  // USE the ini_files
  #include "ini_files/Teensy_SD_ini.h"
  #include "ini_files/Teensy_PIN_ini.h"


  // USE the tabs
  #include "Hold_function.h"
  #include "variables.h"
  #include "switchSettings.h"
  #include "screenSetup.h"
  #include "Tuner.h"
  #include "Screenstyle.h"
  #include "exp_Pedal.h"


/*=======================================================================================================================================*/
/*=======================================================================================================================================*/
//    SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void setup() 
{


/*=======================================================================================================================================*/
//    SERIAL DEBUGGER and SERIAL BAUD
/*---------------------------------------------------------------------------------------------------------------------------------------*/

//Set SERIAL baud rate:
  //Serial.begin(115200);
  Serial.begin(115200);
  Serial.flush();



/*=======================================================================================================================================*/
//    MTP disk for SDCARD INITIALIZATION
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  #define CS_SD BUILTIN_SDCARD  // Works on T_3.6 and T_4.1
  SD.begin(CS_SD);
  MTP.begin();
  MTP.addFilesystem(SD, "SD Card");


/*=======================================================================================================================================*/
//    SDCARD INITIALIZATION
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  //#define SPI_SPEED SD_SCK_MHZ(16) // adjust to sd card
  sd.begin(SdioConfig(FIFO_SDIO));

/*=======================================================================================================================================*/
//    CLOCK SETTINGS
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  setSyncProvider(getTeensy3Time);
  
/*=======================================================================================================================================*/
//    MIDI SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  
/* -- MIDI settings  (Also see variables_ini.h) --*/
  MIDI.turnThruOff();

/*=======================================================================================================================================*/
//    REGISTER ALL CALL-BACK's
/*---------------------------------------------------------------------------------------------------------------------------------------*/

/* AxeController settings -- */
  Axe.begin(serial);
  Axe.registerSystemChangeCallback(onSystemChange);  // tab tempo
  Axe.registerPresetChangingCallback(onPresetChanging); // New preset with all scenenames, effects
  Axe.registerPresetChangeCallback(onPresetChange);  // New preset selection:  update info new presetname, active scenename, effects
  Axe.registerSceneNameCallback(onSceneName); // run after onPresetChanging.  get all scenenames
  Axe.registerEffectsReceivedCallback(onEffectsReceived);
  Axe.registerEffectFilterCallback(onEffectFilter);
  Axe.registerTapTempoCallback(onTapTempo);
  Axe.registerTunerStatusCallback(onTunerStatus);
  Axe.registerTunerDataCallback(onTunerData);
  Axe.fetchEffects(true);
  Axe.requestPresetDetails();
  Axe.registerStalePresetNameCallback(PresetNameCallback);
  


/*=======================================================================================================================================*/
//    SETUP 16*2 LCD 
/*---------------------------------------------------------------------------------------------------------------------------------------*/

 /* -- 16*2 LCD startup Message: -- */
    lcdStartup_Message();


/*=======================================================================================================================================*/
//    MULTIPLEXER SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  
	mux.signalPin(14, INPUT_PULLUP, DIGITAL);

 
/*=======================================================================================================================================*/
//    SETUP SWITCHES AND SCREENS
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  pinMode(16, INPUT_PULLUP);  
  pinMode(17, INPUT_PULLUP); 


 

// setup all the screens on 1st boot:
   bootscreen_setup();  //screenSetup.h  Showing bootscreen with red white bleu Axe FX III information

/* Startup with the scenepage..this is crusial for the program to work correctly */
   strcpy(page, "scene");  //This will set the active page to scenes (and we want that)


  //Initializing 1st setup:
  ini_screens(); // setting_switches.h building up the screens and initializing for scene information
  auditionMode = false; // Auditionmode is a option on the preset page. Fist time initializing it is allways off.
  tapSwitch = false;  // axe_handler.h setting the TAPtempo info from the AxeFXIII on the screen.
  getScenes = true;   // axe_handler.h first time getting scenes from the AxeFXIII to show on the display's.
  effectCycle = true; // axe_handler.h first time getting effects from the AxeFXIII for Wah and Looper information.
  presetRange(); // setting_switches.h filling the presetnames of active bank (active preset)
}


/*=======================================================================================================================================*/
/*=======================================================================================================================================*/
//    LOOP
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void loop() 
{
  if(MTP_connection == true)
  {MTP.loop();}
  Axe.update();
  timer.update();
  
  
        /*======================================*/
        //   This code is for HOLD button push  
        /*======================================*/
          if (strcmp(page, "HOLD") == 0)
          {digitalClockDisplay(); checkButton();}
        
          if (strcmp(page, "stillHOLD") == 0)
          {digitalClockDisplay(); checkStillHoldButton();}
        /*======================================*/


/*===== LOOKUP the active screen in Setup.h and use setting_switches.h for buttons and screen updates of looper  ===========*/
  
  else if (strcmp(page, "scene") == 0) //scene
  {digitalClockDisplay(); expressionPedals(); scenes_settings();  onlyTuner();}

  else if (strcmp(page, "presets") == 0)
  {digitalClockDisplay(); expressionPedals(); preset_settings();}
  
  else if (strcmp(page, "effects") == 0)
  {digitalClockDisplay(); expressionPedals(); effect_settings();}
  
  else if (strcmp(page, "looper") == 0)
  {digitalClockDisplay(); expressionPedals(); looper_settings();}
  
  else if (strcmp(page, "numbers") == 0)
  {digitalClockDisplay(); expressionPedals(); numbers_settings();}

  else if (strcmp(page, "AMP_effect") == 0)
  {digitalClockDisplay(); expressionPedals(); AMP_effect_settings();}

  else if (strcmp(page, "extras") == 0)
  {digitalClockDisplay(); expressionPedals(); extraOptions();}

  else if (strcmp(page, "matrix") == 0)
  {lcdMatrixMessage(); stopTheMAtrix(); matrix_effect.loop();}
}


/*=======================================================================================================================================*/
/*Axelman8*/