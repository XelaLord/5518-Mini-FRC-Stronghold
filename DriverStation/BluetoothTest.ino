#import <SoftwareSerial.h>

SoftwareSerial Bluetooth(3, 12); //Position 1: RX, Position 2: TX

boolean recording = false;

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
  int l = 52;
  String t[l];
  while(Bluetooth.available()>0) {
    Serial.println("Bluetooth Available");
    Serial.println("Data:");
    for(int i=0; i<l-1; i++) {
      t[i] = Bluetooth.read();
      Serial.print(t[i]); 
    }
    
    /*if(1=0){
      Serial.println("Bluetooth Available");
      static char Abuffer[2];
      for (int i=0; i<1; i++) {
        Abuffer[i] = Bluetooth.read();
        Serial.println("Data:" + Abuffer[i]);
      }*/
      if (readline(Bluetooth.read(), t, 9) > 0) {
        Serial.print("You entered: >");
        Serial.print(t);
        Serial.println("<");
      }
      //delay(500);  
    /*}*/
  }
  
}
