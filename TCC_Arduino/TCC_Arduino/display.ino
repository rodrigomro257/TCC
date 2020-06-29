#include "display.h"

void exibir_lcd_monta_automato(){
    lcd.setCursor(0,0);
    lcd.print("MONTE O AUTOMATO");
    lcd.setCursor(0,1);
    lcd.print((char)matriz[numero_transicao][0]);
    lcd.setCursor(2,1);
    lcd.print((char)matriz[numero_transicao][1]);
    lcd.setCursor(4,1);
    lcd.print((char)matriz[numero_transicao][2]);
    lcd.setCursor(10,1);
    lcd.print(numero_transicao);
    //lcd.setCursor(7,1);
    //lcd.print("transicao");
}

void exibir_lcd_define_finais(){
  lcd.setCursor(0,0);
  lcd.print("DEFINA OS FINAIS");
  lcd.setCursor(0,1);
  lcd.print("Finais ");
  lcd.setCursor(7,1);
  lcd.print(estados_finais[0]);
  lcd.setCursor(9,1);
  lcd.print(estados_finais[1]);
  lcd.setCursor(11,1);
  /*
  lcd.print(estados_finais[2]);
  lcd.setCursor(13,1);
  lcd.print(estados_finais[3]);
  lcd.setCursor(15,1);
  lcd.print(estados_finais[4]);
  */
}

void exibir_lcd_insere_palavra(){
  lcd.setCursor(0,0); // COLUNA 0, LINHA 0.
  lcd.print("INSIRA A PALAVRA"); // IMPRIME TEXTO.
  for(int i=0; i<16; i++){
    lcd.setCursor(i,1);
    lcd.print(palavra[i]);
  }
}

void exibir_lcd_confirma_palavra(){
    lcd.setCursor(0,0); // COLUNA 0, LINHA 0.
    lcd.print("    PALAVRA     "); // IMPRIME TEXTO.
    lcd.setCursor(0,1); // COLUNA 0, LINHA 1.
    if(flag_nok==false) lcd.print("    VALIDA      "); // IMPRIME TEXTO.
    if(flag_nok==true) lcd.print("    INVALIDA    "); // IMPRIME TEXTO.
}

