#include "thingProperties.h"
int LED = 2;
int Temp_Pin = 32;
int turb = 26;
void print_Value();
void setup() {
// Initialize serial and wait for port to open:
pinMode(LED, OUTPUT);
// pinMode(Temp_Pin,OUTPUT);
pinMode(turb,OUTPUT);
Serial.begin(9600);
// This delay gives the chance to wait for a Serial Monitor without blocking if none is found
delay(1500);
// Defined in thingProperties.h
initProperties();
// Connect to Arduino IoT Cloud
ArduinoCloud.begin(ArduinoIoTPreferredConnection);
/*
The following function allows you to obtain more information
related to the state of network and IoT Cloud connection and errors
the higher number the more granular information you’ll get.
The default is 0 (only errors).
Maximum is 4
*/
setDebugMessageLevel(2);
ArduinoCloud.printDebugInfo();
}
void loop() {
ArduinoCloud.update();
// Your code here
delay(500);
delay(10000);
int adc_val = analogRead(Temp_Pin);
float milliVolt = adc_val * (3300.0 / 3096.0);
float tempC = milliVolt/10;
temp = tempC;
float turb_value = analogRead(turb);
float turb_volt = turb_value* (5.0 /1024.0);
turbidity = turb_volt;
turbidity = 4.32;
turbidity = -1120.4*turb_volt*turb_volt+5742.3*turb_volt - 4352.9;
if(turbidity <= 1)
ph_value = 7;
else if(turbidity>100)
ph_value = 12;
else
ph_value = 5;
print_Value();
}
/*
Since LED is READ_WRITE variable, onLEDChange() is
executed every time a new value is received from IoT Cloud.
*/
void onLEDChange() {
// Add your code here to act upon LED change
analogWrite(LED, lED); // maximum brightness (100%)
delay(2000);
}
