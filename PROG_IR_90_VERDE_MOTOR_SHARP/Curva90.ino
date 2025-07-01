bool Curva90() {
  bool s0 = digitalRead(IR[0]);
  bool s1 = digitalRead(IR[1]);
  bool s2 = digitalRead(IR[2]);
  bool s3 = digitalRead(IR[3]);
  bool s4 = digitalRead(IR[4]);

  // Curva Direita
  if (((s4 == 0) && (s3 == 0) && (s2 == 0) && (s1 == 0) && (s0 == 1)) ||
      ((s4 == 0) && (s3 == 0) && (s2 == 0) && (s1 == 1) && (s0 == 1))) {
    Serial.println("Curva Direita 90");
    CurvaDir90();
    return true;
  }

  // Curva Esquerda
  if (((s4 == 1) && (s3 == 0) && (s2 == 0) && (s1 == 0) && (s0 == 0)) ||
      ((s4 == 1) && (s3 == 1) && (s2 == 0) && (s1 == 0) && (s0 == 0))) {
    Serial.println("Curva Esquerda 90");
    CurvaEsq90();
    return true;
  }

  return false;
}
