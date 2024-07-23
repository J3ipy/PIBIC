#ifndef TURBIDEZ_H
#define TURBIDEZ_H

const int sensorPin = A0; // PINO ANALÓGICO UTILIZADO PELO SENSOR
const float threshold = 50.0; // Limiar de turbidez para água suja ou limpa

void setupTurbidez();
void loopTurbidez();

float lerTurbidez();
bool estaSuja(float NTU);

#endif
