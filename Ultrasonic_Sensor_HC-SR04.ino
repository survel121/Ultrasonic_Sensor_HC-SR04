// Déclarer une variable pour la distance et une pour la durée

long duree;
float dist; // La distance peut avoir des chiffres après la virgule

void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT); // PIN trigger en sortie
  pinMode(8, INPUT); // PIN Echo en entrée
  Serial.begin(9600); // Communication avec le moniteur série

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(7, LOW);
  delay(1000);

  digitalWrite(7, HIGH);
  delayMicroseconds(10); // Délai de 10 uS pour activer l'envoi d'ultrason
  digitalWrite(7, LOW);

  duree = pulseIn(8, HIGH); // On lit le temps ou le PIN Echo est resté à l'état HAUT

  dist = (duree * 0.034) /2; // V = d/t donc d = V*t

  //On ecrit dans le moniteur série la distance :
  Serial.println(dist);
}
