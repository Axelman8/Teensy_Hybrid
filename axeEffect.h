#pragma once


/*=======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/
#include <Timer.h>
#include <AxeFxControl.h>

  // USE the tabs
#include "Screenstyle.h"



/*=======================================================================================================================================*/
//       AMP CAB ABCD SETTINGS for AMP_effect_settings() on switch_PageSettings.h
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void selectAMP1(AxeEffect* effect)  
//============== AMP1 buttonpush 
{
  switch (changeCurrentEffect)
  {case 17: 

/* is AMP-CAB selected? if yes, Toggle and bypass  */  
              effect->toggle(); delay(100);
              if (effect->isBypassed())
              {effectSwitchBypass(); effect->printEffectName(tft);}
              else
              {effectSwitchActive(); effect->printEffectName(tft);}
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
              break;}

/* if AMP-CAB is not active then set currentEffect */
              currentEffect = effect17;
              changeCurrentEffect = 17;
              debug("\n"); debug(" currenteffect = 17");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
 
}

void selectAMP2(AxeEffect *effect)  
//============== AMP2 buttonpush 
{
  switch (changeCurrentEffect)
  {case 18: 

/* is AMP-CAB selected? if yes, Toggle and bypass  */
              effect->toggle(); delay(100);
              if (effect->isBypassed())
              {effectSwitchBypass(); effect->printEffectName(tft);}
              else
              {effectSwitchActive(); effect->printEffectName(tft);}
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine() ;            
              break;}
              
/* if AMP-CAB is not active then set currentEffect */
              currentEffect = effect18;
              changeCurrentEffect = 18;
              debug("\n"); debug(" currenteffect = 18");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
  
}


void selectCAB1(AxeEffect *effect)  
//============== CAB1 buttonpush 
{
  switch (changeCurrentEffect)
  {case 19:
/* is AMP-CAB selected? if yes, Toggle and bypass  */
              effect->toggle(); delay(100);
              if (effect->isBypassed())
              {effectSwitchBypass();effect->printEffectName(tft);}
              else
              {effectSwitchActive();effect->printEffectName(tft);}
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine() ;            
              break;}
              
/* if AMP-CAB is not active then set currentEffect */
              currentEffect = effect19;
              changeCurrentEffect = 19;
              debug("\n"); debug(" currenteffect = 19");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
  
}


void selectCAB2(AxeEffect *effect)  
//============== CAB2 buttonpush 
{
  switch (changeCurrentEffect)
  {case 20:  
/* is AMP-CAB selected? if yes, Toggle and bypass  */
              effect->toggle(); delay(100);
              if (effect->isBypassed())
              {effectSwitchBypass();effect->printEffectName(tft);}
              else
              {effectSwitchActive();effect->printEffectName(tft);}
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());
              
              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
              break;}
              
/* if AMP-CAB is not active then set currentEffect */
              currentEffect = effect20;
              changeCurrentEffect = 20;
              debug("\n"); debug(" currenteffect = 20");
              effectchannelswitchStyle0();
              tft.println(effect->getChannelChar());

              //draw line and bezel to show its selected
              ampabcdStyle_greenBezelLine();
 
}


/*=======================================================================================================================================*/
//       AMP CAB CHANNELSWITCH A-B-C-D  for AMP_effect_settings() on switch_PageSettings.h
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


void channelSwitchA(AxeEffect *effect)

{
    if (currentEffect != 0)
    {
      AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
      channel = "A";
      effect->switchChannel(0);
      if (currentEffect == effect17)
      {
      if (effect19 == 62)
      {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19);
      channel = "A";
      effect->switchChannel(0);}
      }
      else if (currentEffect == effect18)
      {
      if (effect20 == 63)
      {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect20);
      channel = "A";
      effect->switchChannel(0);}
      }                
      CS6L; ampabcdStyle2(); CS6H;
      CS7L; CS8L; CS9L; ampabcdStyle3(); CS7H; CS8H; CS9H;
    }  
 }

void channelSwitchB(AxeEffect *effect)
{
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "B";
                effect->switchChannel(1);
                if (currentEffect == effect_ids[17])
                {
                if (effect19 == 62)
                {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19);
                channel = "B";
                effect->switchChannel(1);}
                }
                else if (currentEffect == effect18)
                {
                  if (effect20 == 63)
                {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect20);
                channel = "B";
                effect->switchChannel(1);}
                }                
                CS7L; ampabcdStyle2(); CS7H;
                CS6L; CS8L; CS9L; ampabcdStyle3(); CS6H; CS8H; CS9H;
              }  
  }

void channelSwitchC(AxeEffect *effect)
{
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "C";                
                effect->switchChannel(2);
                if (currentEffect == effect17)
                {
                if (effect19 == 62)
                {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19);
                channel = "C";
                effect->switchChannel(2);}
                }
                else if (currentEffect == effect18)
                {
                  if (effect20 == 63)
                  {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect20);
                channel = "C";
                effect->switchChannel(2);}
                }
                CS8L; ampabcdStyle2(); CS8H;
                CS6L; CS7L; CS9L; ampabcdStyle3(); CS6H; CS7H; CS9H;
              }  
  }

void channelSwitchD(AxeEffect *effect)
{
              if (currentEffect != 0)
              {
                AxeEffect *effect = Axe.getCurrentPreset().getEffectById(currentEffect);
                channel = "D";
                effect->switchChannel(3);
                if (currentEffect == effect17)
                {
                if (effect19 == 62)
                {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect19);
                channel = "D";
                effect->switchChannel(3);}
                }
                else if (currentEffect == effect18)
                {
                  if (effect20 == 63)
                  {AxeEffect *effect = Axe.getCurrentPreset().getEffectById(effect20);
                channel = "D";
                effect->switchChannel(3);}
                }
                CS9L; ampabcdStyle2(); CS9H;
                CS6L; CS7L; CS8L; ampabcdStyle3(); CS6H; CS7H; CS8H;
              }  
  }



/*=======================================================================================================================================*/
//       AMP CAB ABCD SETTINGS for onEffectsReceived(PresetNumber number, AxePreset preset) on axe_handler.h
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

  void AMP1(AxeEffect effect)  
//============== AMP1 on screen 1
{
    effect17 = (effect.getEffectId());
    debug("\n"); debug(" * effect17 value = "); debug(effect17);
    CS1L;
    tft.fillScreen(TFT_BLACK);
    if (effect.isBypassed()) 
    {effectSwitchBypass();effect.printEffectName(tft);}
    else 
    {effectSwitchActive();effect.printEffectName(tft);}
    effectchannelswitchStyle0();
    tft.println(effect.getChannelChar());
    CS1H;
  }

  void AMP2(AxeEffect effect)  
//============== AMP2 on screen 2
{
    effect18 = (effect.getEffectId());
    debug("\n"); debug(" * effect18 value = "); debug(effect18);
    CS2L;
    tft.fillScreen(TFT_BLACK);
    if (effect.isBypassed()) 
    {effectSwitchBypass();effect.printEffectName(tft);}
    else 
    {effectSwitchActive();effect.printEffectName(tft);}
    effectchannelswitchStyle0();
    tft.println(effect.getChannelChar());
    CS2H;
 }

  void CAB1(AxeEffect effect)  
//============== CAB1 on screen 4
{
    effect19 = (effect.getEffectId());
    debug("\n"); debug(" * effect19 value = "); debug(effect19);
    CS4L;
    tft.fillScreen(TFT_BLACK);
    if (effect.isBypassed()) 
    {effectSwitchBypass();effect.printEffectName(tft);}
    else 
    {effectSwitchActive();effect.printEffectName(tft);}
    effectchannelswitchStyle0();
    tft.println(effect.getChannelChar());
    CS4H;  
  }

  void CAB2(AxeEffect effect)  
//============== CAB2 on screen 5
{
    effect20 = (effect.getEffectId());
    debug("\n"); debug(" * effect20 value = "); debug(effect20);
    CS5L;
    tft.fillScreen(TFT_BLACK);
    if (effect.isBypassed()) 
    {effectSwitchBypass();effect.printEffectName(tft);}
    else 
    {effectSwitchActive();effect.printEffectName(tft);}
    effectchannelswitchStyle0();
    tft.println(effect.getChannelChar());
    CS5H;  
  }

/*=======================================================================================================================================*/
/*Axelman8*/