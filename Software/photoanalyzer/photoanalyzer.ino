/*
 *    FILE: demo01.pde
 *  AUTHOR: Rob Tillaart
 *    DATE: 2011 05 16
 *
 * PURPOSE: prototype TSL235R monitoring  
 *
 * Digital Pin layout ARDUINO
 * =============================
 *  2     IRQ 0    - to TSL235R
 *
 * PIN 1 - GND
 * PIN 2 - VDD - 5V
 * PIN 3 - SIGNAL
 *
 */

volatile unsigned long cnt = 0;
unsigned long oldcnt = 0;
unsigned long t = 0;
unsigned long last;

int red = 6;
int blue = 7;
int white = 9;

String ledNames[3] = {"red", "blue", "white"};
int leds[3] = {red, blue, white};

void irq1()
{
  cnt++;
}

///////////////////////////////////////////////////////////////////
//
// SETUP
//
void setup() 
{
  Serial.begin(115200);
  while(!Serial);
  Serial.println("START");
  pinMode(2, INPUT_PULLUP);
//  digitalWrite(2, HIGH);
  attachInterrupt(digitalPinToInterrupt(2), irq1, RISING);

  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);

  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
}

///////////////////////////////////////////////////////////////////
//
// MAIN LOOP
//
void loop() 
{
//  if(millis()-lastTime > Fs)
//  {
//    
//  }
  
  if (millis() - last >= 1000)
  {
    last = millis();
    t = cnt;
    unsigned long hz = t - oldcnt;
    Serial.print("FREQ: "); 
    Serial.print(hz);
    Serial.print("\t = "); 
    Serial.print((hz+50)/100);  // +50 == rounding last digit
    Serial.println(" mW/m2");
    oldcnt = t;
  }
}
// END OF FILE
