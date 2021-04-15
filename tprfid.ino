#include <SoftwareSerial.h>
#include <LoRaWan.h>

SoftwareSerial rfid(10,11);
char d;
unsigned char buf[64];
char buffer[256];
int count = 0;
String str = "";

void setup() {
  Serial.begin(9600);
  while(!Serial){}
  rfid.begin(9600);
  lora.init();
 
  memset(buffer, 0, 256);
  lora.getVersion(buffer, 256, 1);
  SerialUSB.print(buffer); 
  memset(buffer, 0, 256);
  lora.getId(buffer, 256, 1);
  Serial.print(buffer);
 
  lora.setKey("2B7E151628AED2A6ABF7158809CF4F3C", "2B7E151628AED2A6ABF7158809CF4F3C", "2B7E151628AED2A6ABF7158809CF4F3C");
 
  lora.setDeciveMode(LWABP);
  lora.setDataRate(DR0, EU868);
 
  lora.setChannel(0, 867.7);
  lora.setChannel(1, 867.9);
  lora.setChannel(2, 868.8);
 
  lora.setReceiceWindowFirst(0, 867.7);
  lora.setReceiceWindowSecond(869.5, DR3);
  lora.setDutyCycle(false);
  lora.setJoinDutyCycle(false);
 
  lora.setPower(14); 
}

void loop() {
  if(rfid.available()){
    while(rfid.available()) {
      d = rfid.read();
      if(d==0x03) {}
      else {
        if(d!=0x02) {
          buf[count++] = d;
        }
      }
    }
    Serial.print("ID: ");
    Serial.write(buf,count);
    Serial.print("");
    lora.transferPacket(buf, count, 10);
    for(int j = 0; j<count; j++){
      buf[j] = NULL;
    }
    count = 0;
  }
}
