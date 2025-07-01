int greenD1 = 0;
int greenE1 = 0;

bool Verde() {
  greenD1 = pulseIn(outD, digitalRead(outD) == HIGH ? LOW : HIGH);
  greenE1 = pulseIn(outE, digitalRead(outE) == HIGH ? LOW : HIGH);

  Serial.println(greenD1);
  Serial.println(greenE1);

  if ((greenD1 >= 30) && (greenD1 <= 40)) {
    Serial.println("Verde Direita detectado");
    CurvaDir90Ved();
    return true;
  }

  if ((greenE1 >= 30) && (greenE1 <= 40)) {
    Serial.println("Verde Esquerda detectado");
    CurvaEsq90Ved();
    return true;
  }

  return false;
}
