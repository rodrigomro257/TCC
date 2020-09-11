#include <LiquidCrystal.h> // BIBLIOTECA DO LCD.
#include <Servo.h>
#include "automato.h"

#define btn_0  2
#define btn_1  3
#define btn_2  4
#define btn_3  5
#define btn_4  6
#define btn_ok 7
#define motor0 8
#define motor1 9
#define motor2 10
#define motor3 11
#define motor4 12
#define buzzer 13
#define lcd_14 14
#define lcd_13 15
#define lcd_12 16
#define lcd_11 17
#define lcd_6  18
#define lcd_4  19

LiquidCrystal lcd(lcd_4, lcd_6, lcd_11, lcd_12, lcd_13, lcd_14); // PINOS DO LCD.

Servo motor_0;
Servo motor_1;
Servo motor_2;
Servo motor_3;
Servo motor_4;
int pos=0;

void setup(){
  // DEFINE BOTÕES COMO ENTRADA.
  pinMode(btn_0, INPUT);
  pinMode(btn_1, INPUT);
  pinMode(btn_2, INPUT);
  pinMode(btn_3, INPUT);
  pinMode(btn_4, INPUT);
  pinMode(btn_ok, INPUT);
  // DEFINE MOTORES COMO SAÍDA.
  motor_0.attach(motor0);
  motor_1.attach(motor1);
  motor_2.attach(motor2);
  motor_3.attach(motor3);
  motor_4.attach(motor4);
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

