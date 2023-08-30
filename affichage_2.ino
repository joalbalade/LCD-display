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
 
  //UN MASQUE POUR CHAQUE BIT DU REGISTRE DDRB (CORRESPOND A RS ET E)
  DDRB |= 0x01; //PB0 en sortie -> RS : signal pour afficher les datas
  DDRB |= 0x04; //PB2 en sortie -> E : autorisation de l'affichage des datas

}

void loop() {
  // put your main code here, to run repeatedly:
//  unsigned char lettre = 'A';

}

//FONCTION D'ACTIVATION/DESACTIVATION DES SORTIES DE DDRB ET DDRD (VOIR P4_DISPLAY204A)
void pulseEnable(){
  // PORTB &=~ 0x02; //mise à 0 de R/W (PB1)
  PORTB &=~ 0x04; //mise à 0 de E (PB2)
  PORTB &=~ 0x01; //mise à 0 de RS (PB0)
  delayMicroseconds(100); //temps à l'état haut
  PORTB |= 0x01; //mise à 1 de RS (PB0)
  delayMicroseconds(100);
  PORTB |= 0x04; //mise à 1 de E (PB2)
  delayMicroseconds(100);
  PORTD |= 0xF0; //mise à 1 des datas (PD7 -> PD4) (bits de poids forts)
  delayMicroseconds(100);
  PORTB &=~ 0x04; //mise à 0 de E (PB2)
  delayMicroseconds(50);
  PORTD &=~ 0xF0; //mise à 0 des datas (PD7 -> PD4) (bits de poids forts)
  PORTB &=~ 0x01; //mise à 0 de RS (PB0)
}

//ECRITURE DES BITS SEGEMENTEE EN 4 PAR 4
void write4bits(){

}
// void LiquidCrystal::write4bits(uint8_t value) {
//   for (int i = 0; i < 4; i++) {
//     digitalWrite(_data_pins[i], (value >> i) & 0x01);
//   }

//   pulseEnable();
// }
