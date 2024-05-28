#pragma once

#include <Arduino.h>
#include <Timer.h>
#include "MUX74HC4067.h"



/*=======================================================================================================================================*/

byte SWITCH;  //universal name that gets assigned with a SWITCH in a loop
byte CS;
byte HOLDSWITCH;
byte previousHOLDSWITCH;

MUX74HC4067 mux(15, 38, 39, 40, 41);

/*=======================================================================================================================================*/


//=============         TEENSY settings           ===============================

//Teensy 4.1 Switch pinnumbers on multiplexer:
#define M_SIZE 1
#define SWITCH1   0   // channel 0  red
#define SWITCH2   1   // channel 1  white
#define SWITCH3   2   // channel 2  bleu
#define SWITCH4   3   // channel 3  black
#define SWITCH5   4   // channel 4  yellow
#define SWITCH6   5   // channel 5  red
#define SWITCH7   6   // channel 6  white
#define SWITCH8   7   // channel 7  bleu
#define SWITCH9   8   // channel 8  black
#define SWITCH10  9   // channel 9  yellow
#define SWITCH11  10  // channel 10 red
#define SWITCH12  11  // channel 11 white
#define SWITCH13  12  // channel 12 bleu
#define SWITCH14  13  // channel 13 black
#define SWITCH15  14  // channel 14 yellow
#define SWITCH16  15  // channel 15 Green
#define SWITCH17  16  // 			Green
#define SWITCH18  17  // 			Green


//Teensy 4.1 Screens pinnumbers with CS number:
#define CS1 2
#define CS2 3
#define CS3 4
#define CS4 5
#define CS5 6

#define CS6 7
#define CS7 8
#define CS8 9
#define CS9 24
#define CS10 25

#define CS11 26
#define CS12 27
#define CS13 28
#define CS14 29
#define CS15 30


// ===  Teensy 4.1 ports for the screen buildup  ===
#define CS1L digitalWriteFast(CS1, LOW)
#define CS2L digitalWriteFast(CS2, LOW)
#define CS3L digitalWriteFast(CS3, LOW)
#define CS4L digitalWriteFast(CS4, LOW)
#define CS5L digitalWriteFast(CS5, LOW)
#define CS6L digitalWriteFast(CS6, LOW)
#define CS7L digitalWriteFast(CS7, LOW)
#define CS8L digitalWriteFast(CS8, LOW)
#define CS9L digitalWriteFast(CS9, LOW)
#define CS10L digitalWriteFast(CS10, LOW)
#define CS11L digitalWriteFast(CS11, LOW)
#define CS12L digitalWriteFast(CS12, LOW)
#define CS13L digitalWriteFast(CS13, LOW)
#define CS14L digitalWriteFast(CS14, LOW)
#define CS15L digitalWriteFast(CS15, LOW)

#define CS1H digitalWriteFast(CS1, HIGH)
#define CS2H digitalWriteFast(CS2, HIGH)
#define CS3H digitalWriteFast(CS3, HIGH)
#define CS4H digitalWriteFast(CS4, HIGH)
#define CS5H digitalWriteFast(CS5, HIGH)
#define CS6H digitalWriteFast(CS6, HIGH)
#define CS7H digitalWriteFast(CS7, HIGH)
#define CS8H digitalWriteFast(CS8, HIGH)
#define CS9H digitalWriteFast(CS9, HIGH)
#define CS10H digitalWriteFast(CS10, HIGH)
#define CS11H digitalWriteFast(CS11, HIGH)
#define CS12H digitalWriteFast(CS12, HIGH)
#define CS13H digitalWriteFast(CS13, HIGH)
#define CS14H digitalWriteFast(CS14, HIGH)
#define CS15H digitalWriteFast(CS15, HIGH)



/*=======================================================================================================================================*/
//    PEDDLEBOARD CONFIG WITH 18 BUTTONS 
/*=======================================================================================================================================*/

byte switches[18] = {SWITCH1,  SWITCH2,  SWITCH3,  SWITCH4,  SWITCH5,  SWITCH6,  
					 SWITCH7,  SWITCH8,  SWITCH9,  SWITCH10, SWITCH11, SWITCH12, 
					 SWITCH13, SWITCH14, SWITCH15, SWITCH16, SWITCH17, SWITCH18};

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/  