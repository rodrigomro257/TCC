#include <LiquidCrystal.h> // BIBLIOTECA DO LCD.
#include "automato.h"

#define btn_0 0
#define btn_1 1
#define btn_2 2
#define btn_3 3
#define btn_4 4

#define btn_ok 5

#define led_ok 6
#define led_nok 7

#define led_0 8
#define led_1 9
#define led_2 10
#define led_3 11
#define led_4 12

int lcd_14=14;
int lcd_13=15;
int lcd_12=16;
int lcd_11=17;
int lcd_6=18;
int lcd_4=19;

LiquidCrystal lcd(lcd_4, lcd_6, lcd_11, lcd_12, lcd_13, lcd_14); // PINOS DO LCD.

void setup(){
  lcd.begin(16, 2); // INICIA O LCD 16x2.
  // DEFINE BOTÕES COMO ENTRADA.
  pinMode(btn_0, INPUT);
  pinMode(btn_1, INPUT);
  pinMode(btn_2, INPUT);
  pinMode(btn_3, INPUT);
  pinMode(btn_4, INPUT);
  pinMode(btn_ok, INPUT);
  // DEFINE LEDS COMO SAÍDA.
  pinMode(led_0, OUTPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_ok, OUTPUT);
  pinMode(led_nok, OUTPUT);
  // DEFINE AS PORTAS ANALÓGICAS COMO SAÍDAS DIGITAIS PARA O LCD.
  pinMode(lcd_4, OUTPUT);
  pinMode(lcd_6, OUTPUT);
  pinMode(lcd_11, OUTPUT);
  pinMode(lcd_12, OUTPUT);
  pinMode(lcd_13, OUTPUT);
  pinMode(lcd_14, OUTPUT);
}

void loop(){
  maquina_estados();
}

