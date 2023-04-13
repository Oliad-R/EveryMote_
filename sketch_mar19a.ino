#include <IRremote.hpp>

#define LED_PIN 3
#define BUTTON_PIN_1 7
#define BUTTON_PIN_2 8
#define BUTTON_PIN_3 9
#define BUTTON_PIN_4 10
String TV;
String tvList[3] = {"Panasonic", "LG", "Samsung"};

void setup() {
  Serial.begin(9600);
  TV = "Panasonic";
  IrSender.begin(LED_PIN);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
}

void loop() {
  if(digitalRead(BUTTON_PIN_4)== HIGH){
    if (TV.equals(tvList[2])){
      TV = tvList[0];
    }
    else{
       if(TV.equals(tvList[0])){
        TV = tvList[1];
       }
       else if(TV.equals(tvList[1])){
        TV = tvList[2];
       }
     }
    delay(2000);
    Serial.println("TV:"+TV);
    digitalWrite(BUTTON_PIN_4, LOW);
  }
  if(TV=="Panasonic"){
    if(digitalRead(BUTTON_PIN_1) == HIGH) {
      Serial.println("ON/OFF PRESSED");
      IrSender.sendPanasonic(8, 61, 2);
      digitalWrite(BUTTON_PIN_1, LOW);
      }
    else if(digitalRead(BUTTON_PIN_2) == HIGH) {
      Serial.println("VOL + PRESSED");
      IrSender.sendPanasonic(8, 32, 3);
      digitalWrite(BUTTON_PIN_2, LOW);
      }
    else if(digitalRead(BUTTON_PIN_3) == HIGH) {
      Serial.println("VOL - PRESSED");
      IrSender.sendPanasonic(8, 33, 3);
      digitalWrite(BUTTON_PIN_3, LOW);
      }
  }
  else if(TV=="LG") {
     if (digitalRead(BUTTON_PIN_1) == HIGH) {
      Serial.println("ON/OFF PRESSED");
      IrSender.sendNEC(4, 8, 3);
      digitalWrite(BUTTON_PIN_1, LOW);
      }
    else if(digitalRead(BUTTON_PIN_2) == HIGH) {
      Serial.println("VOL + PRESSED");
      IrSender.sendNEC(4, 2, 3);
      digitalWrite(BUTTON_PIN_2, LOW);
      }
    else if(digitalRead(BUTTON_PIN_3) == HIGH) {
      Serial.println("VOL - PRESSED");
      IrSender.sendNEC(4, 3, 3);
      digitalWrite(BUTTON_PIN_3, LOW);
      }
  }
}
