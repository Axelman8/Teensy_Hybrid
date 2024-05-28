#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
#include "SdFat.h"

SdFs sd;
FsFile presetNameFile;


const uint16_t bufSize = 60;      //This needs to be as long as the longest preset name + 1 byte

char presetName[10][bufSize];     //Array for storing the loaded preset names


void loadPresetNames() 
{
  for (uint8_t i=0; i<10; i++) {
    int n = presetNameFile.fgets(presetName[i], bufSize);
    if (n > 7) {
      strcpy(presetName[i], &presetName[i][7]); // Skip first 7 characters
    }
  }
}


void preset_Names() 
{

  //Open file
  if (!presetNameFile.open("preset names.txt", FILE_READ)) {
    Serial.println("Error, SD card is out of its sloth");
    return;
  };

  //Read through preset names, skipping lines until we reach the right 'set'
  uint16_t presetCount = 0;
  while (presetCount < PresetNumb) {
    presetNameFile.fgets(presetName[0], bufSize);  //Dummy storage for skipped preset name
    presetCount += 1;
  }

  //Load the next 10 lines into presetName array
  loadPresetNames();
  
  //Close file
  presetNameFile.close();

  //Print loaded preset names
  for (uint8_t i=0; i<10; i++) 
  {
    //Serial.println(presetName[i]);
    switch (i) 
          {
            case 0: strcpy(PresetName0, presetName[i]); break;
            case 1: strcpy(PresetName1, presetName[i]); break;
            case 2: strcpy(PresetName2, presetName[i]); break;
            case 3: strcpy(PresetName3, presetName[i]); break;
            case 4: strcpy(PresetName4, presetName[i]); break;
            case 5: strcpy(PresetName5, presetName[i]); break;
            case 6: strcpy(PresetName6, presetName[i]); break;
            case 7: strcpy(PresetName7, presetName[i]); break;
            case 8: strcpy(PresetName8, presetName[i]); break;
            case 9: strcpy(PresetName9, presetName[i]); break;
          }
  }
}

void presetRange()
{
  //This will convert your PresetNumb in the same apparent way the large switch statement does
  PresetNumb = floor(PresetNumb / 10) * 10;
  preset_Names();
}

/*=======================================================================================================================================*/
/*Axelman8*/