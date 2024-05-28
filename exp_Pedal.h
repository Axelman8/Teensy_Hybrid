#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
#include <Arduino.h>
#include <TFT_eSPI.h>

int16_t screenHeight = 128;
int16_t screenWidth = 160;

TFT_eSPI* pedalDisplay1 = new TFT_eSPI();  // Scherm 1
TFT_eSPI* pedalDisplay2 = new TFT_eSPI();  // Scherm 2

TFT_eSprite sprite1 = TFT_eSprite(pedalDisplay1);  // Sprite voor scherm 1
TFT_eSprite sprite2 = TFT_eSprite(pedalDisplay2);  // Sprite voor scherm 2

// Definieer pinnen voor pedalen
#define PEDAL01  A6
#define PEDAL02  A7

const byte pedal[2] = {PEDAL01, PEDAL02};
const unsigned int pedalValueCalibrationMinimumLevel[2] = {0, 0};
const unsigned int pedalValueCalibrationMaximumLevel[2] = {1023, 1023};
byte controllerValueMinimumLevel[2] = {0, 0};
byte controllerValueMaximumLevel[2] = {127, 127};
const byte pedalCC[2] = {6, 7}; //define the CC for each pedal
byte circlePedals;
unsigned int pedalValue[2];
unsigned int pedalValueOld[2];
byte controllerValueOld[2];
byte controllerValue[2];

void updatePedalSprite(int pedalValue, bool isLeft) 
{
    // Selecteer het juiste scherm en sprite
    TFT_eSprite* sprite = isLeft ? &sprite1 : &sprite2;

    // Selecteer de juiste CS-pin
    isLeft ? CS11L : CS12L;

    // Constanten definiëren
    const int spriteWidth = 10;
    const int totalHeight = 128;
    const int numberOfBlocks = 20;
    const int blockHeight = totalHeight / numberOfBlocks;
    const uint16_t transparentColor = TFT_BLACK;

    // Bereken de x-positie afhankelijk van de zijde
    int xPos = isLeft ? 0 : 0; // Plaats de sprite aan de rechterkant op x-coördinaat 80

    // Maak de sprite
    sprite->setColorDepth(16);
    sprite->createSprite(spriteWidth, totalHeight);
    sprite->fillSprite(transparentColor);

    // Bepaal de breedte van de rand
    int borderSize = 1;

    // Bepaal de kleur van elk blokje en teken het met randen
    for (int i = 0; i < numberOfBlocks; i++) 
    {
        // Bepaal de kleur van het blokje op basis van de pedaalwaarde
        int color = map(pedalValue, 1, 126, 0, numberOfBlocks);
        uint16_t fillColor;
        if (color > i) 
        {
            if (i < numberOfBlocks / 4) 
            {fillColor = TFT_SUPERRED;} 
            else if (i < numberOfBlocks / 2) 
            {fillColor = TFT_ORANGES;} 
            else if (i < numberOfBlocks * 3 / 4) 
            {fillColor = TFT_YELLOWS;} 
            else {fillColor = TFT_MEGAGREEN;}
            // Teken het blokje met randen
            sprite->fillRect(borderSize, totalHeight - (i + 1) * blockHeight + borderSize, spriteWidth - 2 * borderSize, blockHeight - 2 * borderSize, fillColor);
            sprite->drawRect(0, totalHeight - (i + 1) * blockHeight, spriteWidth, blockHeight, TFT_BLACK); 
        } else 
          {
            sprite->drawRect(0, totalHeight - (i + 1) * blockHeight, spriteWidth, blockHeight, TFT_BLACK); 
          }
    }

    // Toon de sprite op het scherm
    sprite->pushSprite(xPos, 0);

    // Zet CS-pin hoog om de communicatie te beëindigen
    isLeft ? CS11H : CS12H;
}




void expressionPedals() 
{
    for (circlePedals = 0; circlePedals < 2; circlePedals++) 
    {
        pedalValue[circlePedals] = analogRead(pedal[circlePedals]) * 0.4 + pedalValueOld[circlePedals] * 0.6;
        controllerValue[circlePedals] = map(pedalValue[circlePedals], pedalValueCalibrationMinimumLevel[circlePedals], pedalValueCalibrationMaximumLevel[circlePedals], controllerValueMinimumLevel[circlePedals], controllerValueMaximumLevel[circlePedals]);

        if (controllerValue[circlePedals] != controllerValueOld[circlePedals]) 
        {
            if (controllerValue[circlePedals] >= 2 && controllerValue[circlePedals] <= 127) 
            {
                Axe.sendControlChange(pedalCC[circlePedals], controllerValue[circlePedals], midichannel);
                //lcd.setCursor(0,1); lcd.print("EXPRPEDAL"); lcd.print(circlePedals + 1); lcd.print(" =    "); lcd.setCursor(13,1); lcd.print(controllerValue[circlePedals]);
                updatePedalSprite(controllerValue[0], true);   // Update sprite pedal 1, left
                updatePedalSprite(controllerValue[1], false);  // Update sprite pedal 2, Right
            }
            controllerValueOld[circlePedals] = controllerValue[circlePedals];
            pedalValueOld[circlePedals] = pedalValue[circlePedals];
        }
    }
}


/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/