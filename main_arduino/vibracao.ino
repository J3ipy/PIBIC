#include "vibracao.h"

const int pinoSensor = A5; // PINO DIGITAL UTILIZADO PELO SENSOR

void setupVibracao() {
    Serial.begin(9600); // INICIALIZA A SERIAL
}

void loopVibracao() {
    Serial.println(" ");
    Serial.print("Range do KY-031: ");
    Serial.print(analogRead(pinoSensor)); // Lendo a porta A0 do Arduino pela comunicação serial
    delay(2000); // Delay de 2s
}
