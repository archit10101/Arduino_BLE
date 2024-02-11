#include <ArduinoBLE.h>

BLEService myService("19b10000-e9f3-537e-4f6c-d104768a1214");
BLEStringCharacteristic intensityCharacteristic("19b10001-e9f3-537e-4f6c-d104768a1214", BLEWrite | BLERead, 20);
BLEStringCharacteristic pulseWidthCharacteristic("19b10002-e9f3-537e-4f6c-d104768a1214", BLEWrite | BLERead, 20);
BLEStringCharacteristic frequencyCharacteristic("19b10003-e9f3-537e-4f6c-d104768a1214", BLEWrite | BLERead, 20);
BLEStringCharacteristic startCharacteristic("19b10004-e9f3-537e-4f6c-d104768a1214", BLEWrite | BLERead, 20);

String intensity = "";
String frequency = "";
String pulseWidth = "";
String start = "";

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud

  if (!BLE.begin()){
    while(1);
  }

// Establishes connection and adds characteristics
  BLE.setLocalName("myXiao");
  BLE.setAdvertisedService(myService);
  myService.addCharacteristic(intensityCharacteristic);
  myService.addCharacteristic(pulseWidthCharacteristic);
  myService.addCharacteristic(frequencyCharacteristic);
  myService.addCharacteristic(startCharacteristic);
  BLE.addService(myService);
  BLE.advertise();
  Serial.println("restarted");

}

void loop() {
  // Creates ble device
  BLEDevice central = BLE.central();
  if (central) {

// Connected. Waiting for data.
    Serial.println("firstCentral");

    while (central.connected()){

      if (intensityCharacteristic.written()){
        intensity = intensityCharacteristic.value();
        Serial.println("Intensity: "+intensity);
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
        delay(200);                      // wait for a second
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage LOW



      }

      if (pulseWidthCharacteristic.written()){
        pulseWidth = pulseWidthCharacteristic.value();
        Serial.println("PulseWidth: " + pulseWidth);
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
        delay(200);                      // wait for a second
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage LOW

      }

      if (frequencyCharacteristic.written()){
        frequency = frequencyCharacteristic.value();
        Serial.println("Frequency: "+frequency);
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
        delay(200);                      // wait for a second
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage LOW

      }

      if (startCharacteristic.written()){
        start = startCharacteristic.value();
        Serial.println("Start: "+start);
        digitalWrite(LED_BUILTIN, LOW);  // turn the LED on (HIGH is the voltage level)
        delay(200);                      // wait for a second
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED off by making the voltage LOW

      }
    }
  }
}
