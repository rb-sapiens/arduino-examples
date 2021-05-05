// 正転と逆転を2秒おきに繰り返すサンプル
int E1 = 10;
int M1 = 12;
int E2 = 11;
int M2 = 13;

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
}

void loop() {
  digitalWrite(M1,HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 100);
  analogWrite(E2, 100);

  delay(2000);

  digitalWrite(M1,LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 100);
  analogWrite(E2, 100);

  delay(2000);

}
