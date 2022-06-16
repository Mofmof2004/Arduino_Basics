

// définition des broches utilisées
const int brocheQA = 2;
const int brocheQB = 3;
const int brocheQC = 4;
const int brocheQD = 5;
const int brocheUP = 6;

void setup() {

  // une sortie pour contrôler l'entrée du 74LS193
  pinMode(brocheUP, OUTPUT);
  digitalWrite(brocheUP, HIGH);
  
  // 4 entrées pour lire les sorties du 74LS193.
  pinMode(brocheQA, INPUT);
  pinMode(brocheQB, INPUT);
  pinMode(brocheQC, INPUT);
  pinMode(brocheQD, INPUT);

  // initialisation de la communication série
  Serial.begin(9600);
  Serial.println("Test du compteur SN74LS193");
  Serial.println("");
}

void loop() {

  // envoi d'une impulsion: la tension prend brièvement
  // une valeur nulle avant de redevenir 5 V.
  digitalWrite(brocheUP, LOW);
  digitalWrite(brocheUP, HIGH);

  // Lecture des 4 sortiers du SN74LS193 et affichage
  // dans le moniteur série
  Serial.print("QD: ");
  Serial.print(digitalRead(brocheQD));
  Serial.print("   QC: ");
  Serial.print(digitalRead(brocheQC));
  Serial.print("   QB: ");
  Serial.print(digitalRead(brocheQB));
  Serial.print("   QA: ");
  Serial.println(digitalRead(brocheQA));
  
  delay(1000); // on ralentit exagérément le processus pour avoir le temps de voir ce qui se passe

}
