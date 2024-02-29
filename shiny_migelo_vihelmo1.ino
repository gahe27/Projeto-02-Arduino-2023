#define AnalogLDR A0
int Leitura = 0;
float VoltagemLDR;
float distancia, tempo;

void setup()
{
  pinMode(4, OUTPUT); //Verde
  pinMode(3, OUTPUT); //Amarelo
  pinMode(2, OUTPUT); //Vermelho
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Fotorresistor
  Leitura = analogRead(AnalogLDR);
  VoltagemLDR = Leitura * (5.0/1024);
  delay(500);
  Serial.println(VoltagemLDR);
  
  //Sensor ultrassônico
  digitalWrite(6, HIGH);
  delay(500);
  digitalWrite(6, LOW);
  tempo = pulseIn(5, HIGH);
  distancia = tempo * 0.01715;
  Serial.println(distancia);
  
  if((distancia < 30.0) && (VoltagemLDR > 4.0)){
  	digitalWrite(2, HIGH);
  } 
  else if(((VoltagemLDR >= 2.0) && (VoltagemLDR <= 3.0)) && ((distancia >= 31) && (distancia <= 60))){
  	digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
  }
  else if((VoltagemLDR < 2) && (distancia > 60)){
  	digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  else{
  	digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
  }
}