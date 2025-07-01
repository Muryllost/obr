// === VARIÁVEIS DE CONTROLE DE MOVIMENTO ===
const unsigned long tempoCurvaF1 = 710;
const unsigned long tempoCurvaF2 = 800;
const unsigned long tempoCurvaD1 = 740;
const unsigned long tempoCurvaD2 = 680;
const unsigned long tempoCurvaE1 = 650;
const unsigned long tempoCurvaE2 = 650;
const unsigned long tempoParar = 500;

// === Função genérica de movimento com temporização ===
void executarMovimento(void (*acao)(), unsigned long duracao) {
  unsigned long t0 = millis();  
  while (millis() - t0 < duracao) {
    acao();
  }
  PararMotor();
}

bool Distancia(){
  delay(200);   
  int dis=SharpIR.distance();  // isso retorna a distância até o objeto que você está medindo

  Serial.print("Distância média: ");  // retorna ao monitor serial
  Serial.println(dis);

  if (dis >= 12 && dis <= 15){
    Serial.println("Fazendo os movimentos");
    // Desvio com movimentos temporizados
    executarMovimento(PararMotor, tempoParar);
    Serial.println("Parou");
    delay(500);
    executarMovimento(CurvaDir90Sharp, tempoCurvaD1);
    Serial.println("Primeira curva a direita");
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF1);
    Serial.println("Primeira reta");
    delay(500);
    executarMovimento(CurvaEsq90Sharp, tempoCurvaE1);
    Serial.println("Primeira curva a esquerda");
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF2);
    Serial.println("Segunda reta");
    delay(500);
    executarMovimento(CurvaEsq90Sharp, tempoCurvaE2);
    Serial.println("Segunda curva a esquerda");
    delay(100);
    executarMovimento(MoverFrente, tempoCurvaF1);
    Serial.println("Terceira reta");
    delay(500);
    executarMovimento(CurvaDir90Sharp, tempoCurvaD2);
    Serial.println("Segunda curva a direita");
    delay(100);
    PararMotor();
    Serial.println("Fim movimentos!");

    return true;
  }
  return false;
}