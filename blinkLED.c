                                                       /* Blinker Demo */

// ------- Preamble -------- //
#include <avr/io.h>                        /* Defines pins, ports, etc */
#include <util/delay.h>                     /* Functions to waste time */


int main(void) {

  // -------- Inits --------- //
  DDRB |= 0b00000001;            /* Data Direction Register B:
                                   writing a one to the bit
                                   enables output. */

  // ------ Event loop ------ //
  while (1) {

    PORTB = 0b00000001;          
    _delay_ms(100);                                           

    PORTB = 0b00000000;          
    _delay_ms(100);     

        PORTB = 0b00000001;          
    _delay_ms(100);                                           

    PORTB = 0b00000000;          
    _delay_ms(100);  

        PORTB = 0b00000001;          
    _delay_ms(100);                                           

    PORTB = 0b00000000;          
    _delay_ms(1000);                                        

  }                                                 
  return 0;                            
}
