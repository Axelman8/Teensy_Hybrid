#pragma once


/*=======================================================================================================================================*/
//   TUNER VARIBLES
/*---------------------------------------------------------------------------------------------------------------------------------------*/

char screenMessage[50];
TFT_eSPI* screen = new TFT_eSPI();
TFT_eSprite* tunerNoteCanvas = NULL;

byte tft_w = TUNER_TFT_WIDTH;
byte tft_h = TUNER_TFT_HEIGHT;

#define NEEDLE_LENGTH 60  // Visible length
#define NEEDLE_RADIUS 60  // Radius at tip
#define DIAL_CENTRE_X (tft_w / 2)
#define DIAL_CENTRE_Y (tft_h / 2 + 15)
#define NEEDLE_COLOR1 TFT_WHITE
#define NEEDLE_COLOR2 TFT_MEGAGREEN

char lastNote[2];
char lastFineTune;
bool hasCleared = false;
byte fineTune = 50;

int radius = tft_w / 2;
int cx = tft_w / 2;
int cy = tft_h / 2 + 15;
int startAngle = 0;
int endAngle = 180;
int numTicks = 36; // 180 degrees / 5 degrees per tick = 36 ticks
float angleIncrement = (endAngle - startAngle) / (float)numTicks;

double old_rads;
uint16_t old_x0;
uint16_t old_y0;
uint16_t old_x1;
uint16_t old_y1;
uint16_t old_x2;
uint16_t old_y2;
uint16_t  bg_color = 0;
int16_t previousFineTune = -1;

      int triangleWidth;
      int xx0; 
      int yy0; 
      int xx1;
      int yy1; 
      int xx2;
      int yy2;


/*=======================================================================================================================================*/
//   TUNER OFF
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void auditionmodePage_selection();


void onTunerStatus(bool engaged) 
{
    debug("\n* function onTunerStatus() started on Tuner.h");
    if (!Axe.isTunerEngaged()) 
    {
        holdAction = 0;
        if (auditionMode != 1) 
        {
            getScenes = true;
            effectCycle = true;
            Axe.refresh();
            debug("\n *-> TUNER ended");
            delay(40);
            CS15L;
            Screen_15;
            CS15H;
        } else 
          {
              CS15L;
              Screen_15;
              CS15H;
              auditionmodePage_selection();
          }
        delay(10);
    }
}

/*=======================================================================================================================================*/

void onlyTuner() 
{
    if (digitalReadFast(switches[17]) == LOW) 
    {
        Axe.toggleTuner();
        if (!Axe.isTunerEngaged())
        Axe.fetchEffects(true);
        debug("\n Switch-18 ");
        delay(200);
    }
}


/*=======================================================================================================================================*/

void buildTuner() 
{
    CS15L;
    debug("\n* function buildTuner() started on Tuner.h");
    int radius = tft_w / 2;
    int cx = tft_w / 2;
    int cy = tft_h / 2 + 15;

    for (int i = 0; i <= numTicks; i++) 
    {
        float angle = startAngle + i * angleIncrement;
        if (angle == 90) {
            continue;
        }

        int tickLength = 5;
        if (i % 3 == 0) {
            tickLength = 10;
        }
        int x1 = cx + (radius - tickLength) * cos(angle * DEG_TO_RAD);
        int y1 = cy - (radius - tickLength) * sin(angle * DEG_TO_RAD);
        int x2 = cx + radius * cos(angle * DEG_TO_RAD);
        int y2 = cy - radius * sin(angle * DEG_TO_RAD);

        tft.drawLine(x1, y1, x2, y2, TFT_WHITE);
    }

      triangleWidth = 12;
      xx0 = tft_w / 2; 
      yy0 = 12; 
      xx1 = xx0 - triangleWidth / 2;
      yy1 = yy0 - triangleWidth; 
      xx2 = xx0 + triangleWidth / 2;
      yy2 = yy0 - triangleWidth; 
      tft.fillTriangle(xx0, yy0, xx1, yy1, xx2, yy2, TFT_MEGAGREEN);

    CS15H;
}

/*=======================================================================================================================================*/

void plotNeedle(int16_t fineTune, uint16_t ms_delay, const char* note, int dialCentreX, int dialCentreY) 
{
    static int16_t old_fineTune = -1; // Begin met een waarde die buiten het bereik van de finetune ligt
    //static int16_t old_needle_x = 0;
    //static int16_t old_needle_y = 0;
    static unsigned long previousMillis = 0;
    unsigned long currentMillis = millis();

    if (fineTune != old_fineTune) { // Controleer of de finetune is gewijzigd
        old_fineTune = fineTune; // Update de vorige finetune-waarde

        if (currentMillis - previousMillis >= ms_delay) 
        {
            previousMillis = currentMillis;
            CS15L;
            // Wis de oude naald door deze opnieuw te tekenen met de achtergrondkleur
            tft.fillTriangle(old_x0, old_y0, old_x1, old_y1, old_x2, old_y2, bg_color);

            // Teken de nieuwe naald
            float angle = map(fineTune, 0, 127, 0, 180);
            angle = constrain(angle, 0, 180);

            double rads = PI + TWO_PI * (fineTune * 90.0 / 127.0) / 180.0;
            uint16_t x0 = cos(rads) * NEEDLE_LENGTH + dialCentreX;
            uint16_t y0 = sin(rads) * NEEDLE_LENGTH + dialCentreY;
            uint16_t x1 = cos(rads - PI / 2) * 3 + dialCentreX;
            uint16_t y1 = sin(rads - PI / 2) * 3 + dialCentreY;
            uint16_t x2 = cos(rads + PI / 2) * 3 + dialCentreX;
            uint16_t y2 = sin(rads + PI / 2) * 3 + dialCentreY;
            // Teken een cirkel aan het beginpunt van de naald
            // Kleur van de naald instellen
            //uint16_t needleColor = (fineTune > 61 && fineTune < 65) ? TFT_MEGAGREEN : TFT_WHITE;
            uint16_t rectColor = (fineTune > 61 && fineTune < 65) ? TFT_MEGAGREEN : TFT_MAGENTA;
            uint16_t circleColor = (fineTune > 61 && fineTune < 65) ? TFT_MEGAGREEN : TFT_SUPERRED;

            tft.fillTriangle(xx0, yy0, xx1, yy1, xx2, yy2, TFT_MEGAGREEN);

            tft.fillRect(0, cy+2, tft_w, 5, rectColor);
            tft.fillTriangle(x0, y0, x1, y1, x2, y2, TFT_MEGAGREEN);
            tft.fillCircle(cx, y1+5, 10, circleColor);
            tft.drawCircle(cx, y1+5, 10, TFT_BLACK);
            tft.drawCircle(cx, y1+5, 11, TFT_BLACK);
            tft.fillCircle(cx, y1+5, 5, TFT_BLACK);

            tft.fillRect(58, 100, 60, 28, TFT_BLACK);
            tft.setTextColor(TFT_MEGAGREEN, TFT_BLACK);
            tft.setTextSize(4);
            tft.setTextDatum(CC_DATUM); 
            tft.setCursor(((tft_w / 2)-15), 100); 
            tft.print(note);

            old_x0 = x0;
            old_y0 = y0;
            old_x1 = x1;
            old_y1 = y1;
            old_x2 = x2;
            old_y2 = y2;

            CS15H;
        }
    }
}

/*=======================================================================================================================================*/

void drawCentreString(TFT_eSPI* canvas, const char* note, byte tft_h, byte tft_w) 
{
    debug("\n* function drawCentreString() started on Tuner.h");
    canvas->setTextDatum(MC_DATUM);
    canvas->setCursor(0, 0);
    canvas->drawString(note, tft_h / 2, tft_w / 2);
}

/*=======================================================================================================================================*/

void drawArrow( int32_t xpos, int32_t ypos, int32_t h, int32_t w, int32_t r, uint32_t color) 
{
  int32_t x0, y0, x1, y1, x2, y2;
  x0 = xpos + (w / 2);
  y0 = ypos + (h / 2);
  x1 = xpos - (w / 2);
  y1 = ypos + (h / 2);
  x2 = xpos;
  y2 = ypos - (h / 2);

  CS15L;
  tft.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  CS15H;
}

/*=======================================================================================================================================*/

void displayPyramidTuner(TFT_eSPI* screen, const char *note, const byte string, const byte fineTune) 
{
  tft.setRotation(1);
  if (tunerNoteCanvas == NULL) 
  {
    tunerNoteCanvas = new TFT_eSprite(screen);
    tunerNoteCanvas->setColorDepth(8);
    tunerNoteCanvas->createSprite(80, 60);
  }
  auto skipNoteDisplay = hasCleared && (note[0] == lastNote[0] && note[1] == lastNote[1]);
  lastNote[0] = note[0];
  lastNote[1] = note[1];  

  CS15L;
  if (!hasCleared) 
  {
    screen->fillScreen(TFT_BLACK); 
    hasCleared = 1;
  }

  if (!skipNoteDisplay) 
  {
    sprintf(screenMessage, "%s", note);
    if (note[1] == '#' || note[1] == 'b') 
    {
      screenMessage[2] = '\0';
    }
    else 
    {
      screenMessage[1] = '\0';
    }

    tunerNoteCanvas->fillScreen(TFT_BLACK);
    tunerNoteCanvas->setTextSize(6);
    tunerNoteCanvas->setTextColor(TFT_MEGAGREEN);

    drawCentreString(tunerNoteCanvas, screenMessage, 70, 60);

      tunerNoteCanvas->pushSprite(50, 10);
  }

  if (lastFineTune != fineTune) 
  {
    // black out last marker (more efficient than full screen)
    int x = (lastFineTune / 127.0) * tft_w;

    // draw center lines
    screen->fillRect(tft_w/2-1-3,tft_h-50-1, 5, 50, TFT_MAGENTA);
    drawArrow(x, 145, tft_h - 25, tft_h - 25, 50, TFT_BLACK);
    lastFineTune = fineTune;
    auto tunerColour = fineTune > 60 && fineTune < 64 ? TFT_MEGAGREEN : TFT_SUPERRED;
    x = (fineTune / 127.0) * tft_w;
    drawArrow(x, 145, tft_h - 25, tft_h - 25, 50, tunerColour);
   }
   tft.fillRect(0, tft_h-53,160, 2, TFT_MAGENTA);  // yellow line because of problem with screen width  
  CS15H;
  }

/*=======================================================================================================================================*/

void displayRadiusTuner(const char* note, const byte string, const byte fineTune, int dialCentreX, int dialCentreY) {
    auto skipNoteDisplay = hasCleared && (note[0] == lastNote[0] && note[1] == lastNote[1]);
    lastNote[0] = note[0];
    lastNote[1] = note[1];

    if (!skipNoteDisplay) 
    {
        // Zet de note-waarde om in de gewenste stringnotatie
        sprintf(screenMessage, "%s", note);
        if (note[1] == '#' || note[1] == 'b') {
            screenMessage[2] = '\0';
        } else {
            screenMessage[1] = '\0';
        }
    }
    
    // Controleer of fineTune is gewijzigd voordat de naald wordt bijgewerkt
    if (fineTune != previousFineTune) 
    {
        plotNeedle(fineTune, 10, screenMessage, dialCentreX, dialCentreY); // Bijwerken van de naald met de nieuwe fineTune-waarde
        previousFineTune = fineTune; // Update de vorige fineTune-waarde
    }
}

/*=======================================================================================================================================*/

void onTunerData(const char* note, const byte string, const byte fineTune) 
    {
     if (tunerScreen15_radius == false)
      {displayPyramidTuner(screen, note, string, fineTune);}
      else
      {displayRadiusTuner(note, string, fineTune, DIAL_CENTRE_X, DIAL_CENTRE_Y);}
    }

/*=======================================================================================================================================*/
/*Axelman8*/