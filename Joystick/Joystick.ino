/*Programación del módulo joystick, el cual tiene una programación para controlar la activación y dirección 
de motores y un diodo LE
const int pinLED = 13;
const int pinJoyX = A0;
const int pinJoyY = A1;
const int pinJoyButton = 9;

int LED = 2;

void setup() {
  pinMode(pinJoyButton , INPUT_PULLUP);  //activar resistencia pull up 
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int Xvalue = 0;
  int Yvalue = 0;
  bool buttonValue = 0;

  //leer valores
  Xvalue = analogRead(pinJoyX);
  delay(100);            //es necesaria una pequeña pausa entre lecturas analógicas
  Yvalue = analogRead(pinJoyY);

  buttonValue = digitalRead(pinJoyButton);

  //mostrar valores por serial
  Serial.print("X:" );
  Serial.print(Xvalue);
  Serial.print(" | Y: ");
  Serial.print(Yvalue);
  Serial.print(" | Pulsador: ");
  Serial.println(buttonValue);
  delay(500);

//Avanzar en linea recta
  if (Xvalue > 1000 &&        Yvalue > 300 && Yvalue < 724) {
    Serial.print("Avanzar ");
  }

//Reversa
  if (Xvalue < 100 &&        Yvalue > 300 && Yvalue < 724) {
    Serial.print("Retroceder ");
  }


//Rotar izquierda
  if (Xvalue > 300 && Xvalue < 724 &&       Yvalue < 100) {
    Serial.print("Rotando a la izquierda ");
  }

//Rotar derecha
  if (Xvalue > 300 && Xvalue < 724 &&       Yvalue > 1000) {
    Serial.print("Rotando a la derecha ");
  }


//Avanzar y rotar derecha
  if (Xvalue > 725 && Yvalue > 725) {
    Serial.print("Avanzando y rotando a la derecha ");
  }

//Avanzar y rotar izquierda
  if (Xvalue > 725 && Yvalue < 299) {
    Serial.print("Avanzando y rotando a la izquierda ");
  }


//Retroceder y rotar derecha
  if (Xvalue < 299 && Yvalue > 725) {
    Serial.print("Retroceder rotando a la derecha ");
  }

//Avanzar y rotar izquierda
  if (Xvalue < 299 && Yvalue < 299) {
    Serial.print("Retroceder rotando a la izquierda ");
  }


//Accionador
  if (buttonValue == 0) {
    Serial.print("Accionando... ");
    digitalWrite(LED, LOW);
    delay(1000);
    digitalWrite(LED, HIGH);
  }

}




