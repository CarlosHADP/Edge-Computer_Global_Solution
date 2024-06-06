// Global Solution 

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

const int ledVermelho = 9;
const int ledAmarelo = 8;
const int ledVerde = 7;
const int luzFundo = 13;
int valorGas;


void setup()
{
  Serial.begin(9600);
  
  lcd.begin(16,2);
  pinMode (luzFundo, OUTPUT);
  digitalWrite(luzFundo, HIGH);
  lcd.setCursor(2,0);
  lcd.print("Monitorando");
  lcd.setCursor(5,1);
  lcd.print("Gases");
  delay(1500);
  
  pinMode (ledAmarelo, OUTPUT);
  pinMode (ledVermelho, OUTPUT);
  pinMode (ledVerde, OUTPUT);
}

void loop(){
  valorGas = analogRead(A0);
  valorGas = map(valorGas, 306, 757, 0, 100);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print((0 <= valorGas && valorGas <= 33)? "Estado Normal":
            ( 34 <= valorGas && valorGas <= 66)? "Estado Alerta":
            "Estado Grave");
  lcd.setCursor(2,1);
  lcd.print("Valor Gas: ");
  lcd.print(valorGas);
  delay(1000);
  if (0 <= valorGas && valorGas <= 33)
  {
    digitalWrite(ledVerde,HIGH);
    digitalWrite(ledAmarelo,LOW);
    digitalWrite(ledVermelho,LOW);
  }else if ( 34 <= valorGas && valorGas <= 66)
  {
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledAmarelo,HIGH);
    digitalWrite(ledVermelho,LOW);
  }else
  {
    digitalWrite(ledVerde,LOW);
    digitalWrite(ledAmarelo,LOW);
    digitalWrite(ledVermelho,HIGH);
  }
   delay(500);
}