/*

 License    : GNU GPL v3 or later
 Author     : Aurélien DESBRIERES
 Mail       : aurelien@hackers.camp
 Project    : Break Instruction
 Created on : Tue Nov 11 08:55:16 2014

 Write && Compile with Emacs-Nox for ATMega328p && LearnCBot Shield

 References
 
 define, void setup, void loop, !, digitalwrite/read, counter

 Course material

 MOOC EPFL microcontrollers

*/


#define AttenteMax 5000 // 5 secondes
#define PeriodeEchant 50//100 ....
#define Led 4
#define Pouss1 2
#define Pous1On !digitalRead(Pouss1)//Poussoir Active...
#define Led1On digitalWrite(Led,HIGH)//ON
#define Led1Off digitalWrite(Led,LOW)//OFF


void setup(){
  pinMode (Pouss1,INPUT);//Poussoir1 Entree
  pinMode (Led,OUTPUT);//Led Sortie
  Led1Off;//Led ...defaut OFF
}

byte cnt=0;

void loop (){
  while (1) {
    if (Pous1On) { cnt=0; }
    delay (PeriodeEchant) ;
    if (cnt >= AttenteMax/PeriodeEchant) { break; }
    cnt++;
  }
  Led1On; delay (500);//500 ms 1/2 s
  Led1Off; delay (500);//500 ms  1/2s
}
