/*
created by: Arthur Gomes
date last modified: 29/3/20
*/
#ifndef SIO_H
#define SIO_H
#include "Arduino.h"
class sio
{
protected:
    bool serialMonitorStatus = false;
    String serialName;
    Stream *serialStream;
    Stream *serialMonitorStream = &Serial;
public:
    sio( void );
    sio(String Name, Stream *bridge);
    void setSerialMonitor(Stream *bridge = &Serial, bool Status = true);
    void serialMonitor(String message);
    void writeToSerial( String message );
    String readFromSerial( int timeout = -1 );
    String readFromSerialMonitor( int timeout = -1);
    void toggleSerialMonitorStatus( String key );
};
#endif
