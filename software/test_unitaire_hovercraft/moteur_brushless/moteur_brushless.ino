
#include <Servo.h>

// les moteur son branchés sur les pin D6 et D7
#define pinMoteur1 5
#define pinMoteur2 6

Servo moteur1;
Servo moteur2;


// on les deux servos sur leurs pins respectifs et on les initialise
void setup() {
  moteur1.attach(pinMoteur1); 
  
  moteur1.write(0);
  delay(1000);
  moteur1.write(180);
  delay(1000);
  moteur1.write(0);
  delay(500); 
  
  moteur2.attach(pinMoteur2);
  
  moteur2.write(0);
  delay(1000);
  moteur2.write(180);
  delay(1000);
  moteur2.write(0);
  delay(500);
  
}


// on lance les moteurs a vitesse moyenne et on les arretent apres 2 secondes  
void loop() {

  moteur1.write(150);
  moteur2.write(100);
}

