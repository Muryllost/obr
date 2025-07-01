void SegueLinha() {
  bool s0 = digitalRead(IR[0]);
  bool s1 = digitalRead(IR[1]);
  bool s2 = digitalRead(IR[2]);
  bool s3 = digitalRead(IR[3]);
  bool s4 = digitalRead(IR[4]);

  // Correção à esquerda
  if  (((s4 == 0) && (s3 == 1) && (s2 == 0) && (s1 == 0) && (s0 == 0)) || ((s4 == 0) && (s3 == 1) && (s2 == 1) && (s1 == 0) && (s0 == 0))) {
    Serial.println("Correção Esquerda");
    MoverAcenEsq();

  }

  // Correção à direita
  else if (((s4 == 0) && (s3 == 0) && (s2 == 0) && (s1 == 1) && (s0 == 0)) || ((s4 == 0) && (s3 == 0) && (s2 == 1) && (s1 == 1) && (s0 == 0))) {
    Serial.println("Correção Direita");
    MoverAcenDir();

  }

  // Linha reta
  else if ((s4 == 0) && (s3 == 0) && (s2 == 1) && (s1 == 0) && (s0 == 0)) {
    Serial.println("Linha reta");
    MoverFrente();
  }

  else if ((s4 == 1) && (s3 == 1) && (s2 == 1) && (s1 == 1) && (s0 == 1)) {
    Serial.println("Voltando");
    Voltar();
  }

}
