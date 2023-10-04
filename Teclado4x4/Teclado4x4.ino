/*
El teclado 4x4 controla el encendido y apagado de un diodo LED en el pin digital 2 al presionar una tecla definida en el teclado y 
la impresión de 2 textos en el puerto serial.

Conexión del teclado 4x4 en Arduino
D11 IZQ
D10
D09
D08
D07
D06
D05
D04 DER

Conexión del diodo LED en Arduino
Positivo 3.3v
Negativo D02
*/

#include <Keypad.h>
 
const byte rowsCount = 4;
const byte columsCount = 4;

char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 11, 10, 9, 8 };
const byte columnPins[columsCount] = { 7, 6, 5, 4 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 
int LED = 2;

void setup() {
   Serial.begin(9600);

   pinMode(LED, OUTPUT);
}
 
void loop() {
   
   char key = keypad.getKey();
   
   if (key) {
      Serial.println(key);
      if (key == '9') {
        delay(1000);
        Serial.println("Hola");
        delay(1000);
        Serial.println("Adiós");
        delay(1000);
        Serial.println("Encendiendo...");
        digitalWrite(LED, LOW);
        delay(2000);
        Serial.println("Apagando...");
        digitalWrite(LED, HIGH);
      }else{
        digitalWrite(LED, HIGH);
      }
   }else{
    digitalWrite(LED, HIGH);
   }

}