// LCD1602 to Arduino Uno connection example

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 10, 4, 5, 6, 7); // bib init (initialisation)

void setup() {
 
   // un masque pour chaque bit de DDRD correspond au DATA
   DDRD |= 0x80; // PD 7 en sortie
   DDRD |= 0x40; // PD 6 en sortie
   DDRD |= 0x20; // PD 5 en sortie
   DDRD |= 0x10; // PD 4 en sortie
  // un masque pour chaque bit de DDRB correspond au RS et E: 
   DDRB |= 0x01;// PB0 en sortie RS: signal pour afficher les DATA 
   DDRB |= 0x04;// PB2 en sortie E: autorisation de l'afficher des DATA 
//////////////////////////////////////////

 lcd.begin(16, 2); // bib init (initialisation)
  PORTB |= 0x01; // mise a 1 de RS: PB0 
  delayMicroseconds(1);
  unsigned char lettre = 'a';
 // PORTD |=  0x61; 
  delayMicroseconds(100); 
 // PORTB &=~ 0x04;

char E = 10;
 
PORTD=0x50;
// PORTB |= 0x04; // mise a 1 de E: PB2
 delayMicroseconds(100); 
  digitalWrite(E, LOW);
  digitalWrite(E, HIGH);
  delayMicroseconds(1000);    
  //digitalWrite(E, HIGH);
  digitalWrite(E, LOW);
  PORTD=0x80;
  delayMicroseconds(1000);    // enable pulse must be >450ns
   digitalWrite(E, LOW);
   digitalWrite(E, HIGH);
   digitalWrite(E, LOW);
   delayMicroseconds(100);   // commands need > 37us to settle

  //lcd.print(PIND);
  //Serial.println(PIND);

 // Serial.begin(9600);
}
//---------------------------------------------------------------//
void loop() {
 // unsigned char lettre = 'a';
}

// void pulseEnable() { // pour activer et desactiver les temporisation dess sortie DDRB et DDRD
//  // PORTB &=~ 0x02; // mise a  0 permanente R/W 
//   PORTB &=~ 0x04; // mise a 0 de E: PB2
//   PORTB &=~ 0x01; // mise a 0 de RS: PB0
//   delayMicroseconds(100);
//   PORTB |= 0x01; // mise a 1 de RS: PB0
//   delayMicroseconds(100); 
//   PORTB |= 0x04; // mise a 1 de E: PB2
//   delayMicroseconds(100); 
//   PORTD |= 0xF0; // mise a 1 des DATA: DDRD bits de poids fort
//   delayMicroseconds(100); 
//   PORTB &=~ 0x04;
//   delayMicroseconds(50); 
//   PORTB &=~ 0x01;
//   PORTD &=~ 0xF0; // mise a 0 des DATA: DDRD bits de poids fort
// }
// ///////////////////////////////////////////////////////////////
// void write4bits(uint8_t value) { // ecrriture des bits de poids foirt
//   for (int i = 0; i < 4; i++) {
//     digitalWrite(_data_pins[i], (value >> i) & 0x01);
//   }
//   pulseEnable();
// }
// ///////////////////////////////////////////////////////////////
// void LiquidCrystal::write8bits(uint8_t value) {
//   for (int i = 0; i < 8; i++) {
//     digitalWrite(_data_pins[i], (value >> i) & 0x01);
//   }
  
//   pulseEnable();
// }
