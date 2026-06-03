#include <SoftwareSerial.h>

SoftwareSerial BT(11,12);

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

char dato;

void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  BT.begin(9600);
}

void loop() {

  if(BT.available()) {

    dato = BT.read();

    switch(dato) {

      case 'F':
        adelante();
        break;

      case 'B':
        atras();
        break;

      case 'L':
        izquierda();
        break;

      case 'R':
        derecha();
        break;

      case 'S':
        detener();
        break;
    }
  }
}

void adelante() {

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void atras() {

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void izquierda() {

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void derecha() {

  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void detener() {

  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);

  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}