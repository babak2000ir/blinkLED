                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  DDRB = 0xff;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */

  // ------ Event loop ------ //
  while (1) {

int a=5;
    PORTB = 0b01000010;          
    _delay_ms(a); 
                                         
    PORTB = 0b000000000;          
    _delay_ms(a); 


    PORTB = 0b00000001;          
    _delay_ms(a); 
                                         
    PORTB = 0b000000000;          
    _delay_ms(a); 

    PORTB = 0b00111100;          
    _delay_ms(a); 
                                         
    PORTB = 0b11111111;          
    _delay_ms(a);


  }                                                  
  return 0;                     
}
