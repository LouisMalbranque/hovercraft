/**
 * Exemple de code pour la bibliothèque Mirf – Serveur Ping Pong
 */
#include <SPI.h>      // Pour la communication via le port SPI
#include <Mirf.h>     // Pour la gestion de la communication
#include <nRF24L01.h> // Pour les définitions des registres du nRF24L01
#include <MirfHardwareSpiDriver.h> // Pour la communication SPI
#include <Servo.h>
#define pinMoteur1 6
#define pinMoteur2 5
#define pinServo A4
Servo moteur1;
Servo moteur2;
Servo direction;

void setup() {
  Serial.begin(9600);

  Mirf.cePin = 9; // Broche CE sur D9
  Mirf.csnPin = 10; // Broche CSN sur D10
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init(); // Initialise la bibliothèque

  Mirf.channel = 2; // Choix du canal de communication (128 canaux disponibles, de 0 à 127)
  Mirf.payload = 22; // Taille d'un message (maximum 32 octets)
  Mirf.config(); // Sauvegarde la configuration dans le module radio

  Mirf.setTADDR((byte *) "nrf01"); // Adresse de transmission
  Mirf.setRADDR((byte *) "nrf02"); // Adresse de réception

  Serial.println("Go !"); 

  moteur1.attach(pinMoteur1); 
  moteur2.attach(pinMoteur2);
  direction.attach(pinServo);
  
  moteur1.write(0);
  moteur2.write(0);
  delay(1000);
  moteur1.write(180);
  moteur2.write(180);
  delay(1000);
  moteur1.write(0);
  moteur2.write(0);
  delay(500); 
}

void loop() {
  int message[11];

  if(Mirf.dataReady()){
    Mirf.getData((byte*) &message); // Réception du paquet
  }
  if (message[1] == 1){
    moteur1.write(115);
  }else if (message[1] == 0){
    moteur1.write(0);
  }
  if (message[10]>500 && message[10]<=1023){
    moteur2.write(map(message[10], 512, 1023, 0, 70));
  }else moteur2.write(0);
  direction.write(map(message[7], 0, 1023, 130, 50));
  
}
