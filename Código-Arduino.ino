const int pinoSensor = A0; //PINO DIGITAL UTILIZADO PELO SENSOR

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
}
 
void loop(){
  Serial.print("{\"Pac\":"); //Determinador para salvar no mysql pelo node-red
 Serial.print(analogRead(pinoSensor)); //lendo a porta A0 do arduino pela comunicação serial
 Serial.println("}");
 delay(2000); //delay de 2s
}
