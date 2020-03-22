#include <LiquidCrystal.h> // BIBLIOTECA DO LCD.
#include <Servo.h>
#include "automato.h"

#define btn_0 2
#define btn_1 3
//#define btn_2 0
//#define btn_3 1
//#define btn_4 4

#define btn_ok 7

#define buzzer 13

int lcd_14=14;
int lcd_13=15;
int lcd_12=16;
int lcd_11=17;
int lcd_6=18;
int lcd_4=19;

LiquidCrystal lcd(lcd_4, lcd_6, lcd_11, lcd_12, lcd_13, lcd_14); // PINOS DO LCD.

Servo motor_0;
Servo motor_1;
int pos=0;

bool zerar_variaveis=false;

void setup(){
  // DEFINE BOTÕES COMO ENTRADA.
  pinMode(btn_0, INPUT);
  pinMode(btn_1, INPUT);
  //pinMode(btn_2, INPUT);
  //pinMode(btn_3, INPUT);
  //pinMode(btn_4, INPUT);
  pinMode(btn_ok, INPUT);
  // DEFINE MOTORES COMO SAÍDA.
  motor_0.attach(8);
  motor_1.attach(9);
  // DEFINE BUZZER COMO SAÍDA.
  pinMode(buzzer, OUTPUT);
  // DEFINE AS PORTAS ANALÓGICAS COMO SAÍDAS DIGITAIS PARA O LCD.
  lcd.begin(16, 2); // INICIA O LCD 16x2.
  pinMode(lcd_4, OUTPUT);
  pinMode(lcd_6, OUTPUT);
  pinMode(lcd_11, OUTPUT);
  pinMode(lcd_12, OUTPUT);
  pinMode(lcd_13, OUTPUT);
  pinMode(lcd_14, OUTPUT);
  zera_matriz_finais_palavra();
}

void loop(){
  maquina_estados();
}

