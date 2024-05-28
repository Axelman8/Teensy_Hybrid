#pragma once


void displayPreset(const char* PresetName, int presetNumber) 
{
  strcpy(active_PresetName, PresetName);
  PresetName_helper();
  if ((PresetNumb + presetNumber) != (active_Preset))
  {
    presetNames_buildup();
    presetNumberStyle1(); tft.println(PresetNumb + presetNumber);
  }
  else 
  {
    presetNumberStyle2_fillscreen;
    active_presetNames_buildup();
    presetNumberStyle2(); tft.println(PresetNumb + presetNumber);
  }
}

void displayPresetNumber(int presetNumber)
{
	presetNumberStyle1(); tft.println(PresetNumb + presetNumber);
}

/*=======================================================================================================================================*/
/*Axelman8*/