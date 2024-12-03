#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <IRremote.hpp>

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);        //Starts the receiver
}

void loop() {
  if (IrReceiver.decode()) {                                    //Checks if data was received
    IrReceiver.printIRResultShort(&Serial);                     //Prints received data to serial monitor
    Serial.println();
    if (IrReceiver.decodedIRData.address == 0) {                
      Serial.print("Execute command");                          //Replace with any command (stop/start car)
      Serial.println();
    }
  }
  IrReceiver.resume();
}
