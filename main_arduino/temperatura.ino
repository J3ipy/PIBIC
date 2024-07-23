#include "temperatura.h"

OneWire oneWire(ONE_WIRE_BUS);        // Objeto OneWire
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

float tempMin = 999;   // Armazena temperatura mínima
float tempMax = 0;     // Armazena temperatura máxima

void setupTemperatura() {
    Serial.begin(9600);
  
    sensors.begin();
  
    // Localiza e inicializa o sensor
    Serial.println("Localizando sensores DS18B20...");
    Serial.print("Foram encontrados ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" sensores.");
  
    if (!sensors.getAddress(sensor1, 0)) 
        Serial.println("Sensores nao encontrados!"); 
}

void loopTemperatura() {
    // Lê a informação do sensor
    sensors.requestTemperatures();
    float tempC = sensors.getTempC(sensor1);
  
    // Atualiza temperaturas mínima e máxima
    if (tempC < tempMin) {
        tempMin = tempC;
    }
    if (tempC > tempMax) {
        tempMax = tempC;
    }
  
    // Mostra dados no serial monitor
    Serial.println(" ");
    Serial.print("Temperatura Celsius: ");
    Serial.print(tempC);
    Serial.print(" Min: ");
    Serial.print(tempMin);
    Serial.print(" Max: ");
    Serial.println(tempMax);
   
    delay(2000);
}
