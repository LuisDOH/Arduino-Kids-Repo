#include <LiquidCrystal.h>

#define led 3
#define eco 4
#define trig 5
#define buzzer 6

// Decir a arduino como esta conectada
// la pantalla
// conexiones (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(7,8,9,10,11,12);

int A_2 = 880;  int B_  = 493/2;
int B2  = 988;  int Cs3 = 555*2;
int E   = 329;  int Ds3 = 623*2;

int tempo = 116;    int semi = 60000/( tempo * 4 *2);
int corch = 2*semi; int negra = corch*2;  int np = corch*3;

int blanca = negra*2; int redonda = blanca*2;
int rep = 3*negra;    int bnp = 3*negra+3*corch;

int b =blanca;  int r =2*b;   int n = negra;  int c = corch;
int s = semi;   int f = s/2;  int sf = f/2;

int cp = c+s;   int Sil = 10;
int retardo = 115;


void setup(){
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  // tipo de pantalla
  lcd.begin(2,16);
  
}

void loop(){
  digitalWrite(trig, 1);
  delay(10);
  digitalWrite(trig, 0);

  int tiempo = pulseIn(eco, HIGH);
  int distancia =  tiempo * 0.034/2;

  

  if(distancia < 10){
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("(. )  _  (. )");
    lcd.setCursor(0, 1);
    lcd.print("Ya te vi ...");
    digitalWrite(led,1);
    ctono();
  }
  else{
    lcd.clear();
    lcd.setCursor(1, 1);
    lcd.print("Deteccion:");

    lcd.setCursor(11,1);
    lcd.print(distancia);
    digitalWrite(led,0);
  }

}

void nota(int nota, int duracion){
  tone(buzzer,nota, duracion);
  delay(duracion);
  noTone(buzzer);
  delay(duracion);
}


void ctono(){
  // [10]
  nota(B_,c);

  nota(B2,s); 
  nota(B2,s); 

  nota(Ds3,c); 
  nota(B2,c); 

  nota(Cs3,c); 
  nota(A_2,c); 

  nota(E,c); 
  nota(E,c); 

  // [11]
  nota(B_,c);
  nota(B_,c);

  nota(B2,s);
  nota(B2,s);
  nota(B2,s);
  nota(B2,s);

  
  nota(A_2,c);
  nota(B2,c);

  nota(E,c);
  nota(E,c);

  // [12]
  nota(B_,c);

  nota(B2,s); 
  nota(B2,s); 

  nota(Ds3,c); 
  nota(B2,c); 

  nota(Cs3,c); 
  nota(A_2,c); 

  nota(E,c); 
  nota(E,c); 
 
  // [13]
  nota(B_,c);
  nota(B_,c);

  nota(B2,s);
  nota(B2,s);
  nota(B2,s);
  nota(B2,s);

  
  nota(A_2,c);
  nota(Cs3,c);

  nota(B2,c);
  
  nota(B2,c);

} 