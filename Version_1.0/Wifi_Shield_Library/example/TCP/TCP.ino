#include "Wifly.h"
#include <SoftwareSerial.h>
WiflyClass Wifly(2,3);

void setup()
{
  Serial.begin(9600);
  Wifly.init();
  Wifly.setConfig("SSID","PASSWORD");
  Wifly.join("SSID");
  Wifly.checkAssociated();
  while(!Wifly.connect("192.168.1.164","90"));
  Wifly.writeToSocket("Connected!");
}
void loop()
{
  if(Wifly.canReadFromSocket())
  {
    Wifly.readFromSocket();
  }
  if(Serial.available())
  {
    Wifly.print((char)Serial.read());
  }
}
