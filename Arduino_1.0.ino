#include <Adafruit_Sensor.h>                       // Biblioteca DHT Sensor Adafruit 
#include <DHT.h>
#include <DHT_U.h>
 
#define DHTTYPE      DHT22                       // Sensor DHT22 ou AM2302
 
#define DHTPIN 2                                   // Pino do Arduino conectado no Sensor(Data) 
DHT_Unified dht(DHTPIN, DHTTYPE);   // configurando o Sensor DHT - pino e tipo

const int sensorChuva = A0; //pino do sensor de chuva
 
void setup()
{
  Serial.begin(9600);   // monitor serial 9600 bps
  dht.begin();   // inicializa a função do sensor DHT

  pinMode(sensorChuva, INPUT); //define o pino como entrada de dados
}
 
void loop()
{
  delay(3000); // atraso entre as medições

  int valorSensorChuva = analogRead(sensorChuva); // fazendo a leitura do Sensor de chuva
  
  sensors_event_t event; // inicializa o evento da Temperatura
  dht.temperature().getEvent(&event); // faz a leitura da Temperatura
  
  if (isnan(event.temperature)) // se ocorrer algum erro na leitura da temperatura
  {
    Serial.println("Erro na leitura");
  }
  else
  {
    Serial.print(event.temperature); Serial.print("C "); // escreve as informações da temperatura
  }
  dht.humidity().getEvent(&event); // faz a leitura de Umidade
  
  if (isnan(event.relative_humidity)) // se ocorrer algum erro na leitura da umidade
  {
    Serial.println("Erro na leitura");
  }
  else
  {
    Serial.print(event.relative_humidity); Serial.print("% "); // escreve as informações da umidade
    Serial.println(valorSensorChuva); // escreve a resistência registrada pelo sensor de chuva
  }
}
