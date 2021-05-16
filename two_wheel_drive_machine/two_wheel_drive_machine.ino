int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

int BUZZER = 4;

int TRIG = 8;
int ECHO = 9;

double Duration = 0; //受信した間隔
double Distance = 0; //距離

void setup() {
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  Serial.begin( 9600 );

  pinMode(BUZZER, OUTPUT);
  pinMode(ECHO, INPUT );
  pinMode(TRIG, OUTPUT );

  buzzer(2800,200);
  buzzer(3200,200);
  buzzer(4000,200);
}

void loop() {
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite( TRIG, HIGH ); //超音波を出力
  delayMicroseconds( 10 ); //
  digitalWrite( TRIG, LOW );
  Duration = pulseIn( ECHO, HIGH ); //センサからの入力
  if (Duration > 0) {
    Duration = Duration/2;
    Distance = Duration*340*100/1000000;
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println(" cm");
  }

  if (Distance < 20){
    drive(100, -100);
  }else if(Distance < 50){
    drive(100, -20);
  }else{
    drive(130,150);
  }
  delay(200);
}

void drive(int m1_lever, int m2_lever){
  if(m1_lever > 0){
    digitalWrite(M1,HIGH);
  }else{
    digitalWrite(M1,LOW);
  }
  if(m2_lever > 0){
    digitalWrite(M2,HIGH);
  }else{
    digitalWrite(M2,LOW);
  }

  analogWrite(E1, abs(m1_lever));
  analogWrite(E2, abs(m2_lever));
}

// freq: frequency of buzzer [hz]
// duration: buzzer duration [ms]
void buzzer(long freq, long duration){
  long delaymicrosec = 1000000 / freq / 2;
  long count = freq * duration / 1000 / 2;

  for (int i = 0; i < count; i++){
    digitalWrite(BUZZER, HIGH);
    delayMicroseconds(delaymicrosec);
    digitalWrite(BUZZER, LOW);
    delayMicroseconds(delaymicrosec);
  }
}
