#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/

  // USE the ini_files  
#include "ini_files/Teensy_Numbers_helper.h"
#include "ini_files/Teensy_PIN_ini.h"

  // USE the tabs
#include "axeEffect.h"
#include "Screenstyle.h"
#include "axeSystemWorker.h"
#include "Presetrange.h"
#include "screenSetup.h"
#include "switchSelect.h"
#include "Hold_function.h"
#include "matrix.h"




/*=======================================================================================================================================
                                                 _____  _____ ______ _   _ ______  _____ 
                                                / ____|/ ____|  ____| \ | |  ____|/ ____|
                                               | (___ | |    | |__  |  \| | |__  | (___  
                                                \___ \| |    |  __| | . ` |  __|  \___ \ 
                                                ____) | |____| |____| |\  | |____ ____) |
                                               |_____/ \_____|______|_| \_|______|_____/ 
 =======================================================================================================================================
                                                         SCENES BUTTONS   
 ---------------------------------------------------------------------------------------------------------------------------------------*/

void scenes_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      effectCycle = true;  timeStart = 0;  holdAction = false;
      debug("\n"); debug(" timeStart value reset to  "); debug(timeStart); 
      debug("\n"); debug(" holdAction value reset to  "); debug(holdAction);
      holdAction = false;      
      switch (MPLXCounter) 
      {
        case 0: HOLDSWITCH = SWITCH1; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc1
        case 1: HOLDSWITCH = SWITCH2; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc2
        case 2: HOLDSWITCH = SWITCH3; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc3
        case 3: HOLDSWITCH = SWITCH4; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc4
        case 4: HOLDSWITCH = SWITCH5; timeStart = millis(); holdAction = 2; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; // preset down
        case 5: HOLDSWITCH = SWITCH6; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc5
        case 6: HOLDSWITCH = SWITCH7; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc6
        case 7: HOLDSWITCH = SWITCH8; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc7
        case 8: HOLDSWITCH = SWITCH9; timeStart = millis(); holdAction = 1; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; //sc8
        case 9: HOLDSWITCH = SWITCH10; timeStart = millis(); holdAction = 3; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break; // preset up
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 7; strcpy(HOLDpage, "scene"); strcpy(page, "HOLD"); break;
        case 11: HOLDSWITCH = SWITCH12; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break;
        case 12: HOLDSWITCH = SWITCH13; timeStart = millis(); holdAction = 6; strcpy(HOLDpage, "presets"); strcpy(page, "HOLD"); break;         
        case 13: switch_14;  delay(100);  break; // Switch 14. TAPtempo
        case 14: HOLDSWITCH = SWITCH15; timeStart = millis(); holdAction = 8; strcpy(HOLDpage, "extras"); strcpy(page, "HOLD"); break; 
        case 15: switch_16;  delay(100);  break; // Switch 16. BANKDOWN
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: switch_17;  delay(100); break; // Switch 17. BANKUP
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
      }
    }
  }
}
 

/*=======================================================================================================================================
                                              _____  _____  ______  _____ ______ _______ _____ 
                                             |  __ \|  __ \|  ____|/ ____|  ____|__   __/ ____|
                                             | |__) | |__) | |__  | (___ | |__     | | | (___  
                                             |  ___/|  _  /|  __|  \___ \|  __|    | |  \___ \ 
                                             | |    | | \ \| |____ ____) | |____   | |  ____) |
                                             |_|    |_|  \_\______|_____/|______|  |_| |_____/ 
  =======================================================================================================================================
                                                            PRESET BUTTONS
  ---------------------------------------------------------------------------------------------------------------------------------------*/

void preset_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      effectCycle = true;  timeStart = 0;  holdAction = false;
      debug("\n"); debug(" timeStart value reset to  "); debug(timeStart); 
      debug("\n"); debug(" holdAction value reset to  "); debug(holdAction);
      holdAction = false;      
      switch (MPLXCounter) 
      {
        debug("\n"); debug(" holdAction value = "); debug(holdAction);
        case 0:  selectedSwitch = 0; presetSelection(); delay(200);  break; // Switch 1. preset 1
        case 1:  selectedSwitch = 1; presetSelection(); delay(200);  break; // Switch 2. preset 2
        case 2:  selectedSwitch = 2; presetSelection(); delay(200);  break; // Switch 3. preset 3
        case 3:  selectedSwitch = 3; presetSelection(); delay(200);  break; // Switch 4. preset 4
        case 4:  selectedSwitch = 4; presetSelection(); delay(200);  break; // Switch 5. Preset 5
        case 5:  selectedSwitch = 5; presetSelection(); delay(200);  break; // Switch 6. preset 6
        case 6:  selectedSwitch = 6; presetSelection(); delay(200);  break; // Switch 7. preset 7
        case 7:  selectedSwitch = 7; presetSelection(); delay(200);  break; // Switch 8. preset 8
        case 8:  selectedSwitch = 8; presetSelection(); delay(200);  break; // Switch 9. preset 9
        case 9:  selectedSwitch = 9; presetSelection(); delay(200);  break; // Switch 10.preset 10
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break; 
        case 11: switch_12;  delay(200);  break; // Switch 12. AMP_EFFECTPAGE
        case 12: switch_13;  delay(200);   break;  // Switch 13.         
        case 13: switch_14;  delay(100); break; // Switch 14. TAPtempo
        case 14: comeFromPreset = true; switch_15;  delay(200);  break; // Switch 15. NUMBER SELECT
        case 15: switch_16;  delay(100);  break; // Switch 16. BANKDOWN
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: switch_17;  delay(100); break; // Switch 17. BANKUP
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
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
  =======================================================================================================================================
                                                       EFFECT  BUTTONS
  ---------------------------------------------------------------------------------------------------------------------------------------*/

void effect_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      effectCycle = true;  timeStart = 0;  holdAction = false;
      debug("\n"); debug(" timeStart value reset to  "); debug(timeStart); 
      debug("\n"); debug(" holdAction value reset to  "); debug(holdAction);
      holdAction = false;      
      switch (MPLXCounter) 
      {
        case 0: HOLDSWITCH = SWITCH1; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 1: HOLDSWITCH = SWITCH2; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 2: HOLDSWITCH = SWITCH3; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 3: HOLDSWITCH = SWITCH4; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 4: HOLDSWITCH = SWITCH5; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 5: HOLDSWITCH = SWITCH6; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 6: HOLDSWITCH = SWITCH7; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 7: HOLDSWITCH = SWITCH8; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 8: HOLDSWITCH = SWITCH9; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 9: HOLDSWITCH = SWITCH10; timeStart = millis(); holdAction = 5; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 7; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 11: HOLDSWITCH = SWITCH12; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break; 
        case 12: sceneSwitch_13;  delay(200); break;     // Switch 13.      
        case 13: switch_14;  delay(100); break; // Switch 14. TAPtempo
        case 14: switch_15;  delay(200);  break; // Switch 15. NUMBER SELECT
        case 15: switch_16;  delay(100);  break; // Switch 16. BANKDOWN
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: switch_17;  delay(100); break; // Switch 17. BANKUP
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
      }
    }
  }
}




/*=======================================================================================================================================
                                         __  __ _____      ______ ______ ______ ______ _____ _______ _____ 
                                   /\   |  \/  |  __ \    |  ____|  ____|  ____|  ____/ ____|__   __/ ____|
                                  /  \  | \  / | |__) |   | |__  | |__  | |__  | |__ | |       | | | (___  
                                 / /\ \ | |\/| |  ___/    |  __| |  __| |  __| |  __|| |       | |  \___ \ 
                                / ____ \| |  | | |        | |____| |    | |    | |___| |____   | |  ____) |
                               /_/    \_\_|  |_|_|        |______|_|    |_|    |______\_____|  |_| |_____/ 
 ================================================================================================================================
                                              AMP and CAB switching A-B-C-D   BUTTONS
 ================================================================================================================================*/

void AMP_effect_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      holdAction = false;  
      switch (MPLXCounter) 
      {

      //======= Switch 1.  =AMP 1        
       case 0: {AMP_ABCD(); AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect17); 
                CS1L; selectAMP1(effect); CS1H; delay(400);} break;
      
      
      //======= Switch 2  =AMP 2
       case 1: {AMP_ABCD(); AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect18); 
                CS2L; selectAMP2(effect); CS2H; delay(400);} break;
      
      
      //========= THIS DOES NOTHING
       case 2:   break;     // Switch 3. 
      
      
      //======== Switch 4  =CAB 1/2
       case 3: {AMP_ABCD(); AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19); 
                CS4L; selectCAB1(effect); CS4H; delay(400);} break;
      
      
      //======== Switch 5 =CAB 2
       case 4: {AMP_ABCD(); AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect20); 
                CS5L; selectCAB2(effect); CS5H; delay(400);} break;        
      
      
      //========================================================================================
      //                                   --- CAHNNEL SWITCHING ---
      //========================================================================================
      
      
      //======= Switch 6  CHANNEL A
       case 5: { AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect); 
                 channelSwitchA(effect); channelSwitch();} break;
      
      //======= Switch 7  CHANNEL B
       case 6: { AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect); 
                 channelSwitchB(effect); channelSwitch();} break;
      
      //======= Switch 8  CHANNEL C
       case 7: { AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect); 
                 channelSwitchC(effect); channelSwitch();} break;
      
      //======= Switch 9  CHANNEL D
       case 8: { AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect); 
                 channelSwitchD(effect); channelSwitch();} break; 

            
        case 9:   break;     // Switch 10.       
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 7; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 11: HOLDSWITCH = SWITCH12; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break; 
        case 12: sceneSwitch_13;  delay(200); break;     // Switch 13.
        case 13: switch_14;  delay(100); break; // Switch 14. TAPtempo
        case 14: switch_15;  delay(200);  break; // Switch 15. NUMBER SELECT
        case 15: switch_16;  delay(100);  break; // Switch 16. BANKDOWN
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: switch_17;  delay(100); break; // Switch 17. BANKUP
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
      }
    }
  }
}


/*=======================================================================================================================================
                                                _      ____   ____  _____  ______ _____  
                                               | |    / __ \ / __ \|  __ \|  ____|  __ \ 
                                               | |   | |  | | |  | | |__) | |__  | |__) |
                                               | |   | |  | | |  | |  ___/|  __| |  _  / 
                                               | |___| |__| | |__| | |    | |____| | \ \ 
                                               |______\____/ \____/|_|    |______|_|  \_\
  =======================================================================================================================================
                                                            LOOPER  BUTTONS
 ---------------------------------------------------------------------------------------------------------------------------------------*/

void looper_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      holdAction = false;  
      switch (MPLXCounter) 
      {
        case 0:
          {debug("\n"); debug(" undo");
           Axe.getLooper().undo(); ini_looper();
           CS1L; looperStyle2(); tft.println("UNDO"); CS1H;      delay(200);} break;

        case 2:
          {debug("\n"); debug(" play");
           Axe.getLooper().play(); ini_looper();
           CS3L; looperStyle2(); tft.println("PLAYING"); CS3H;   delay(200);} break;

        case 4: 
          {debug("\n"); debug(" record");
           Axe.getLooper().record(); ini_looper();
           CS5L; looperStyle2(); tft.println("RECORDING"); CS5H; delay(200);} break;

        case 5:
          {debug("\n"); debug(" once");
           Axe.getLooper().once(); ini_looper();
           CS6L; looperStyle2(); tft.println("ONCE"); CS6H;      delay(200);} break;

        case 7:
          {debug("\n"); debug(" reverse");
           Axe.getLooper().reverse(); ini_looper();
           CS8L; looperStyle2(); tft.println("REVERSE"); CS8H;   delay(200);} break;


        case 9:
          {debug("\n"); debug(" halfSpeed");
           Axe.getLooper().halfSpeed(); ini_looper();
           CS10L; looperStyle2(); tft.println("HALFSPD"); CS10H; delay(200);} break;
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 7; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 11: HOLDSWITCH = SWITCH12; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break; 
        case 12: sceneSwitch_13;  delay(200); break;     // Switch 13.
        case 13: switch_14;  delay(100); break; // Switch 14. TAPtempo
        case 14: switch_15;  delay(200);  break; // Switch 15. NUMBER SELECT
        case 15: break; //printAllPresets(); delay(200); break; // Switch 16. Print all presets to the SDcard
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: break;
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
      }
    }
  }
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

void numbers_settings()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      holdAction = false;  
      switch (MPLXCounter) 
      {
        case 0: {numberhelper(); delay(200);} break;
        case 1: {numberhelper(); delay(200);} break;
        case 2: {numberhelper(); delay(200);} break;
        case 3: {numberhelper(); delay(200);} break;                
        case 4: {numberhelper(); delay(200);} break;
        case 5: {numberhelper(); delay(200);} break;
        case 6: {numberhelper(); delay(200);} break;
        case 7: {numberhelper(); delay(200);} break;
        case 8: {numberhelper(); delay(200);} break;
        case 9: {numberhelper(); delay(200);} break;    
        case 10: HOLDSWITCH = SWITCH11; timeStart = millis(); holdAction = 7; strcpy(HOLDpage, "effects"); strcpy(page, "HOLD"); break;
        case 11: HOLDSWITCH = SWITCH12; timeStart = millis(); holdAction = 4; strcpy(HOLDpage, "looper"); strcpy(page, "HOLD"); break; 
        case 12: sceneSwitch_13;  delay(200); break;     // Switch 13.
        case 13: //Switch 14.  TAP tempo  !! Set TAP tempo manual with number buttons    
          {
            debug("\n"); debug(" -> Pressed Switch = "); debug(MPLXCounter);
            switch (Counter)
            {
              case 1: Axe.setTempo(n1); delay(200); Counter = 0; tapTempo = n1; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n1);
                debug("\n"); debug (" Tempo = ");  debug(n1);
              case 2: Axe.setTempo(n2); delay(200); Counter = 0; tapTempo = n2; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n2);
                debug("\n"); debug (" Tempo = ");  debug(n2);
              case 3:
                if (n3 >= 251)
                { n3 = 250;}
                Axe.setTempo(n3); delay(200); Counter = 0; tapTempo = n3; tapTempo_screen(); break;
                lcd.clear(); lcd.setCursor(0, 1); lcd.print("Tempo = "); lcd.print(n3);
                debug("\n"); debug (" Tempo = ");  debug(n3);
            }
            lcd.setCursor(0, 1); lcd.print("Number =        ");
            Axe.fetchEffects(true);
            Axe.refresh();
            Counter = 0;
          }
          delay(200);
          break;
        case 14: switch_15;  delay(200);  break; // Switch 15 Select a preset with the numbers entered
        case 15: switch_16;  delay(100);  break; // Switch 16. BANKDOWN
      }
    }
  }
  	for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
	{
      if(digitalReadFast(switches[SwitchCounter]) == LOW) 
    {
      switch (SwitchCounter) 
      {
        case 16: switch_17;  delay(100); break; // Switch 17. BANKUP
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
      }
    }
  }
}


/*=======================================================================================================================================

 =======================================================================================================================================
                                                         Other functions BUTTONS   
 ---------------------------------------------------------------------------------------------------------------------------------------*/


 void extraOptions()
{
	for (MPLXCounter = 0; MPLXCounter < 16; ++MPLXCounter)
	{
		// Reads from channel and returns HIGH or LOW
		switches[MPLXCounter] = mux.read(MPLXCounter);
    if (switches[MPLXCounter] == LOW) 
    {
      effectCycle = false;  timeStart = 0;  holdAction = false;
      debug("\n"); debug(" timeStart value reset to  "); debug(timeStart); 
      debug("\n"); debug(" holdAction value reset to  "); debug(holdAction);
      holdAction = false;      
      switch (MPLXCounter) 
      {
          case 0:  {tuner_selection();           delay(200);} break; // Switch 1. Change Tuner Type 
          case 1:  {taptempo_AdjustSelection();  delay(200);} break; // Switch 2. Change TAPtempo type
          case 2:  {printAllPresets();           delay(200);} break; // Switch 3. Print all presets to the SDcard
          case 3:  {setupMatrix();               delay(200);} break; // Switch 4. Call the MatriX
          case 4:  {MTPconnection();             delay(200);} break;
          case 5:  {}; break;
          case 6:  {}; break;
          case 7:  {}; break;
          case 8:  {}; break;
          case 9:  {}; break;
          case 10: {}; break;
          case 11: {}; break;
          case 12: sceneSwitch_13; delay(200); break;  // Switch 13.
          case 13: {}; break;
          case 14: {}; break;
          case 15: {}; break;
        }
      }
    }
      for (byte SwitchCounter = 16; SwitchCounter < 18; ++SwitchCounter)
        {
        if(digitalReadFast(switches[SwitchCounter]) == LOW) 
        {
        switch (SwitchCounter) 
        {
        case 16: break; 
        case 17: switch_18;  delay(200); break; // Switch 18. TUNER
        }
    }
  }
}



/*=======================================================================================================================================

                                                                                                                      
            MMMMMMMM               MMMMMMMM                          tttt                              iiii  XXXXXXX       XXXXXXX
            M:::::::M             M:::::::M                       ttt:::t                             i::::i X:::::X       X:::::X
            M::::::::M           M::::::::M                       t:::::t                              iiii  X:::::X       X:::::X
            M:::::::::M         M:::::::::M                       t:::::t                                    X::::::X     X::::::X
            M::::::::::M       M::::::::::M  aaaaaaaaaaaaa  ttttttt:::::ttttttt   rrrrr   rrrrrrrrr  iiiiiii XXX:::::X   X:::::XXX
            M:::::::::::M     M:::::::::::M  a::::::::::::a t:::::::::::::::::t   r::::rrr:::::::::r i:::::i    X:::::X X:::::X   
            M:::::::M::::M   M::::M:::::::M  aaaaaaaaa:::::at:::::::::::::::::t   r:::::::::::::::::r i::::i     X:::::X:::::X    
            M::::::M M::::M M::::M M::::::M           a::::atttttt:::::::tttttt   rr::::::rrrrr::::::ri::::i      X:::::::::X     
            M::::::M  M::::M::::M  M::::::M    aaaaaaa:::::a      t:::::t          r:::::r     r:::::ri::::i      X:::::::::X     
            M::::::M   M:::::::M   M::::::M  aa::::::::::::a      t:::::t          r:::::r     rrrrrrri::::i     X:::::X:::::X    
            M::::::M    M:::::M    M::::::M a::::aaaa::::::a      t:::::t          r:::::r            i::::i    X:::::X X:::::X   
            M::::::M     MMMMM     M::::::Ma::::a    a:::::a      t:::::t    ttttttr:::::r            i::::i XXX:::::X   X:::::XXX
            M::::::M               M::::::Ma::::a    a:::::a      t::::::tttt:::::tr:::::r           i::::::iX::::::X     X::::::X
            M::::::M               M::::::Ma:::::aaaa::::::a      tt::::::::::::::tr:::::r           i::::::iX:::::X       X:::::X
            M::::::M               M::::::M a::::::::::aa:::a       tt:::::::::::ttr:::::r           i::::::iX:::::X       X:::::X
            MMMMMMMM               MMMMMMMM  aaaaaaaaaa  aaaa         ttttttttttt  rrrrrrr           iiiiiiiiXXXXXXX       XXXXXXX
                                                                                                                      


  =======================================================================================================================================
                                                       MATRIX            
 ---------------------------------------------------------------------------------------------------------------------------------------*/

void StartTheMatrix()
{

}


/*=======================================================================================================================================*/
/*Axelman8*/