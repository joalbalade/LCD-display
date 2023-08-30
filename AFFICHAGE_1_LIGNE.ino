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
/////////////////////////////////////////////

 lcd.begin(16, 2); // bib init (initialisation)

 pulseEnable();
//  write4bits("Bonjour");
//  write8bits("a");
}
//////////////////////////////////////////////////////////////////////////
void loop() {
 // unsigned char lettre = 'a';
}
//////////////////////////////////////////////////////////////////////////
void pulseEnable() { // affichage de caractere

   unsigned  char lettre[16] = "test :) bonjour ";

   for (int i = 0; i<strlen(lettre);i++){
      uint8_t value = lettre[i];
      PORTB |= 0x01; // mise a 1 de RS: PB0 

      PORTD = value; // upper 4 bit ascii 

      PORTB &=~ 0x04; // mise a 0 de E: PB2
      PORTB |= 0x04; // mise a 1 de E: PB2
      PORTB &=~ 0x04; // mise a 0 de E: PB2
   
      PORTD = PORTD << 4;// lower 4bit ascii
      // PORTD = 0x80; // lower 4bit ascii
      //delayMicroseconds(1000);    // enable pulse must be >450ns
      time_ms();
      PORTB &=~ 0x04; // mise a 0 de E: PB2
      PORTB |= 0x04; // mise a 1 de E: PB2  
      PORTB &=~ 0x04; // mise a 0 de E: PB2
      //delayMicroseconds(100);   // commands need > 37us to settle.
      time_ms();
   }
}

void time_ms(){ //fonction  pour la temporistation
   for ( unsigned long int i = 0; i < 10000; i++ ){
    asm("nop");//nop: fonction qui permet de faire rien  
  }
}
//////////////////////////////////////////////////////////////////////////
void TIM16_WriteTCNT1( unsigned int i ) // permet d'ecrire dans le timer 1///// TIM16_WriteTCNT1( 0x2326 );
{
unsigned char sreg;
/* Save global interrupt flag */
sreg = SREG;
/* Disable interrupts */
cli();
/* Set TCNT1 to i */
TCNT1 = i;
/* Restore global interrupt flag */
SREG = sreg;
}
//////////////////////////////////////////////////////////////////////////
unsigned int TIM16_ReadTCNT1( void ) //permet de lire la valeur du timer 1
{
unsigned char sreg;
unsigned int i;
/* Save global interrupt flag */
sreg = SREG;
/* Disable interrupts */
cli(); // permet le processeur de ne pas s'arret a cause d'un evenement exterieur
/* Read TCNT1 into i */
i = TCNT1;
/* Restore global interrupt flag */
SREG = sreg;
return i;
}
//////////////////////////////////////////////////////////////////////
// void Sep_car(char mot) { // ecrriture des bits de poids foirt
//   pulseEnable();
// }
//////////////////////////////////////////////////////////////////////

// int rs = 8;
// int enable = 10 ;

// int d4 = 4;
// int d5 = 5;
// int d6 = 6;
// int d7 = 7;




// void Init_LiquidCrystal(uint8_t rs, uint8_t enable,
//            uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
// {
//   init(0, rs, 0, enable, 0, 0, 0, 0, d4, d5, d6, d7);
// }



// void init(uint8_t fourbitmode, uint8_t rs, uint8_t rw, uint8_t enable,
//       uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3,
//       uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
// {
//   uint8_t _rs_pin = rs;
//   uint8_t _rw_pin = rw;
//   uint8_t _enable_pin = enable;
//   uint8_t _data_pins[7] = {0 0 0 0 0 0 0 0};
//   _data_pins[0] = d0;
//   _data_pins[1] = d1;
//   _data_pins[2] = d2;
//   _data_pins[3] = d3; 
//   _data_pins[4] = d4;
//   _data_pins[5] = d5;
//   _data_pins[6] = d6;
//   _data_pins[7] = d7; 

//   if (fourbitmode){
//     _displayfunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS;
//   else 
//     _displayfunction = LCD_8BITMODE | LCD_1LINE | LCD_5x8DOTS;
//   }
//   begin(16, 1);  
// }
