#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 3  // Sinal do sensor de temperatura DS18B20

extern OneWire oneWire;
extern DallasTemperature sensors;
extern DeviceAddress sensor1;

void setupTemperatura();
void loopTemperatura();

extern float tempMin;
extern float tempMax;

#endif
