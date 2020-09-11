#include "automato.h"

void zera_matriz_finais_palavra(){
  for(int i=0; i<MAX_TRANSICOES; i++){      
    for(int j=0; j<3; j++){
      matriz[i][j]=' ';
    }
  }
  for(int i=0; i<MAX_ESTADOS; i++){
    estados_finais[i]=' ';
  }
  for(int i=0; i<MAX_PALAVRA; i++){
    palavra[i]=' ';
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
  flag_nok=true;// ACUSA ERRO.
  return false;
}

bool verificar_estado_final(char estado_atual){
  for(int i=0; i<MAX_ESTADOS; i++){
    if (estados_finais[i]==estado_atual) return true;
  }
  return false;
}

void abaixar_motores(){
  for (pos=0; pos<=90; pos++){
    motor_0.write(pos);
    motor_1.write(pos);
    motor_2.write(pos);
    motor_3.write(pos);
    motor_4.write(pos);
  }
}

void acusar_erro(){
  tone(buzzer,1500);   
  delay(500);
  noTone(buzzer);
  delay(500);
  tone(buzzer,1500);   
  delay(500);
  noTone(buzzer);
  flag_nok=true;
}

void acusar_sucesso(){
  tone(buzzer,1500);   
  delay(500);
  noTone(buzzer);
}

void levantar_motor(char transicao){
  for(int i=0; i<=numero_transicao; i++){
    if(matriz[i][0]==estado_atual && matriz[i][1]==transicao){
      estado_atual=matriz[i][2];
      switch(matriz[i][2]){           
        case '0':
          for (pos=90; pos>=0; pos--){
            motor_0.write(pos);
          }
        break;        
        case '1':
          for (pos=90; pos>=0; pos--){
            motor_1.write(pos);
          }
        break;
        case '2':
          for (pos=90; pos>=0; pos--){
            motor_2.write(pos);
          }
        break;        
        case '3':
          for (pos=90; pos>=0; pos--){
            motor_3.write(pos);
          }
        break;
        case '4':
          for (pos=90; pos>=0; pos--){
            motor_4.write(pos);
          }
        break;
      };
      return;
    }
  }
}

void montar_automato(char valor){
  delay(DEBOUNCE);
  matriz[numero_transicao][posicao_matriz]=valor;
  posicao_matriz++;
}

void definir_finais(int btn, char valor){
  delay(DEBOUNCE);
  if(estados_finais[btn]==' ') numero_estados_finais++;
  estados_finais[btn]=valor;
  tem_estado_final=true;
}

void inserir_palavra(char valor){
  delay(DEBOUNCE);
  abaixar_motores();
  if(valida_token(valor)){
    palavra[tamanho_palavra]=valor;                                          
    levantar_motor(palavra[tamanho_palavra]);
    tamanho_palavra++; 
  } 
  else acusar_erro();
}

void maquina_estados(){
  switch(ESTADO){
    
    case MONTA_AUTOMATO:
      exibir_lcd_monta_automato();
      if(digitalRead(btn_0)==HIGH) montar_automato('0');
      if(digitalRead(btn_1)==HIGH) montar_automato('1');
      if(digitalRead(btn_2)==HIGH) montar_automato('2');
      if(digitalRead(btn_3)==HIGH) montar_automato('3');
      if(digitalRead(btn_4)==HIGH) montar_automato('4');
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
      if(digitalRead(btn_0)==HIGH) definir_finais(0, '0');
      if(digitalRead(btn_1)==HIGH) definir_finais(1, '1');
      if(digitalRead(btn_2)==HIGH) definir_finais(2, '2');
      if(digitalRead(btn_3)==HIGH) definir_finais(3, '3');
      if(digitalRead(btn_4)==HIGH) definir_finais(4, '4');
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
      if(flag_nok==false){
        if(digitalRead(btn_0)==HIGH) inserir_palavra('0');
        if(digitalRead(btn_1)==HIGH) inserir_palavra('1');
        if(digitalRead(btn_2)==HIGH) inserir_palavra('2');
        if(digitalRead(btn_3)==HIGH) inserir_palavra('3');
        if(digitalRead(btn_4)==HIGH) inserir_palavra('4');
        if(tamanho_palavra==MAX_PALAVRA){
          delay(TEMPO_EXIBICAO);
          ESTADO=VALIDA_PALAVRA;
          lcd.clear();
        }
      }
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        if(flag_nok==true){
          delay(DEBOUNCE);
          lcd.clear();
          for(int i=0; i<MAX_PALAVRA; i++) palavra[i]=' ';
          tamanho_palavra=0;
          abaixar_motores;
        }
        else{
          ESTADO=VALIDA_PALAVRA;
          lcd.clear();
        }               
      }
      flag_nok=false;
    break;

    case VALIDA_PALAVRA:     
      if(flag_aviso_sonoro==false){
        if(verificar_estado_final(estado_atual)) acusar_sucesso();
        else acusar_erro();
        flag_aviso_sonoro=true;
      }
      if(digitalRead(btn_ok)==HIGH){
        delay(DEBOUNCE);
        ESTADO=INSERE_PALAVRA;
        abaixar_motores();
        lcd.clear();
        for(int i=0; i<MAX_PALAVRA; i++) palavra[i]=' ';
        tamanho_palavra=0;
        estado_atual='0';
        flag_aviso_sonoro=false;
      }
      exibir_lcd_confirma_palavra();
    break;
  };
}

