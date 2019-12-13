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
int cmd_right,cmd_left;
// Direccion (1 adelante, -1 atras)
int dir_1 = 1;
int dir_2 = 1;

///Valores del encoder

int encoderDer = A0;
int encoderIzq = A1;
int counterEncDer = 0;
int counterEncIzq = 0;
unsigned long t0 = 0;

int encDerVal = 0;
int encIzqVal = 0;
int currVal = 0;

// Velocidad en encoder ticks/seg
double targetR = 0;
double targetL = 0;

// Cada cuanto revizar velocidad (en milis)
int sample_time = 250;


///Valores del PID
double kpr = .7;
double kir = .7;
double kdr = 0.15;

double kpl = .9;
double kil = .6;
double kdl = 0.1;

double err_r = 0;
double sum_err_r = 0;
double prev_err_r = 0;

double err_l = 0;
double sum_err_l = 0;
double prev_err_l = 0;

double pid_r = 0;
double pid_l = 0;

int out_r = 200;
int out_l = 0;

void setup()
{
 Serial.begin(9600) ;
 // Declaramos todos los pines como salidas
 pinMode (ENA, OUTPUT);
 pinMode (ENB, OUTPUT);
  pinMode(encoderDer, INPUT);
  encDerVal = analogRead(encoderDer);
  pinMode(encoderIzq, INPUT);
  encIzqVal = analogRead(encoderIzq);
  
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
 
  //analogWrite(IN2, 0);
  //analogWrite(IN1, 0);
  
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  //analogWrite(IN3, 0);
  //analogWrite(IN4, 0);
  
  t0 = millis();
 
}

void loop()
{
  // Contar encoder derecho
  currVal = analogRead(encoderDer);
  Serial.println("Valor enconder");

  Serial.println(currVal);

  //if(encDerVal == HIGH){
    if(currVal >= 300){
      counterEncDer++;
        Serial.println("entro");

    }
//  }
  Serial.println(counterEncDer);

  encDerVal = currVal;

  // Contar encoder izquierdo
  currVal = analogRead(encoderIzq);
 // if(encIzqVal == HIGH){
    if(currVal >= 300){
      counterEncIzq++;
    }
  //}
  encIzqVal = currVal;
 //Adelante(vel);
  delay(1000);
  // Cada sample_time ms calcula velocidad y PID
  if(millis() >= t0 + sample_time){
    //PID
    // Error actual es target - velocidad en ticks/segundo
    err_r = targetR - (1000/sample_time)*counterEncDer*dir_1;
    err_l = targetL - (1000/sample_time)*counterEncIzq*dir_2;

    // Error integral
    sum_err_r += err_r;
    sum_err_l += err_l;

    // PID completo
    pid_r = err_r*kpr + (err_r - prev_err_r)*kdr + sum_err_r*kir;
    pid_l = err_l*kpl + (err_l - prev_err_l)*kdl + sum_err_l*kil;
    // Actualizar error previo
    prev_err_r = err_r;
    prev_err_l = err_l;

    // Ajustar salida
    out_r = min(abs(pid_r), 255);
    out_l = min(abs(pid_l), 255);
    // Por ahora, solo hay targets positivos.
    if (pid_r >= 0){
      analogWrite(ENA, out_r);
      analogWrite(IN1, 0);
      dir_1 = 1;    
      Serial.println("Velocidad primer ciclo der");
      Serial.println(out_r*100);
      
      Adelante (out_r*100);
         
    }else{
      analogWrite(IN2, 0);
      analogWrite(ENA, out_r);
      dir_1 = -1;
      Atras (out_r);
       }
     // Por ahora, solo hay targets positivos
    if (pid_l >= 0){
      //Serial.println("Velocidad primer ciclo izq");
      analogWrite(ENB, out_l);
      analogWrite(IN4, 0);
      dir_2 = 1;
      Adelante (out_r*100);
    
    }else{
      analogWrite(IN3, 0);
      analogWrite(ENB, out_l);
      dir_2 = -1;
     // Serial.print(out_r);
    }

    // Volver a empezar tiempo para calcular velocidad
    t0 = millis();
  }
  
 //Adelante ();
 //delay(1000); 

 //Derecha ();
 //delay(500);
 }
void Atras (int vel)
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, vel); //Velocidad motor B
 
}
void Adelante (int vel)
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel); //Velocidad motor B
 
}

void Derecha (int vel)
{
 //Direccion motor A
 digitalWrite (IN1, LOW);
 digitalWrite (IN2, HIGH);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, HIGH);
 digitalWrite (IN4, LOW);
 analogWrite (ENB, vel); //Velocidad motor A
}
void Izquierda ()
{
 //Direccion motor A
 digitalWrite (IN1, HIGH);
 digitalWrite (IN2, LOW);
 analogWrite (ENA, vel); //Velocidad motor A
 //Direccion motor B
 digitalWrite (IN3, LOW);
 digitalWrite (IN4, HIGH);
 analogWrite (ENB, vel); //Velocidad motor A
} 
