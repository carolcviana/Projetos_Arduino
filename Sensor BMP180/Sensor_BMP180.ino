#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;

#define ALTITUDE 920.0 //Altitude do local

void setup() {
  Serial.begin(9600); //Inicialização da comunicação serial
  pressure.begin(); //Inicialização do sensor BMP180
}

void loop() {

  char status;
  double T, P, p0, a;

  //Temperatura em ºC
  status = pressure.startTemperature();
  status = pressure.getTemperature(T);
  Serial.print("Temperatura: ");
  Serial.print(T);
  Serial.println(" ºC");

  //Pressão Absoluta em hPa
  status = pressure.startPressure(3);
  status = pressure.getPressure(P, T);
  Serial.print("Pressão Absoluta: ");
  Serial.print(P);
  Serial.println(" hPa");

  //Pressão Relativa em hPa
  p0 = pressure.sealevel(P, ALTITUDE);
  Serial.print("Pressão Relativa: ");
  Serial.print(p0);
  Serial.println(" hPa");

  //Altitude calculada em m
  a = pressure.altitude(P, p0);
  Serial.print("Altitude Calculada: ");
  Serial.print(a);
  Serial.println(" m");

  delay(100);
}
