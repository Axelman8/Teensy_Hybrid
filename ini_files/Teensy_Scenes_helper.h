#pragma once


void sceneHoldswitch()
{
	debug("\n"); debug("\n"); debug(" -> sceneHoldswitch started on Scenes_helper.h "); 
	switch (sceneNumber) 
    {
	case 1: HOLDSWITCH = SWITCH1; break;
    case 2: HOLDSWITCH = SWITCH2; break;
    case 3: HOLDSWITCH = SWITCH3; break;
    case 4: HOLDSWITCH = SWITCH4; break;
	case 5: HOLDSWITCH = SWITCH6; break;
	case 6: HOLDSWITCH = SWITCH7; break;
	case 7: HOLDSWITCH = SWITCH8; break;
	case 8: HOLDSWITCH = SWITCH9; break;
	}	
    previousHOLDSWITCH = HOLDSWITCH;
	debug("\n"); debug(" -> previousHOLDSWITCH is set to: "); debug(previousHOLDSWITCH); debug("\n");
}


void displayScene(const char* SC1, const char* SC2, const char* SC3, byte L1, byte L2, byte L3, byte ScNumber) 

	{
	if (L1 > 0)
			{
		sceneBigRectangle();
			if (sceneNumber == ScNumber)
			{scene_ACTIVEbezel();}
			
			if (L1 >= 9)
			{ sceneStyle2(); tft.println(SC1);}
			else
			{ sceneStyle3(); tft.setCursor(80 - ((L1 * 9) - 5), 6); tft.println(SC1); }
			tft.setCursor(80 - ((L2 * 9) - 5), 36);
			tft.println(SC2);
			tft.setCursor(80 - ((L3 * 9) - 5), 66);
			tft.println(SC3);
			}
		}
		
void activeScenesHelper(byte L1, byte ScNumber)
{
	if (L1 == 0)
	{
	if (ScNumber == 8)
	{drawArrayJpeg(Axelman8, sizeof(Axelman8), 35, 0);} 
		if (sceneNumber == ScNumber) 
		{scene_ACTIVEbezel();}
	}
	 else if (sceneNumber == ScNumber)
	{scene_ACTIVEbezel();}
}
		
/*=======================================================================================================================================*/
/*Axelman8*/		