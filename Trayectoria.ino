///Valores de los motores
// Motor A
int ENA = 6;
int IN1 = 13;
int IN2 = 12;

// Motor B
int ENB = 5;
int IN3 = 11;
int IN4 = 10;
int vel = 200;

int encoderDer = A0;
int encoderIzq = A1;
int counterEncDer = 0;
int counterEncIzq = 0;
unsigned long t0 = 0;

int encDerVal = 1;
int encIzqVal = 1;
int currVal = 0;




void setup() {
  // put your setup code here, to run once:
  pinMode(encoderDer, INPUT);
  encDerVal = digitalRead(encoderDer);
  pinMode(encoderIzq, INPUT);
  encIzqVal = digitalRead(encoderIzq);
  
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
   pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
 
}

void loop() {
  delay(500);
 Adelante();
  delay(2500);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  Adelante();
  delay(1000);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  
  Derecha();
  delay(150);
  Parar();
  delay(1000);
  
  Adelante();
  delay(2500);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  Adelante();
  delay(1000);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  
  Derecha();
  delay(150);
  Parar();
  delay(1000);

  Adelante();
  delay(2500);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  Adelante();
  delay(1000);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  
  Derecha();
  delay(150);
  Parar();
  delay(1000);
  
 Adelante();
  delay(2500);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
  Adelante();
  delay(1000);
  Derecha();
  delay(1);
  Izquierda();
  delay(1);
   
  Derecha();
  delay(150);
  Parar();
  delay(3000);
  


  
}
void Atras ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, vel); //Velocidad motor B
 analogWrite (ENA, vel); //Velocidad motor A
}
void Parar ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, LOW);
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, 0); //Velocidad motor B
 analogWrite (ENA, 0); //Velocidad motor A
 
}

void Adelante ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
  //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel); //Velocidad motor B
 analogWrite (ENA, vel); //Velocidad motor A

}

void Derecha ()
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, vel); //Velocidad motor A
 analogWrite (ENA, vel); //Velocidad motor A
 
}
void Izquierda ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel); //Velocidad motor A
 analogWrite (ENA, vel); //Velocidad motor A
 
} 
