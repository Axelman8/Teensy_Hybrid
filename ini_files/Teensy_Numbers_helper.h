#pragma once

void numberhelper()
{
            Counter = Counter + 1;
            inputNumber = MPLXCounter;
            debug("\n"); debug(" Counter = ");  debug(Counter);
            debug("\n"); debug(" Inputnumber = ");  debug(inputNumber);
            if ( Counter == 1)      
              {
              n1 = inputNumber;
              debug("\n"); debug(" N1 = ");  debug(n1);
              lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n1);
              }
              else if ( Counter == 2) 
                {
                  n2 = ((n1 * 10) + inputNumber);
                  debug("\n"); debug(" N2 = ");  debug(n2);
                  lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n2);
                }
                 else if ( Counter == 3) 
                  {
                    n3 = ((n2 * 10) + inputNumber);
                    debug("\n"); debug(" N3 = ");  debug(n3);
                    lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n3);
                  }
                    else if ( Counter == 4) 
                    {
                      n4 = ((n3 * 10) + inputNumber);
                      debug("\n"); debug(" N4 = ");  debug(n4);
                      lcd.setCursor(0, 1); lcd.print(" Number = "); lcd.print(n4);
                    }
  }


/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/
