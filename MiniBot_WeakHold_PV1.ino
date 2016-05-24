//Imports
#include <SPI.h>              // needed for Arduino versions later than 0018
#include <AFMotor.h>          //Adafruit Motor Sheild
#include <SoftwareSerial.h>   //Replicates the serial port for the Bluetooth Module

//--Variables--
//Drive Motors
AF_DCMotor motorR(1);   
AF_DCMotor motorL(2);  

//Serial Communication

//Bluetooth Definition
SoftwareSerial Bluetooth(14, 15); //Position 1: RX, Position 2: TX
int noSignal = 0;

//Driverstation Variables
int intInputNum = 4;        //Make sure that this value matches those that are below
float DSInput[4];           //Controller input is put here
String DSInputName[4]={"Zero Axis", "First Axis", "Second Axis", "Third Axis"};      //Names of the input channels are put here

//Special Function Variables
AF_DCMotor motor3(3);   //Make sure to come back and make names better later
AF_DCMotor motor4(4);   //Make sure to come back and make names better later

//Diagnostics
int intALEDLowValue = 0;
boolean blnDiagnostics = true;  //True = More serial output False = Less serial output

//LED's
int intALEDHighValue = 255;
int intALEDLowValue = 0;

//MSC Variables


//--Functions and Methods--
//Drive Methods
void DriveMotorR(float fltSpeed, boolean blnDirection) { //Not sure if the string part is going to work
  String strDir = "";
  motorR.setSpeed(fltSpeed);
  if(blnDirection) {
    motorR.run(FORWARD); //Not sure if this is going to work
    strDir = "FORWARD";
  }
  else {
    motorR.run(BACKWARD); //Not sure if this is going to work
    strDir = "BACKWARD");
  }

  if (blnDiagnostics) {
    Serial.println("--Right Motor Running Speed: " += fltSpeed += " Direction: " += strDir += " --"; 
  }
}

void DriveMotorL(float fltSpeed, boolean blnDirection) { //Not sure if the string part is going to work
  String strDir = "";
  motorL.setSpeed(fltSpeed);
  if(blnDirection) {
    motorL.run(FORWARD); //Not sure if this is going to work
    strDir = "FORWARD":
  }
  else {
    motorL.run(BACKWARD); //Not sure if this is going to work
    strDir = "BACKWARD";
  }

  if (blnDiagnostics) {
    Serial.println("--Left Motor Running; Speed: " += fltSpeed += "; Direction: " += strDir += " --";
  }
}

void Drive(){

  if (blnDiagnostics) {
    
  }
}

//Special Functions Methods
void Shooter() {

  if (blnDiagnostics) {
    
  }
}

void Intake() {
  
  if (blnDiagnostics) {
    
  }
}

void Lifter() {
  
  if (blnDiagnostics) {
    
  }
}

//Communication Methods
void SerialCommunication(){ //Finish
  if (blnDiagnostics) {
    
  }
}

void GetVaraibles(){
  DSInput[0] = bluetooth.parseFloat(); //Get 1st position of serial buffer (Zero Axis)
  DSInput[1] = bluetooth.parseFloat(); //Get 2nd position of serial buffer (One Axis)
  DSInput[2] = bluetooth.parseFloat(); //Get 3rd position of serial buffer (Two Axis)
  DSInput[3] = bluetooth.parseFloat(); //Get 4th position of serial buffer (Three Axis)
    
  if (blnDiagnostics) {
    Serial.println("-----Serial Values Coming From Driver Station-----");
    for (int x = 0; x < intInputNum; x++){
      char Buffer[25]; 
      Serial.println(AxisandDSValue(DSInputName[x], floatToString(Buffer, DSInput[x], 5));  //Not sure if this conversion can work
    }
  }
}

void NoBluetoothCommunication() {
  Serial.println("--NO BLUETOOTH--");
  noSignal += 1;
  if (noSignal > 40){
    noSignal = 0;    //if you have over 3 seconds of packet loss, the robot will stop moving.
    DriveMotorR(0, true);  //Not sure if this actually can work
    DriveMototL(0, true);  //Note sure if this actually can work  
  }
  delay(40); // delay for 60ms for rough timing on the packet loss shutdown
  if (blnDiagnostics) {
    
  }
}

//Diagnostic Methods
String AxisandDSValue(String strAxis, String strCV) {
  string result;
  result = strAxis += ": " += strCV;
  return result;
}

//--Initial Setup Code--
void setup()  {
  //--Start Communications--
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Serial.println("-----Communication Started!-----");
  
  //--Initalize Outputs--
  //LED's

  Serial.println("-----Outputs Initalized-----");
  
  //--Initialize Car Default State--
  //Drive Motors
  DriveMotorR(0, true);  //Not sure if the string part of this is going to work
  DriveMotorL(0, true); //Not sure if the string part of this is going to work
  Serial.println("-----Robot Initalized and Ready to Go!-----");
}

//--Primary Loop--
void loop()  {
  //Bluetooth connection determines path of main loop
  while(Bluetooth.available()>0){
    GetVaraibles();
    //Finish code to actually drive the robot and do the math for tank drive
    Drive();
    Intake();
    Shooter();
    Lifter();
   }

  //The following runs if there is no bluetooth connection
  NoBluetoothCommunication();
}
 
