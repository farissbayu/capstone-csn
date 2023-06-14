// roda kanan
#define IN1 2 // maju
#define IN2 3 // mundur
// roda kiri
#define IN3 5 // mundur
#define IN4 4 // maju

// pompa_kanan 
#define IN1a 6
#define IN2a 7
//#define IN3a 9
//#define IN4a 8

#define PUMP 6

// --infrared sensor-- //
#define IR1 A0
#define IR2 A1
#define IR3 A2
#define IR4 A3
#define IR5 A4

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(IN1a, OUTPUT);
  pinMode(IN2a, OUTPUT);
//  pinMode(IN3a, OUTPUT);
//  pinMode(IN4a, OUTPUT);
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  
  Serial.begin(115200);
}

  
void loop() {
  // Reading sensor value
  int s1 = digitalRead(IR1);
  int s2 = digitalRead(IR2);
  int s3 = digitalRead(IR3);
  int s4 = digitalRead(IR4);
  int s5 = digitalRead(IR5);

  if (s1 == 1 && s2 == 1 && s3 == 1 && s4 == 1 & s5 == 1) {
    stop();
  }
  
  
  if (s1 == 0 && s2 == 0 && s3 == 0 && s4 == 0 & s5 == 0) {
    stop();
    delay(1000);
    pumpOn();
    delay(1000);
    pumpOff();
    delay(1000);
    forward();
    delay(100);
  }


  // forward
  else if (s3 == 0 || (s2 == 0 && s3 == 0) || (s3 ==0 && s4 == 0) || (s2 == 0 && s3 == 0 && s4 == 0)) {
    forward();
  }

  // right
  else if (s5 == 0 || (s4 == 0 && s5 == 0) || (s3 == 0 && s4 == 0 && s5 == 0)) {
    right();
  }

  // left
  else if (s1 == 0 || (s2 == 0 && s1 == 0) || (s3 == 0 && s2 == 0 && s1 == 0)) {
    left();
  }

}


void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void right() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void left() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void pumpOn() {
  digitalWrite(IN1a, HIGH);
  digitalWrite(IN2a, LOW);
}


void pumpOff() {
  digitalWrite(IN1a, LOW);
  digitalWrite(IN2a, LOW);
}
