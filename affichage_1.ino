#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 10, 7, 6, 5, 4); //Definition des pins raccordés sur l'afficheur LCD //Phase d'init

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2); //Définition de la taille de l'écran LCD //Phase d'init

  //UN MASQUE POUR CHAQUE BIT DU REGISTRE DDRD (CORRESPOND AUX DATAS)
  DDRD |= 0x80; //PD7 en sortie
  DDRD |= 0x40; //PD6 en sortie
  DDRD |= 0x20; //PD5 en sortie
  DDRD |= 0x10; //PD4 en sortie
  PORTB |= 0x01;
 
  //UN MASQUE POUR CHAQUE BIT DU REGISTRE DDRB (CORRESPOND A RS ET E)
  DDRB |= 0x01; //PB0 en sortie -> RS : signal pour afficher les datas
  DDRB |= 0x04; //PB2 en sortie -> E : autorisation de l'affichage des datas
  
  //CF CHRONOGRAMME P4_DISPLAY204A
  // PORTB &=~ 0x04; //mise à 0 de E (PB2)
  // PORTB &=~ 0x01; //mise à 0 de RS (PB0)
  // delayMicroseconds(10);
  // PORTB |= 0x01; //mise à 1 de RS (PB0)
  // delayMicroseconds(10);
  // PORTB |= 0x04; //mise à 1 de E (PB2)
  // delayMicroseconds(10);


  // unsigned char lettre = 'a';
  // unsigned char upper = lettre & 0xF0;
  // unsigned char lower = lettre & 0x0F;
  // PORTD |= 0x70;
  // PINB |= 0x04;
delayMicroseconds(100);

PORTD = 0x50;
PORTB &=~ 0x04; //mise à 0 de E (PB2)
PORTB |= 0x04; //mise à 1 de E (PB2)
delayMicroseconds(100);
PORTB &=~ 0x04; //mise à 0 de E (PB)
delayMicroseconds(100);
PORTD = 0x80;
PORTB &=~ 0x04; //mise à 0 de E (PB2)
PORTB |= 0x04; //mise à 1 de E (PB2)
delayMicroseconds(100);
PORTB &=~ 0x04; //mise à 0 de E (PB)
delayMicroseconds(100);
}

void loop() {
  // put your main code here, to run repeatedly:
//  unsigned char lettre = 'A';

}
