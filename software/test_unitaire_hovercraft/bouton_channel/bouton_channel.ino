// pin du bouton 
#define pinBouton 7

/*
* setup du port série (verifié dans le port la vitesse)
* definition du mode du pin sur entrée
*/
void setup() {
  Serial.begin(9600);
  pinMode(pinBouton,INPUT);
}


// on affiche juste l'état du bouton dans le port série
void loop() {
  Serial.println(digitalRead(pinBouton));
}
