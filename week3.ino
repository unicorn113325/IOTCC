#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(8,9);
int LED = 13;
int Data;
void setup() {
  Bluetooth.begin(9600);
  Serial.begin(9600);
  Serial.println("Waiting for command...");
  Bluetooth.println("Send 1 to turn on the LED. send 0 to turn off");
  pinMode(LED,OUTPUT);

}

void loop() {
  if (Bluetooth.available()){
Data=Bluetooth.read();
  if(Data=='1'){
digitalWrite(LED,HIGH);
Serial.println("LED On!");
Bluetooth.println("LED On!");
  }
  else if(Data=='0'){
digitalWrite(LED,LOW);
  Serial.println("LED off!");
Bluetooth.println("LED off!");
  }
  else{;}
  }
delay(1000);
}   


