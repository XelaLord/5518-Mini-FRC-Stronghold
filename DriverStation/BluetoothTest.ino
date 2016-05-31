#import <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 12); //Position 1: RX, Position 2: TX



void ReadLine() {
  
  }

void setup()
{
  Serial.begin(9600);
  Bluetooth.begin(9600);
  Serial.println("Coms Started");
}

void loop()
{
  Serial.println("Starting Main Loop");
  int i = 0;
  String t[l];
  boolean recording = false;
  String alphabet[] = {"a","b","c","d","e"};
  String buffer="";
  
  while(Bluetooth.available()>0) {
    //Serial.println("Bluetooth Available");
    Serial.println("Data:");
    
    do {
      t[i] = Bluetooth.read();
      i++;
      for (int a=0;a<5;a++){
        if(t[i] = alphabet[a]) {
          buffer="";
          recording = true;
        }
      }
      
      if(t[i] = ";"){
        recording = false;
      }
      
      if(recording=true) {
        buffer += t[i]
      }
    } while (recording)
   
      //delay(500); //optional delay
      Serial.print(buffer)
  }
  
}
