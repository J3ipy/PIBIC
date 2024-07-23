#include "turbidez.h"

void setupTurbidez() {
  Serial.begin(9600); // INICIALIZA A SERIAL
  pinMode(sensorPin, INPUT); // CONFIGURA O PINO COMO ENTRADA
}

void loopTurbidez() {
  float NTU = lerTurbidez();

  Serial.println(" ");
  Serial.print("Turbidez (NTU): ");
  Serial.print(NTU);

  if (estaSuja(NTU)) {
    Serial.println(" | Água Suja");
  } else {
    Serial.println(" | Água Limpa");
  }

  delay(2000); // Aguarde 2 segundos antes da próxima leitura
}

float lerTurbidez() {
  int sensorValue = analogRead(sensorPin); // Lê o valor analógico do sensor
  float voltage = sensorValue * (5.0 / 1023.0); // Converte a leitura para tensão (0-5V)
  float NTU = voltage * 100; // Converte a tensão para NTU (ajuste conforme necessário)
  return NTU;
}

bool estaSuja(float NTU) {
  return NTU > threshold;
}
