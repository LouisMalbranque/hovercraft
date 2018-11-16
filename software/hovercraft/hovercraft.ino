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
Servo moteur1;
Servo moteur2;

void setup() {
  Serial.begin(9600);

  Mirf.cePin = 9; // Broche CE sur D9
  Mirf.csnPin = 10; // Broche CSN sur D10
  Mirf.spi = &MirfHardwareSpi; // On veut utiliser le port SPI hardware
  Mirf.init(); // Initialise la bibliothèque

  Mirf.channel = 1; // Choix du canal de communication (128 canaux disponibles, de 0 à 127)
  Mirf.payload = sizeof(long)*11; // Taille d'un message (maximum 32 octets)
  Mirf.config(); // Sauvegarde la configuration dans le module radio

  Mirf.setTADDR((byte *) "nrf01"); // Adresse de transmission
  Mirf.setRADDR((byte *) "nrf02"); // Adresse de réception

  Serial.println("Go !"); 

  moteur1.attach(pinMoteur1); 
  moteur2.attach(pinMoteur2);
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
  byte message[11];

  if(Mirf.dataReady()){
    Mirf.getData(message); // Réception du paquet
  }
  for (int i=0; i<11; i++){
    Serial.print(message[i]);
    Serial.print(" ");
  }
  Serial.println();
}
