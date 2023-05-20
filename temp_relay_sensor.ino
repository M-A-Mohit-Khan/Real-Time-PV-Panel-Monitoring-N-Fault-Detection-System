#include <OneWire.h>
#include <DallasTemperature.h>
// Define constants
#define REFERENCE_VOLTAGE 5.0
#define SENSOR_READING_MULTIPLIER 5.0
#define SENSOR_CALIBRATION_SENSITIVITY 1000.0 / 200.0
#define SENSOR_CALIBRATION_VREF 2500
#define AVERAGE_READINGS 1000

// Define relay pins
#define RELAY_1 2
#define RELAY_2 3
#define RELAY_3 4
#define RELAY_4 5

//Ds18b20 pin define, one wire instance and Dallastemp library setup
const int SENSOR_PIN = 13; 
OneWire oneWire(SENSOR_PIN);        
DallasTemperature tempSensor(&oneWire);
float tempCelsius;

// Function to take the average of analog readings
float getAnalogReading(int pin)
{
  long sum = 0;
  for (int i = 0; i < AVERAGE_READINGS; i++)
  {
    sum += analogRead(pin);
    delay(2);
  }
  return (float)sum / AVERAGE_READINGS;
}

void setup() {
    // Initialize serial communication
  Serial.begin(9600);
  delay(100);
   tempSensor.begin();    // initialize the sensor
  delay(10000); // Delay to give time for Serial Monitor to connect

  // Initialize relay pins as outputs
  pinMode(RELAY_1, OUTPUT);
  pinMode(RELAY_2, OUTPUT);
  pinMode(RELAY_3, OUTPUT);
  pinMode(RELAY_4, OUTPUT);
   // Turn off all the relays
  digitalWrite(RELAY_1, LOW);
  digitalWrite(RELAY_2, LOW);
  digitalWrite(RELAY_3, LOW);
  digitalWrite(RELAY_4, LOW);
}

void loop() {
// Temperature calculation
float tempCelsius;
long int sensorValue=0;
  tempSensor.requestTemperatures();             // send the command to get temperatures
  tempCelsius = tempSensor.getTempCByIndex(0);
  for(int i = 0; i < AVERAGE_READINGS; i++)
  {
    sensorValue += tempCelsius;
    delay(5);
  }  // read temperature in Celsius
  //tempFahrenheit = tempCelsius * 9 / 5 + 32; // convert Celsius to Fahrenheit
float Temp = sensorValue / AVERAGE_READINGS;
  Serial.print(Temp,2);    // print the temperature in Celsius
  Serial.print(", ");
  // Serial.print("\n"); // comment it while serial communication
  delay(2000);

// Turn on each relay for  and then turn it off
  digitalWrite(RELAY_1, HIGH);
  delay(5000);
  // Measure the voltage for 1st array
  float Vol_sen1 = getAnalogReading(A1) * REFERENCE_VOLTAGE / 1023.0;
  float Voltage1 = Vol_sen1* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the open circuit voltage for 1st array
  float Open_Vol_sen1 = getAnalogReading(A2) * REFERENCE_VOLTAGE / 1023.0;
  float OC_Voltage1 = Open_Vol_sen1* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the current for 1st array
  float Current1 = (getAnalogReading(A0) * (REFERENCE_VOLTAGE / 1023.0*1000) - SENSOR_CALIBRATION_VREF) * SENSOR_CALIBRATION_SENSITIVITY;
  delay(1000);
  // Print the values
    Serial.print(Voltage1, 2);
    Serial.print(", ");
    Serial.print(OC_Voltage1, 2);
    Serial.print(", ");
    Serial.print(Current1, 2);
    Serial.print(", ");
   // Serial.print("\n"); // comment it while serial communication
  digitalWrite(RELAY_1, LOW);
  delay(3000);

  digitalWrite(RELAY_2, HIGH);
  delay(5000);
 // Measure the voltage for 2nd array
  float Vol_sen2 = getAnalogReading(A1) * REFERENCE_VOLTAGE / 1023.0;
  float Voltage2 = Vol_sen2* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the open circuit voltage for 2nd array
  float Open_Vol_sen2 = getAnalogReading(A2) * REFERENCE_VOLTAGE / 1023.0;
  float OC_Voltage2 = Open_Vol_sen2* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the current for 2nd array
  float Current2 = (getAnalogReading(A0) * (REFERENCE_VOLTAGE / 1023.0*1000) - SENSOR_CALIBRATION_VREF) * SENSOR_CALIBRATION_SENSITIVITY;
  delay(1000);
  // Print the values
   Serial.print(Voltage2, 2);
    Serial.print(", ");
    Serial.print(OC_Voltage2, 2);
    Serial.print(", ");
    Serial.print(Current2, 2);
    Serial.print(", ");
     // Serial.print("\n"); // comment it while serial communication
  digitalWrite(RELAY_2, LOW);
  delay(3000);

  digitalWrite(RELAY_3, HIGH);
  delay(5000);
 // Measure the voltage for 3rd array
  float Vol_sen3 = getAnalogReading(A1) * REFERENCE_VOLTAGE / 1023.0;
  float Voltage3 = Vol_sen3* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the open circuit voltage for 3rd array
  float Open_Vol_sen3 = getAnalogReading(A2) * REFERENCE_VOLTAGE / 1023.0;
  float OC_Voltage3 = Open_Vol_sen3* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the current for 3rd array
  float Current3 = (getAnalogReading(A0) * (REFERENCE_VOLTAGE / 1023.0*1000) - SENSOR_CALIBRATION_VREF) * SENSOR_CALIBRATION_SENSITIVITY;
  delay(1000);
  // Print the values
   Serial.print(Voltage3, 2);
    Serial.print(", ");
    Serial.print(OC_Voltage3, 2);
    Serial.print(", ");
    Serial.print(Current3, 2);
    Serial.print(", ");
  //Serial.print("\n"); // comment it while serial communication
  digitalWrite(RELAY_3, LOW);
  delay(3000);

  digitalWrite(RELAY_4, HIGH);
  delay(5000);
   // Measure the voltage for 4th array
  float Vol_sen4 = getAnalogReading(A1) * REFERENCE_VOLTAGE / 1023.0;
  float Voltage4 = Vol_sen4* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the open circuit voltage for 4th array
  float Open_Vol_sen4 = getAnalogReading(A2) * REFERENCE_VOLTAGE / 1023.0;
  float OC_Voltage4 = Open_Vol_sen4* SENSOR_READING_MULTIPLIER;
  delay(1000);
  // Measure the current for 4th array
  float Current4 = (getAnalogReading(A0) * (REFERENCE_VOLTAGE / 1023.0*1000) - SENSOR_CALIBRATION_VREF) * SENSOR_CALIBRATION_SENSITIVITY;
  delay(1000);
    // Print the values
   Serial.print(Voltage4, 2);
    Serial.print(", ");
    Serial.print(OC_Voltage4, 2);
    Serial.print(", ");
    Serial.print(Current4, 2);
    Serial.print(", ");
    //  Serial.print("\n"); // comment it while serial communication
  digitalWrite(RELAY_4, LOW);
  delay(3000);


}
