#pragma once
#include <AxeFxControl.h>
#include <Arduino.h>
#include <Timer.h>




/*=======================================================================================================================================


 ██████╗ ██████╗ ███╗   ██╗███████╗██╗ ██████╗        ██╗███╗   ██╗██╗    ███████╗███████╗████████╗████████╗██╗███╗   ██╗ ██████╗ ███████╗
██╔════╝██╔═══██╗████╗  ██║██╔════╝██║██╔════╝        ██║████╗  ██║██║    ██╔════╝██╔════╝╚══██╔══╝╚══██╔══╝██║████╗  ██║██╔════╝ ██╔════╝
██║     ██║   ██║██╔██╗ ██║█████╗  ██║██║  ███╗       ██║██╔██╗ ██║██║    ███████╗█████╗     ██║      ██║   ██║██╔██╗ ██║██║  ███╗███████╗
██║     ██║   ██║██║╚██╗██║██╔══╝  ██║██║   ██║       ██║██║╚██╗██║██║    ╚════██║██╔══╝     ██║      ██║   ██║██║╚██╗██║██║   ██║╚════██║
╚██████╗╚██████╔╝██║ ╚████║██║     ██║╚██████╔╝    ██╗██║██║ ╚████║██║    ███████║███████╗   ██║      ██║   ██║██║ ╚████║╚██████╔╝███████║
 ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝╚═╝     ╚═╝ ╚═════╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝    ╚══════╝╚══════╝   ╚═╝      ╚═╝   ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝

========================================================================================================================================*/

/*

On this page you have controll over your setup.  
If any update will be pushed for the software,  this will not effect your personal settings like:

* Screen definitions
* Screen layout 
* Screen layout coloring per screen


If you want to change anything to your personal settings,  do it in this library tab.
Just edit and save and then flash the program to the arduino

*/

/*=======================================================================================================================================*/
//    SERIAL DEBUGGER and SERIAL BAUD
/*=======================================================================================================================================*/

// 	setting the Serial DEBUGGER | to see the text in the serial what the program is doing
//	OFF  = DEBUG0 
//	ON   = DEBUG 

#define DEBUG


//Using the Serial DEBUGGER  
#ifdef DEBUG == DEBUG
#define debug(x) Serial.print(x)
#else
#define debug(x)
#endif


/*=======================================================================================================================================*/
//  USE MKI or MKII 
/*=======================================================================================================================================*/ 

//Set as MKI  if U are using the MKI
//Set as MKII if U are using the MKII version

#define MK2

//Using the configuration to help with corrections in presetchange selection  
#ifdef MK1 == MK1
#define lastPreset 511
#define correction1 520
#define correction2 510
#else
#define lastPreset 1023
#define correction1 1030
#define correction2 1025
#endif 
 
 
/*=======================================================================================================================================*/
//    USE MTP FOR WINDOWS CONNECTION TO SD-CARD
/*=======================================================================================================================================*/ 

 bool MTP_connection = false;

/*=======================================================================================================================================*/
//    Holdtime function -->> DO NOT REMOVE <-
/*=======================================================================================================================================*/ 

// ADDED 2022 10 02
unsigned long holdTimeResult = 0;
unsigned long timeStart = 0;
unsigned long holdTime = 260;


/*=======================================================================================================================================*/
//    SHOW TUNER ON  SCREEN 15  
/*=======================================================================================================================================*/


//Tuner is RADIUS or PYRAMID
bool tunerScreen15_radius = true; 


/*=======================================================================================================================================*/
//    SHOW FLASH TAP TEMPO ON SCREEN 14  
/*=======================================================================================================================================*/

bool tempoflash_bar = false;  // true  = show   90x30px | single BAR on screen 14
                              // false = show   30x20px | 4 NOTES    on screen 14


/*=======================================================================================================================================*/
//    RESET_EFFECT  = RESET ALL EFFECTS TO DEFAULT WHEN GOING TO SCENE PAGE  
/*=======================================================================================================================================*/

#define RESET_EFFECT true

/* ======================================================================================================================================= 



                           HERE ARE THE SCREEN AND BUTTON NUMBERS.  EACH PAGE HAS THE SAME SETUP
                                    YOU CAN CONFIGURE YOUR PAGE BUILDUP SETTINGS HERE 
                    
                                     |=====|   |=====|   |=====|   |=====|   |=====|  
                                     |  11 |   |  12 |   |  13 |   |  14 |   |  15 |  
                                     |=====|   |=====|   |=====|   |=====|   |=====|   18
                                        O         O         O         O         O       O
                                              
                                     |=====|   |=====|   |=====|   |=====|   |=====|  
                                     |  6  |   |  7  |   |  8  |   |  9  |   |  10 |  
                                     |=====|   |=====|   |=====|   |=====|   |=====|   17
                                        O         O         O         O         O       O
                                              
                                     |=====|   |=====|   |=====|   |=====|   |=====|  
                                     |  1  |   |  2  |   |  3  |   |  4  |   |  5  |   
                                     |=====|   |=====|   |=====|   |=====|   |=====|   16
                                        O         O         O         O         O       O
										
										

/*=======================================================================================================================================*/
//    SWITCH and SCREEN setup
/*=======================================================================================================================================*/

// Screen and switch 5
#define sceneScreen_5 presetDown_screen()
#define sceneswitch_5 presetDown_selection()

// Screen and switch 10
#define sceneScreen_10 presetUp_screen()
#define sceneswitch_10 presetUp_selection()

// Screen and switch 11
#define Screen_11 effect_screen()
#define switch_11 effectPage_selection()

// Screen and switch 12
#define Screen_12 ampABCD_screen() //ampABCD_screen() 
#define switch_12 ampabcdPage_selection() //ampabcdPage_selection() 

// DO NOT CHANGE SCREEN 13 value!
#define Screen_13 bootUpscreen13()
#define switch_13 presetPage_selection()
#define sceneSwitch_13 scenePage_selection()
#define switch_13A auditionmodePage_selection()

// Screen and switch 14
#define Screen_14 tapTempo_screen()
#define switch_14 taptempoPage_selection()

// Screen and switch 15
#define Screen_15 numberSelect_screen()
#define switch_15 numberPage_selection()

// SWITCHES ONLY
#define switch_16 bankDown_selection()
#define switch_17 bankUp_selection()
#define switch_18 tunerPage_selection()
#define numberswitch_18 reset_numberSelect_screen()
//#define switch_19 ini_functionPage()

/*=======================================================================================================================================*/
// Define SCREEN build-up Variables
/*=======================================================================================================================================*/
/* 
 *  These colors are free to configure... just give it a color and flash it to the ARDUINO to see the result!
 *  NOTE:  Only some screens are MULTI configurable.
 *  
 *
 *  Create your own colors with this hack:  http://www.barth-dev.de/online/rgb565-color-picker/
 *  NOTE: These colors must exist in TFT_eSPI.h
 *
 *##################   COLORS   ###########################
 *                     
 * #define TFT_BLACK       0x0000   
 * #define TFT_NAVY        0x000F     
 * #define TFT_DARKGREEN   0x03E0      
 * #define TFT_DARKCYAN    0x03EF      
 * #define TFT_MAROON      0x7800     
 * #define TFT_PURPLE      0xD01F  
 * #define TFT_OLIVE       0x7BE0      
 * #define TFT_LIGHTGREY   0xD69A      
 * #define TFT_DARKGREY    0x7BEF  
 * #define TFT_BLUE        0x021E 
 * #define TFT_SUPERBLUE   0x2B1F
 * #define TFT_GREEN       0x0FEA 
 * #define TFT_MEGAGREEN   0x1FE3 
 * #define TFT_OCEANGREEN  0x1F51 
 * #define TFT_CYAN        0x07FF  
 * #define TFT_RED         0xF8A8
 * #define TFT_SUPERRED	   0xE000 
 * #define TFT_ORGRED      0xF800 
 * #define TFT_MAGENTA     0xF83F 
 * #define TFT_YELLOW      0xFFE9 
 * #define TFT_WHITE       0xFFFF   
 * #define TFT_ORANGE      0xFC84 
 * #define TFT_GREENYELLOW 0xB7E0  
 * #define TFT_PINK        0xD9BE    
 * #define TFT_BROWN       0x9A60  
 * #define TFT_GOLD        0xFEA0  
 * #define TFT_SILVER      0xC618    
 * #define TFT_SKYBLUE     0x073F 
 * #define TFT_VIOLET      0x915C 
 *  
 *
 *  
 */
/*=======================================================================================================================================*/

/* fillscreen       = SCREEN background color
 * txt1,2,3color    = TEXT color 
 * txt1,2,3BG  = TEXT background color: this is taken from the fillscreen background color!
*/

/*=======================================================================================================================================*/

// ALL SCENES screens Background color
#define sceneStyle_Circle TFT_YELLOW
#define sceneStyle_RECT_fillscreen TFT_BLACK     //BIG RECT IN SCENE SCREENS,  YOU CAN SET IT WITH ANY COLOR TO TRY

#define sceneScreenBuildUp TFT_BLACK


// Choose color of scene active bezel and coloring
#define sceneStyle_ACTIVEbezel TFT_MEGAGREEN //TFT_GREEN
#define activesceneStyle1_txt1_color TFT_LIGHTGREY
#define activesceneStyle1_txt1_BG sceneStyle_ACTIVEbezel


// Choose color of NOT active scene bezelLINE and coloring
// #define sceneStyle0_fillscreen
#define sceneStyle_notACTIVEbezelLine sceneStyle0_fillscreen //THIS WILL GIVE THE EFFECT IN THE CORNERS OF THE SCENE SCREEN
#define sceneStyle_ACTIVEeffectBezelLine TFT_MEGAGREEN //TFT_GREEN
#define sceneStyle_notACTIVEeffectBezelLine TFT_SUPERRED //TFT_RED

// Choose color of NOT active scene bezel and coloring
#define sceneStyle_notACTIVEbezel sceneStyle_RECT_fillscreen

// ALL SCENE screen color  txt1 = number in corner
#define sceneStyle1_txt1_color TFT_SUPERBLUE //TFT_MAGENTA  //0xF83F 
#define sceneStyle1_txt1_BG sceneStyle_notACTIVEbezel
#define sceneStyle1_txt2_BG sceneStyle_notACTIVEbezel

// ALL SCENE screen color txt1 = number in corner and txt2 = scenename text
#define sceneStyle_RECT_fillscreen TFT_BLACK     //BIG RECT IN SCENE SCREENS,  YOU CAN SET IT WITH ANY COLOR TO TRY
#define sceneStyle2_txt1_BG sceneStyle0_fillscreen
#define sceneStyle2_txt2_color TFT_SKYBLUE // TFT_YELLOW
#define sceneStyle2_txt2_BG sceneStyle0_fillscreen
#define sceneStyle2_txt3_color TFT_SKYBLUE //TFT_SUPERBLUE
#define sceneStyle2_txt3_BG sceneStyle0_fillscreen

// ALL SCENE text color or the effects on the bottom 
#define sceneEffectStyle1_txt1_color TFT_BLACK


/*=======================================================================================================================================*/


// STARTUP screen 13 for preset info  NO(txt1) INFO(txt2)
 #define presetNumberStyle_fillscreen TFT_MAGENTA
 #define presetNumberStyle_auditionMode_fillscreen TFT_BLACK
 #define presetNumberStyle_txt1_color TFT_BLACK //TFT_SKYBLUE



// Not active PRESET number text color settings  //All preset screens number text 
#define presetStyle_notACTIVEbezel TFT_BLACK
#define presetNumberStyle1_fillscreen TFT_BLACK
#define presetNumberStyle1_txt1_color TFT_YELLOW
#define presetNumberStyle1_txt1_BG presetNumberStyle1_fillscreen

// PRESET name text color settings              //All preset screens Presetname text 
#define presetNameStyle1_txt1_fillscreen TFT_BLACK
#define presetNameStyle1_txt1_color TFT_SKYBLUE 
#define presetNameStyle1_txt1_BG presetNameStyle1_txt1_fillscreen

// Active preset settings text color settings
#define presetStyle_ACTIVEbezel TFT_MEGAGREEN //TFT_GREEN
#define presetNumberStyle2_fillscreen TFT_BLACK
#define presetNumberStyle2_txt1_color TFT_BLACK
#define presetNumberStyle2_txt1_BG presetStyle_ACTIVEbezel

// Active preset settings
#define presetNameStyle2_txt1_color TFT_SKYBLUE //TFT_CYAN
#define presetNameStyle2_txt1_BG presetNumberStyle2_fillscreen

// AUDITIONMODE Active preset settings text color settings
#define presetStyle_auditionMode_ACTIVEbezel TFT_SUPERRED //TFT_RED
#define presetNumberStyle2_auditionMode_fillscreen TFT_BLACK
#define presetNumberStyle2_txt1_auditionMode_color TFT_YELLOW
#define presetNumberStyle2_txt1_auditionMode_BG presetStyle_auditionMode_ACTIVEbezel

// PRESET DOWN - UP screen (Screen 5 and 10) ->  1 screen configuration of the screen background and txt1(number) and txt2(name) color
#define presetUpDown_screen_fillscreen TFT_SUPERBLUE //TFT_MAGENTA
#define presetUpDown_screen_fillscreen1 TFT_BLACK
#define presetUpDown_screen_fillscreen2 TFT_BLACK
#define presetUpDown_screen_txt1_color TFT_WHITE //TFT_BLACK
#define presetUpDown_screen_txt1_BG presetUpDown_screen_fillscreen1
#define presetUpDown_screen_txt2_color TFT_MAGENTA //TFT_SUPERBLUE
#define presetUpDown_screen_txt2_BG presetUpDown_screen_fillscreen1


/*=======================================================================================================================================*/


#define ampabcd_screen_black_fillscreen TFT_BLACK
#define ampabcd_screen_green_fillscreen TFT_MEGAGREEN //TFT_GREEN
#define ampabcd_screen_red_fillscreen TFT_SUPERRED //TFT_RED
#define ampabcd_screen_cyan_fillscreen TFT_CYAN


#define ampabcd_screen_style2_color TFT_BLACK
#define ampabcd_style2_BG ampabcd_screen_green_fillscreen

#define ampabcd_screen_style3_color TFT_BLACK //TFT_SKYBLUE
#define ampabcd_style3_BG ampabcd_screen_black_fillscreen

#define ampabcd_screen_style4_color TFT_BLACK
#define ampabcd_style4_BG ampabcd_screen_cyan_fillscreen

#define ampabcd_screen_style5_color TFT_YELLOW
#define ampabcd_style5_BG ampabcd_screen_black_fillscreen

/*=======================================================================================================================================*/


// PRESET number and name on Screen 13 -> configuration color of the number(txt1) and text (txt2)
#define screen13Style_fillscreen TFT_BLACK
#define screen13Style_txt1_color TFT_WHITE //TFT_SUPERBLUE 
#define screen13Style_txt1_BG TFT_SUPERBLUE //screen13Style_fillscreen
#define screen13Style_txt2_color TFT_YELLOW
#define screen13Style_txt2_BG screen13Style_fillscreen
#define screen13Style_txt3_color TFT_SUPERRED //TFT_RED


// PRESET screen -> 1 screen with "Preset" (txt1)  "Page" (txt2) on it (topscreens)
#define preset_screen_fillscreen TFT_ORANGE
#define preset_screen_txt1_color TFT_BLACK
#define preset_screen_txt1_BG preset_screen_fillscreen
#define preset_screen_txt2_color TFT_BLACK
#define preset_screen_txt2_BG preset_screen_fillscreen


/*=======================================================================================================================================*/

// EFFECT screen -> 1 screen configuration of the screen background and txt1(EFFECT) and txt2(PAGE) color
#define effect_screen_fillscreen TFT_BLACK
#define effect_screen_RECT_fillscreen TFT_SUPERBLUE //TFT_MAGENTA
#define effect_screen_txt1_color TFT_YELLOW //TFT_MEGAGREEN
#define effect_screen_txt1_BG TFT_BLACK
#define effect_screen_txt2_color TFT_WHITE  //TFT_SKYBLUE 
#define effect_screen_txt2_BG effect_screen_RECT_fillscreen

// EFFECT NOT ACTIVE background and text color settings
#define effectStyle1_fillscreen TFT_SUPERRED //TFT_RED
#define effectStyle1_txt1_color TFT_BLACK 
#define effectStyle1_txt1_BG effectStyle1_fillscreen

// EFFECT ACTIVE background and text color settings
#define effectStyle2_fillscreen TFT_MEGAGREEN //TFT_GREEN
#define effectStyle2_txt1_color TFT_BLACK
#define effectStyle2_txt1_BG effectStyle2_fillscreen

/*=======================================================================================================================================*/

// AMP ABCD screen -> 1 screen configuration of the screen background and txt1(AMP/CAB) and txt2(ABCD) color
#define ampABCD_screenB_fillscreen TFT_MAGENTA
#define ampABCD_screenR_fillscreen TFT_SUPERRED //TFT_RED
#define ampABCD_screenR_RECT_fillscreen TFT_SUPERBLUE
#define ampABCD_screen_txt1_color TFT_YELLOW //TFT_MEGAGREEN 
#define ampABCD_screen_txt1_BG TFT_BLACK
#define ampABCD_screen_txt2_color TFT_WHITE //TFT_BLACK //TFT_SKYBLUE 
#define ampABCD_screen_txt2_BG ampABCD_screenR_RECT_fillscreen
#define ampABCD_screen_txt3_color TFT_BLACK
#define ampABCD_screen_txt3_BG ampABCD_screenR_fillscreen


// TAP TEMPO screen ->  1 screen configuration of the screen background and txt1(TEMPO) and txt2(axe tempo) color
#define tapTempo_screen_fillscreen TFT_BLACK 
#define tapTempo_screen_RECT_fillscreen TFT_SUPERBLUE //TFT_MAGENTA
#define tapTempo_screen_txt1_color TFT_YELLOW //TFT_MEGAGREEN 
#define tapTempo_screen_txt1_BG TFT_BLACK
#define tapTempo_screen_txt2_color TFT_WHITE //TFT_BLACK
#define tapTempo_screen_txt2_BG tapTempo_screen_RECT_fillscreen
#define tapTempo_screen_flash_color1 TFT_BLACK   // this is the color of the flash rectangle background fillment
#define tapTempo_screen_sprite_color TFT_MEGAGREEN //TFT_GREEN   // this is the color of the flash rectangle border
#define tapTempo_screen_flash_color  TFT_MEGAGREEN //TFT_GREEN   // this is the color of the flash rectangle fillment

// TAP TEMPO selectionScreen (when tapping the TEMPO to the beat. The screen shows its selected and to be tapped again) 
// ->  1 screen configuration of the screen background and txt1(TAP) and txt2(axe tempo) color
#define tapTempo_selectionScreen_fillscreen TFT_SUPERRED //TFT_RED
#define tapTempo_selectionScreen_txt1_color TFT_WHITE
#define tapTempo_selectionScreen_txt1_BG tapTempo_selectionScreen_fillscreen
#define tapTempo_selectionScreen_txt2_color TFT_WHITE
#define tapTempo_selectionScreen_txt2_BG tapTempo_selectionScreen_fillscreen

/*=======================================================================================================================================*/

// LOOPER screen -> 1 screen with LOOPER(txt1) text color
#define looper_screen1_fillscreen TFT_MAGENTA
#define looper_screen1_txt_color TFT_SKYBLUE //TFT_CYAN
#define looper_screen1_txt_BG looper_screen_fillscreen

// LOOPER screen -> 6 screens with LOOPER(txt1) text color
#define looper_screen_fillscreen TFT_BLACK
#define looper_screen_txt1_color TFT_YELLOW
#define looper_screen_txt1_BG looper_screen_fillscreen

// LOOPER screen -> 6 screens (txt2) = selected looper option text color 
#define looper_screen_txt2_color TFT_SUPERRED //TFT_RED
#define looper_screen_txt2_BG looper_screen_fillscreen

/*=======================================================================================================================================*/

// NOWAH TOPscreen 11 configuration of the screen background and txt1(NO WAH ACTIVE) color
#define NOWAH_screen_fillscreen TFT_SUPERRED //TFT_RED
#define NOWAH_screen_txt1_color TFT_BLACK
#define NOWAH_screen_txt1_BG NOWAH_screen_fillscreen

// YESWAH TOPscreen 11 configuration of the screen background and txt1(WAH AVAILABLE) color
#define YESWAH_screen_fillscreen TFT_MEGAGREEN //TFT_GREEN
#define YESWAH_screen_txt1_color TFT_BLACK
#define YESWAH_screen_txt1_BG YESWAH_screen_fillscreen

/*=======================================================================================================================================*/

// NOLOOPER TOPscreen 12 configuration of the screen background and txt1(NO LOOPER) color
#define NOLOOPER_screen_fillscreen TFT_SUPERRED //TFT_RED
#define NOLOOPER_screen_txt1_color TFT_BLACK
#define NOLOOPER_screen_txt1_BG NOLOOPER_screen_fillscreen

// YESLOOPER TOPscreen 12 configuration of the screen background and txt1(LOOPER ACTIVE) color
#define YESLOOPER_screen_fillscreen TFT_MEGAGREEN //TFT_GREEN
#define YESLOOPER_screen_txt1_color TFT_BLACK
#define YESLOOPER_screen_txt1_BG YESLOOPER_screen_fillscreen

/*=======================================================================================================================================*/

// 1 NUMBER screen -> 1 screen configuration of the screen background and txt1(axelman8) and txt2(Number Select) color
#define number_screen_fillscreen TFT_MAGENTA
#define number_screen_RECT_fillscreen TFT_SUPERBLUE
#define number_screen_txt1_color TFT_YELLOW
#define number_screen_txt1_BG number_screen_RECT_fillscreen
#define number_screen_txt2_color TFT_YELLOW //TFT_MEGAGREEN 
#define number_screen_txt2_BG TFT_BLACK
#define number_screen_txt3_color TFT_WHITE //TFT_BLACK //TFT_SKYBLUE 
#define number_screen_txt3_BG number_screen_fillscreen

// NUMBERS 0 to 9 screens -> 10 screens configuration of the screen background and text color
#define numberSelect_screen_fillscreen TFT_BLACK
#define numberSelect_screen_txt1_color TFT_YELLOW
#define numberSelect_screen_txt1_BG numberSelect_screen_fillscreen

/*=======================================================================================================================================*/

// AUDITION MODE Screen 13 -> configuration of background and txt1 (audition) and txt2 (mode) color
#define auditionMode_screen_fillscreen TFT_MAGENTA
#define auditionMode_screen_txt1_color TFT_SUPERBLUE
#define auditionMode_screen_txt1_BG auditionMode_screen_fillscreen
#define auditionMode_screen_txt2_color TFT_BLUE
#define auditionMode_screen_txt2_BG auditionMode_screen_fillscreen

// AUDITION MODE Screen 12 -> configuration of background and txt1(select, type) and txt2(tuner) color
#define tuner_screen_fillscreen TFT_BLACK 
#define tuner_screen_RECT_fillscreen TFT_BLACK
#define tuner_screen_txt1_color TFT_BLACK //TFT_SKYBLUE
#define tuner_screen_txt1_BG tuner_screen_fillscreen
#define tuner_screen_txt2_color TFT_YELLOW
#define tuner_screen_txt2_BG tuner_screen_fillscreen

/*=======================================================================================================================================*/
/*Axelman8*/