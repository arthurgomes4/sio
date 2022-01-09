/*
created by Arthur Gomes
date last modified : 5/4/20
*/
#include "sio.h"

sio::sio()
{
}
sio::sio( String Name, Stream *bridge)
{
  this->serialStream = bridge;
  this->serialName = Name;
}
void sio::setSerialMonitor( Stream *bridge = &Serial, bool Status = true)
{
  this->serialMonitorStream = bridge;
  this->serialMonitorStatus = Status;
  serialMonitor("connection set");
}
void sio::serialMonitor(String message)
{
  if (this->serialMonitorStatus == false)
    return;

  String msg;
  msg.concat("[");
  msg.concat(millis() / 1000);
  msg.concat("][");
  msg.concat(this->serialName);
  msg.concat("] >> ");
  msg.concat(message);
  msg.concat("\n\r");

  this->serialMonitorStream->print(msg);
}
void sio::writeToSerial( String message )
{
  this->serialStream->print(message);
}
String sio::readFromSerial( int timeout = -1 )
{
  int initial = millis();
  while (true)
  {
    if (this->serialStream->available())
    {
      String msg;
      while (this->serialStream->available())
      {
        msg.concat((char)this->serialStream->read());
        delay(2);
      }
      return msg;
    }
    else if (millis() - initial > timeout && timeout > 0)
    {
      return "\0";

    }
  }
}
String sio::readFromSerialMonitor( int timeout = -1)
{
  int initial = millis();
  while (true)
  {
    if (this->serialMonitorStream->available())
    {
      String msg;
      while (this->serialMonitorStream->available())
      {
        msg.concat((char)this->serialMonitorStream->read());
        delay(2);
      }
      return msg;
    }
    else if (millis() - initial > timeout && timeout > 0)
    {
      return "\0";

    }
  }
}
void sio::toggleSerialMonitorStatus( String key )
{
  String msg = this->readFromSerialMonitor( 1 );
  if( msg == key && this->serialMonitorStatus == true )
  this->serialMonitorStatus = false;
  else if( msg == key && this->serialMonitorStatus == false )
  this->serialMonitorStatus = true;
 }
