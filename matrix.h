#pragma once
#include <TFT_eSPI.h>
#include <DigitalRainAnimation.hpp>

void stopTheMAtrix()
{
    if (digitalReadFast(switches[17]) == LOW) 
    {
    matrix_effect.pause();  
    clearAllScreens();
    CS11L; Screen_11; CS11H;
    CS12L; Screen_12; CS12H;
    CS14L; Screen_14; CS14H;
    CS15L; Screen_15; CS15H;
    holdAction = 0; sceneSwitch_13; 
    delay(200);
    }
}


void setupMatrix() 
{
  clearAllScreens();
  strcpy(page, "matrix");
  CS11L, CS12L, CS13L, CS14L, CS15L;
  matrix_effect.init(&tft);
  CS6L, CS7L, CS8L, CS9L, CS10L; 
  matrix_effect.init(&tft);
  CS1L, CS2L, CS3L, CS4L, CS5L;
  matrix_effect.init(&tft);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(staticText);
  lcd.setCursor(0, 1);
  lcd.print(scrollText.substring(0, scrollText.length() - lcdWidth));
}

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/