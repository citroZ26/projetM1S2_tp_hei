char d;
String str;
int i;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("RFID Test..");
}

void loop() { 

  if(Serial1.available()){
    d = Serial1.read();
   if(d==0x03){
    i=0;
    Serial.println();
   }
   else{
    if(d!=0x02){
    Serial.print(d);
    str = Serial.readString();

 
   // test = Serial.readString();
    }
    Serial.print(str);
   }
  
   //Serial.print("Test");
  // Serial.print(test);
  }
  
}
