#include "automato.h"

void zera_matriz_e_finais(){
  for(int i=0; i<MAX_TRANSICOES; i++){      
    for(int j=0; j<4; j++){
      matriz[i][j]=' ';
    }
  }
  for(int i=0; i<MAX_ESTADOS; i++){
    estados_finais[i]=' ';
  }
}

void verifica_repeticao(){
  for(int i=numero_transicao-1; i>=0; i--){
    if(matriz[numero_transicao][0]==matriz[i][0] && matriz[numero_transicao][1]==matriz[i][1]){
      matriz[numero_transicao][0]=' ';
      matriz[numero_transicao][1]=' ';
      matriz[numero_transicao][2]=' ';
      numero_transicao--;
    }
  }
}

bool valida_token(char token){
  for(int i=0; i<numero_transicao; i++){
    if(matriz[i][0]==estado_atual && matriz[i][1]==token){
      return true;
    }
  }
  // ASCENDE LED VERMELHO E ACUSA ERRO.
  digitalWrite(led_nok, HIGH);
  return false;
}

void desliga_leds(){
  digitalWrite(led_0,   LOW);
  digitalWrite(led_1,   LOW);
  digitalWrite(led_2,   LOW);
  digitalWrite(led_3,   LOW);
  digitalWrite(led_4,   LOW);
  digitalWrite(led_ok,  LOW);
  digitalWrite(led_nok, LOW);
}

bool posicao_atual_eh_final(char estado_atual){
  for(int i=0; i<MAX_ESTADOS; i++){
    if (estados_finais[i]==estado_atual) return true;
  }
  return false;
}

void ascender_led(char transicao){
  for(int i=0; i<=numero_transicao; i++){
    if(matriz[i][0]==estado_atual && matriz[i][1]==transicao){
      estado_atual=matriz[i][2];
      switch(matriz[i][2]){           
        case '0':
          digitalWrite(led_0, HIGH);
        break;        
        case '1':
          digitalWrite(led_1, HIGH);
        break;
        case '2':
          digitalWrite(led_2, HIGH);
        break; 
        case '3':
          digitalWrite(led_3, HIGH);
        break; 
        case '4':
          digitalWrite(led_4, HIGH);
        break; 
      };
      return;
    }
  }
}

void maquina_estados(){
  
  switch(ESTADO){

    case MONTA_AUTOMATO:
      exibir_lcd_monta_automato();
      if(digitalRead(btn_0)==HIGH){
        delay(DEBOUNCE);
        matriz[numero_transicao][posicao_matriz]='0';
        posicao_matriz++;
      }
      if(digitalRead(btn_1)==HIGH){
        delay(DEBOUNCE);
        matriz[numero_transicao][posicao_matriz]='1';
        posicao_matriz++;
      }
      if(digitalRead(btn_2)==HIGH){
        delay(DEBOUNCE);
        matriz[numero_transicao][posicao_matriz]='2';
        posicao_matriz++;
      }
      if(digitalRead(btn_3)==HIGH){
        delay(DEBOUNCE);
        matriz[numero_transicao][posicao_matriz]='3';
        posicao_matriz++;
      }
      if(digitalRead(btn_4)==HIGH){
        delay(DEBOUNCE);
        matriz[numero_transicao][posicao_matriz]='4';
        posicao_matriz++;
      }
      if(posicao_matriz==3){
        exibir_lcd_monta_automato();
        delay(TEMPO_EXIBICAO);
        verifica_repeticao();
        posicao_matriz=0;
        numero_transicao++;
        tem_transicao=true;              
      }
      if(numero_transicao==MAX_TRANSICOES){
        ESTADO=DEFINE_FINAIS;
        lcd.clear();
      }
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        if(posicao_matriz==0 && tem_transicao==true){   
          ESTADO=DEFINE_FINAIS;
          lcd.clear();
        }
      }
    break;
  
    case DEFINE_FINAIS:
      exibir_lcd_define_finais();
      if(digitalRead(btn_0)==HIGH){
        delay(DEBOUNCE);
        if(estados_finais[0]==' ') numero_estados_finais++;
        estados_finais[0]='0';
        tem_estado_final=true;
      }
      if(digitalRead(btn_1)==HIGH){
        delay(DEBOUNCE);
        if(estados_finais[1]==' ') numero_estados_finais++;
        estados_finais[1]='1';
        tem_estado_final=true;
      }
      if(digitalRead(btn_2)==HIGH){
        delay(DEBOUNCE);
        if(estados_finais[2]==' ') numero_estados_finais++;
        estados_finais[2]='2';
        tem_estado_final=true;
      }
      if(digitalRead(btn_3)==HIGH){
        delay(DEBOUNCE);
        if(estados_finais[3]==' ') numero_estados_finais++;
        estados_finais[3]='3';
        tem_estado_final=true;
      }
      if(digitalRead(btn_4)==HIGH){
        delay(DEBOUNCE);
        if(estados_finais[4]==' ') numero_estados_finais++;
        estados_finais[4]='4';
        tem_estado_final=true;
      }
      if(numero_estados_finais==MAX_ESTADOS){
        delay(TEMPO_EXIBICAO);
        ESTADO=INSERE_PALAVRA;
        lcd.clear();
      }
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        if(tem_estado_final){
          ESTADO=INSERE_PALAVRA;
          lcd.clear();
        }
      }
    break;
    
    case INSERE_PALAVRA:
      exibir_lcd_insere_palavra();
      if(digitalRead(led_nok)==LOW){
        if(digitalRead(btn_0)==HIGH){
          delay(DEBOUNCE);
          desliga_leds();
          if(valida_token('0')){
            palavra[tamanho_palavra]='0';
            ascender_led(palavra[tamanho_palavra]);
            tamanho_palavra++;
          }
          else digitalWrite(led_nok, HIGH);
        }
        if(digitalRead(btn_1)==HIGH){
          delay(DEBOUNCE);
          desliga_leds();
          if(valida_token('1')){
            palavra[tamanho_palavra]='1';                                          
            ascender_led(palavra[tamanho_palavra]);
            tamanho_palavra++; 
          } 
          else digitalWrite(led_nok, HIGH);
        }
        if(digitalRead(btn_2)==HIGH){
          delay(DEBOUNCE);
          desliga_leds();
          if(valida_token('2')){
            palavra[tamanho_palavra]='2';                                          
            ascender_led(palavra[tamanho_palavra]);
            tamanho_palavra++; 
          } 
          else digitalWrite(led_nok, HIGH);
        }
        if(digitalRead(btn_3)==HIGH){
          delay(DEBOUNCE);
          desliga_leds();
          if(valida_token('3')){
            palavra[tamanho_palavra]='3';                                          
            ascender_led(palavra[tamanho_palavra]);
            tamanho_palavra++; 
          } 
          else digitalWrite(led_nok, HIGH);
        }
        if(digitalRead(btn_4)==HIGH){
          delay(DEBOUNCE);
          desliga_leds();
          if(valida_token('4')){
            palavra[tamanho_palavra]='4';                                          
            ascender_led(palavra[tamanho_palavra]);
            tamanho_palavra++; 
          } 
          else digitalWrite(led_nok, HIGH);
        }     
        if(tamanho_palavra==MAX_PALAVRA){
          delay(TEMPO_EXIBICAO);
          ESTADO=VALIDA_PALAVRA;
          lcd.clear();
        }
      }
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        if(digitalRead(led_nok)==HIGH){
          delay(DEBOUNCE);
          lcd.clear();
          for(int i=0; i<MAX_PALAVRA; i++) palavra[i]=' ';
          tamanho_palavra=0;
          desliga_leds();
        }
        else{
          ESTADO=VALIDA_PALAVRA;
          lcd.clear();
        }               
      }
    break;

    case VALIDA_PALAVRA:
      exibir_lcd_confirma_palavra();
      if(posicao_atual_eh_final(estado_atual)) digitalWrite(led_ok, HIGH);
      else digitalWrite(led_nok, HIGH);
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        ESTADO=INSERE_PALAVRA;
        desliga_leds();
        lcd.clear();
        for(int i=0; i<MAX_PALAVRA; i++) palavra[i]=' ';
        tamanho_palavra=0;
        estado_atual='0';
      }
    break;

  };
}

