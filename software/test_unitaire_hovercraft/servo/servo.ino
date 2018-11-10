
#include <Servo.h>

// pin ded connexion du servo (A4 == 23) 
#define pinservo A4

Servo myServo;

/*
* initialisation
*/
void setup() {
  myServo.attach(pinservo);
}


/*
 * on met le servo d'un coté et une seconde apres de l'autre
 */
void loop() {
  myServo.write(1);
  delay(2000);
  myServo.write(179);
  delay(2000);
}
