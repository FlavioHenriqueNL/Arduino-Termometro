#include <LCD5110_Basic.h>
#include <DHT.h>

#define DHTPIN 7
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

/*Cria objeto da classe LCD5110
CLK – Pino 8
DIN – Pino 9
DC – Pino 10
RST – Pino 12
CE – Pino 11
*/
LCD5110 tela(8,9,10,12,11);

//Obtendo as fontes
extern uint8_t SmallFont[];
extern uint8_t MediumNumbers[];
extern uint8_t BigNumbers[];

void setup() {
  dht.begin();
  tela.InitLCD();
  Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:

  float umidade = dht.readHumidity();
  double temperatura = dht.readTemperature();
 
  Serial.println("==============================");
  Serial.println(temperatura);
  Serial.println(umidade);
  Serial.println("==============================");


  if(isnan(temperatura) || isnan(umidade)){
    tela.setFont(SmallFont);
    tela.print("Falha ao ler o sensor.", LEFT, 0);
  }else{
    tela.setFont(SmallFont);

    tela.print("Umidade: ", LEFT, 10);
    tela.printNumF(umidade,2, RIGHT, 10);
    tela.print("Temp: ", LEFT, 35);
    tela.printNumF(temperatura,2, RIGHT, 35);
    //tela.clrScr();
  }
 
}
