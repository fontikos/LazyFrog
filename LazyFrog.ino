/*
    Copyright (C) 2014  Xenofon (Fontas) Fafoutis
    http://eis.bristol.ac.uk/~xf14883
    xenofon.fafoutis@bristol.ac.uk
    fontikos@gmail.com
    
    Lazy Frog: A Digitally-Controlled Optical Tremolo
    
    Modes:
    Mode 0 - 50/50    - 50% HIGH 50% LOW, POT1 controls the speed, POT2 applies fine adjustments on the speed
    Mode 1 - PWM      - Pulse Width Modulator, POT1 controls the duration of HIGH, POT2 controls the duration of LOW
    Mode 2 - Pattern  - 8-bit Pattern, POT1 controls the duration of each beat, POT2 defines an 8-bit HIGH-LOW pattern (e.g. HLLHHHLL)

    This program is distributed under the Creative Commons Attribution-NonCommercial 2.0 UK Licence (http://creativecommons.org/licenses/by-nc/2.0/uk/).
*/
 

int led = 0; // LED Pin
int a1 = 1;  // A1 Pin
int a2 = 2;  // A2 Pin
int a3 = 3;  // A3 Pin

int pot1,pot2,sw1;
int mode = 2;
int i;

void setup() {                
  pinMode(led, OUTPUT);    
  pinMode(a1, INPUT);
  pinMode(a2, INPUT);
  pinMode(a3, INPUT);
}

void loop() {
  pot1 = analogRead(a1);  // Read POT1
  pot2 = analogRead(a3);  // Read POT2
  sw1 = analogRead(a2);   // Read MODE
  
  if (sw1>900)
    mode = 1;
  else if (sw1<100)
    mode = 2;
  else
    mode = 0;
    
  
  if(mode==0){  
    digitalWrite(led, HIGH);   
    delay(pot1 + (pot2/10));    
    digitalWrite(led, LOW);    
    delay(pot1 + (pot2/10));   
  }
  if(mode==1){  
    digitalWrite(led, HIGH);  
    delay(pot1);               
    digitalWrite(led, LOW);
    delay(pot2);
  }  
  if(mode==2){  
    for(i=2;i<10;i++){
      if((pot2>>i)%2==1) 
        digitalWrite(led, HIGH);
      else
        digitalWrite(led, LOW);
      delay(pot1>>3);
    }
  }
}
