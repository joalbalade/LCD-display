// LCD1602 to Arduino Uno connection example

#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 10, 4, 5, 6, 7); // bib init (initialisation)

void pulse(){
  PORTB &=~ 0x04; // mise a 0 de E: PB2
  PORTB |= 0x04; // mise a 1 de E: PB2  
  PORTB &=~ 0x04; // mise a 0 de E: PB2
  time_ms();
}

void setup() {
  
  DDRB |= 0x01;// PB0 en sortie RS: signal pour afficher les DATA 
  DDRB |= 0x04;// PB2 en sortie E: autorisation de l'afficher des DATA 

  DDRD |= 0x80; // PD 7 en sortie
  DDRD |= 0x40; // PD 6 en sortie
  DDRD |= 0x20; // PD 5 en sortie
  DDRD |= 0x10; // PD 4 en sortie
  initialisation();
   // un masque pour chaque bit de DDRD correspond au DATA
  
/////////////////////////////////////////////

 lcd_begin();
 //lcd.begin(16, 2); // bib init (initialisation)
}
//////////////////////////////////////////////////////////////////////////
void loop() {
  decal_cursor_col();
  write_word_1();
  decal_cursor_row();
  write_word_2();
}
//////////////////////////////////////////////////////////////////////////

void initialisation(){
  PORTB |= 0x01; // mise a 1 de RS: PB0
  PORTB |= 0x04; // mise a 1 de E: PB2
  PORTD = 0xF0;
}

//FONCTION D'INITIALISATION (correspond au lcd.begin(16,2))
void lcd_begin(){
  for ( unsigned long int i = 0; i < 3000000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x30;
  pulse();

  for ( unsigned long int i = 0; i < 1000000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x30;
  pulse();

  for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x30;
  pulse();

  for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x20;
  pulse();

    for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x20;
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0xC0;
  pulse();

  for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x00;
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x80;

  for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x00;
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x10;
  pulse();

  time_ms();
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x00;
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x40;
  pulse();

  for ( unsigned long int i = 0; i < 50000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x00;
  pulse();
  PORTB &=~ 0x01;
  PORTD &=~ 0xF0;
  PORTD |= 0x02;
  pulse();
}

//FONCTION DE TEMPORISATION
void time_ms(){
  for ( unsigned long int i = 0; i < 10000; i++ ){
    asm("nop"); //nop: instruction assembleur qui ne fait rien  
  }
}

//DECALAGE CURSEUR COLONNES
void decal_cursor_col(){
  PORTB &=~ 0x01;
  uint8_t value = 0x85;
  PORTD = value; // upper 4 bit ascii 

  pulse();
  
  PORTD = PORTD << 4;// lower 4bit ascii
  
  time_ms();
  pulse();

}

//DECALAGE CURSEUR LIGNES
void decal_cursor_row(){
  PORTB &=~ 0x01; //Mise à 0 de RS
  uint8_t value = 0xC0;
  PORTD = value; // upper 4 bit ascii 

  pulse();
   
  PORTD = PORTD << 4;// lower 4bit ascii
  
  time_ms();
  pulse();

}

//ECRITURE DU 1ER MOT
void write_word_1(){
  unsigned  char mot[16] = "PROJET";

  for (int i = 0; i<strlen(mot);i++){
  uint8_t value = mot[i];
  PORTB |= 0x01; // mise a 1 de RS: PB0 
  PORTD = value; // upper 4 bit ascii 

  pulse();
  PORTD = PORTD << 4;// lower 4bit ascii
  
  time_ms();
  pulse();
  }
}

// ECRITURE DU 2EME MOT
void write_word_2(){
  unsigned  char mot[16] = "MICROCONTROLEUR";

  for (int i = 0; i<strlen(mot);i++){
  uint8_t value = mot[i];
  PORTB |= 0x01; // mise a 1 de RS: PB0 
  PORTD = value; // upper 4 bit ascii 

  pulse();
   
  PORTD = PORTD << 4;// lower 4bit ascii
  
  time_ms();
  pulse();
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
