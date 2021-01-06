// Include the Servo library 
#include "esp32_Servo.h" 


//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;


int servoPin = 13;
Servo myservo;  // create servo object to control a servo

void setup() {
  Serial.begin(115200);

  myservo.attach(servoPin);  // attaches the servo on the servoPin to the servo object
  myservo.write(0); 
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {

  // Make servo go to 0 degrees 
  /*
   myservo.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   myservo.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   myservo.write(180); 
   delay(1000); */
   
  if (Serial.available()) {
    char ch = Serial.read();

    if(ch == '0') // close
    {
      for(int i = 0; i < 90; i++)
      {
        myservo.write(90-i);
        delay(10);
      }
    }
    if(ch == '1') // open
    {
      for(int i = 0; i < 90; i++)
      {
        myservo.write(i);
        delay(10);
      }      
    }
    
    // SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    char ch = SerialBT.read();

    if(ch == '0') // close
    {
      for(int i = 0; i < 90; i++)
      {
        myservo.write(90-i);
        delay(10);
      }
    }
    if(ch == '1') // open
    {
      for(int i = 0; i < 90; i++)
      {
        myservo.write(i);
        delay(10);
      }      
    }    
    // Serial.write(SerialBT.read());
  }
  delay(20);
}
