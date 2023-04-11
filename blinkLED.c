#include <avr/io.h>			/* Include AVR std. library file */
#include <util/delay.h>			/* Include Delay header file */

#define LCD_DATA PORTB         // port B is selected as LCD data port
#define color_port PORTC
#define en PC5                 // enable signal is connected to port D pin 7
#define rs PC4                  // register select signal is connected to port D pin 5

void LCD_cmd(unsigned char cmd);
void init_LCD(void);
void LCD_write(unsigned char data);

// -------- Functions --------- //
static inline void initADC0(void) {
  ADMUX |= (1 << REFS0);                  /* reference voltage on AVCC */
  ADMUX |= 0b00000011;                    /* use ADC0 (PC0) as input */
  ADCSRA |= (1 << ADPS2);                   /* ADC clock prescaler /16 */
  ADCSRA |= (1 << ADEN);                                 /* enable ADC */
}

unsigned int color = 0b00000000;

int main(void)
{
  DDRB=0xFF;              // set LCD data port as output
  DDRC=0xFF;              // RGB

  uint16_t adcValue;
  uint8_t i;
  initADC0();

  init_LCD();             // initialize LCD
  _delay_ms(20);         

  LCD_cmd(0x0C);          // display on, cursor off 
  LCD_writestr("Voltage:");        // call a function to display “Atmega32” on LCD
  

  while (1) {
    LCD_cmd(0xC0);          // move cursor to the start of 2nd line

    ADCSRA |= (1 << ADSC);                     /* start ADC conversion */
    loop_until_bit_is_clear(ADCSRA, ADSC);          /* wait until done */
    adcValue = ADC;                                     /* read ADC in */
                        /* Have 10 bits, want 3 (eight LEDs after all) */

    
    //LCD_cmd(0x0C);          // display on, cursor off

    LCD_writeIntAsStr(adcValue/201); // call a function to display “Microcontroller” on LCD
    //LCD_writeIntAsStr(23);
    //LCD_writestr("0.00V");
    //clear the screen
    //LCD_cmd(0x01);          // make clear LCD

    _delay_ms(20);
  }

  LCD_cmd(0x0E);          // make display ON, cursor ON

  return 0;
}

void init_LCD(void)
{
  LCD_cmd(0x38);           // initialization in 8bit mode of 16X2 LCD
  _delay_ms(1);

  LCD_cmd(0x01);          // make clear LCD
  _delay_ms(1);

  LCD_cmd(0x02);          // return home
  _delay_ms(1);

  LCD_cmd(0x06);          // make increment in cursor
  _delay_ms(1);

  LCD_cmd(0x80);          // “8” go to first line and “0” is for 0th position
  _delay_ms(1);

  return;
}

 

//**************sending command on LCD***************//
void LCD_cmd(unsigned char cmd)
{
  LCD_DATA = cmd;      // data lines are set to send command

  PORTC  &= ~(1<<rs);  // RS sets 0
  PORTC  |= (1<<en);   // make enable from high to low
  _delay_ms(1);
  PORTC  &= ~(1<<en);

  return;
}

 

//*****************write data on LCD*****************//

void LCD_write(unsigned char data)
{
  LCD_DATA= data;       // data lines are set to send command

  PORTC  |= (1<<rs);    // RS sets 1
  PORTC  |= (1<<en);    // make enable from high to low
  _delay_ms(1);
  PORTC &= ~(1<<en);

  return ;
}

void LCD_writestr(char *str)
{
  int i=0;
  while(str[i]!=0)
  {
    LCD_write(str[i]);
    //_delay_ms(30);
    //LCD_toggle_color();
    i++;
  }
}

void LCD_writeIntAsStr(uint16_t number)
{
  char buffer[5];
  //itoa(number, buffer, 10);
  sprintf(buffer,"%04d",number);
  LCD_writestr(buffer);
}

void LCD_toggle_color()
{
  color++;

  if (color > 7)
  {
    color = 0;
  }

  color_port = color;
  //set color to navy
  //color_port = 0b00000001;

  //set color to purple
  //color_port = 0b00000010;

  //set color to blue
  //color_port = 0b00000011;

  //set color to yellow
  //color_port = 0b00000100;

  //set color to green
  //color_port = 0b00000101;

  //set color to red
  //color_port = 0b00000110;

  //set color to Off
  //color_port = 0b00000111;

  //set color to white
  //color_port = 0b00000000; 
}