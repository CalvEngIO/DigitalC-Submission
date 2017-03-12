/*
  FILENAME:   monochromater.ino
  AUTHOR:     Orlando S. Hoilett
  DATE:       Sunday, September 7, 2014
  
  
  UPDATES:
  
  Version 0.0.0
  09/07/2014:1930>
              Reads value from detector circuit using one of the
              analog in pins on the Arduino.
  09/08/2014:1253>
              Added redON(), greenON(), and blueON() functions to
              easily select the wavelength of light we want the
              RGB LED to emit.       
              
  DESCRIPTION
  
  This program reads voltages from a photodetector circuit for a
  simple monochromator. This example was created as a demonstration
  of pulse oximetry for first-year engineering students at
  Vanderbilt University.

*/

//declare variables
const int sensorPin = A0; //Analog In Pin 0
int ADCvalue = 0;
double sensorVoltage = 0;

//define pin locations
int redPin = 3; //digitalPin 3
int greenPin = 4; //digitalPin 4
int bluePin = 5; //digitalPin 5

//initialize helper methods
double convertToVoltage(int ADCvalue);
void initializeLEDPins(int redPin, int greenPin, int bluePin);
void redON();
void greenON();
void blueON();


void setup()
{
  //begin communication with Arduino and computer
  Serial.begin(9600);
  
  initializeLEDPins(redPin, greenPin, bluePin);
  
  //you should write the function to turn on the correct color
  //here please remember to type the semicolon ";" at the end of
  //the function like you see with all the other commands I have
  //written
  
  redON();
  
  //did you add the semicolon ";" at the end?

}


void loop()
{
  //reads value from sensor using Arduino
  ADCvalue = analogRead(sensorPin);
  
  //convert ADC value to a voltage using the conversion
  //(ADCvalue / 1023) * 5
  sensorVoltage = convertToVoltage(ADCvalue);
  
  //print the value to the "COM" port
  Serial.println(sensorVoltage);
  
  //wait for a bit to print the data
  //this makes it easier to read in the "COM" port
  delay(350);
  
}


double convertToVoltage(int ADCvalue)
{
  return (ADCvalue / 1023.0) * 5.0;
}

void initializeLEDPins(int redPin, int greenPin, int bluePin)
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void redON ()
{
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, HIGH);
}

void greenON ()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, HIGH);
}


void blueON ()
{
  digitalWrite(redPin, HIGH);
  digitalWrite(greenPin, HIGH);
  digitalWrite(bluePin, LOW);
}
