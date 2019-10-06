

#include <Wire.h> 
#include <LCD5110_Basic.h>
#include "IO_MLX90615.h"

int inPin1=3; // ortam 
int inPin2=4; // nesne
int inPin3=5; // celcius cinsinden
int inPin4=6; // KELVIN cinsinden
int inPin5=7; // ekran isigi ayarlama
int giris = A0;


 int buton_durumu1=0;
 int buton_durumu2=0;
 int buton_durumu3=0;
 int buton_durumu4=0;
 int buton_durumu5=0;
 

LCD5110 ekran (8,9,10,11,12);
extern uint8_t SmallFont[];
extern uint8_t resim1[];
extern uint8_t dort[];
extern uint8_t uc[];
extern uint8_t iki[];
extern uint8_t tek[];

IO_MLX90615 sensor = IO_MLX90615();
float tempo;
float tempa;


void setup() {
  
pinMode(inPin1,INPUT); 
pinMode(inPin2,INPUT);
pinMode(inPin3,INPUT);
pinMode(inPin4,INPUT);
pinMode(inPin5,INPUT);
pinMode(giris,INPUT);


ekran.InitLCD();
ekran.setContrast(70);
sensor.begin();

}


void loop ()

{  
     int okunan = analogRead(giris);
     float voltaj = okunan * 15 / 1023;
     delay(1000);
     if(14>= voltaj>= 12)
     { 
     ekran.drawBitmap(74,0,dort,9,16); 
     }

     if(11>= voltaj>= 8)
     { 
     ekran.drawBitmap(74,0,uc,9,16); 
     }

     if(7>= voltaj>= 4)
     { 
     ekran.drawBitmap(74,0,iki,9,16); 
     }

     if(3>= voltaj>=0)
     { 
     ekran.drawBitmap(74,0,tek,9,16); 
     }
     
     
  
     buton_durumu1=digitalRead(inPin1);
     buton_durumu2=digitalRead(inPin2);
     buton_durumu3=digitalRead(inPin3);
     buton_durumu4=digitalRead(inPin4);
     buton_durumu5=digitalRead(inPin5);

ekran.drawBitmap(0,0,resim1,18,48);
 
   if(buton_durumu1==HIGH)
  {
   ekran.clrScr();
   ekran.setFont(SmallFont);
   tempo= sensor.readObjectTempC(); 
   ekran.print("Nesne",25,0);
   ekran.print("Sicakligi:",25,16);
   ekran.setFont(SmallFont);
   ekran.printNumF(tempo,2,20,32);
   ekran.print("o",63,24);
   ekran.print("C",69,32);
   delay(50);   
     }
   
  
  else if(buton_durumu2==HIGH)
    {
    ekran.clrScr();
    ekran.setFont(SmallFont);
    tempa= sensor.readAmbientTempC();
    ekran.print("Ortam",25,0);
    ekran.print("Sicakligi:",25,16);
    ekran.setFont(SmallFont);
    ekran.printNumF(tempo,2,20,32);
    ekran.print("o",63,24);
    ekran.print("C",69,32);
    delay(50);    
    }

    if (buton_durumu3==HIGH)
    {
      ekran.clrScr();
      ekran.setFont(SmallFont);
      tempo= sensor.readObjectTempF(); 
      ekran.print("Nesne",25,0);
      ekran.print("Sicakligi:",25,16);
      ekran.setFont(SmallFont);
      ekran.printNumF(tempo,2,20,32);
      ekran.print("o",63,24);
      ekran.print("F",69,32);
      delay(50); 
    }

    else if(buton_durumu4==HIGH)
    {
     ekran.clrScr();
     ekran.setFont(SmallFont);
     tempa= sensor.readAmbientTempF();
     ekran.print("Ortam",25,0);
     ekran.print("Sicakligi:",25,16);
     ekran.setFont(SmallFont);
     ekran.printNumF(tempo,2,20,32);
     ekran.print("o",63,24);
     ekran.print("F",69,32);
     delay(50);    
    }
 }






  
