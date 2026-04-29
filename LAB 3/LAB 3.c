#define F_CPU 16000000UL 
#include <util/delay.h> 
#include <avr/io.h> 
#define BAUD 9600                                    
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1) 
#include <avr/io.h> 
 
 
unsigned char keychar[4][4] =  {{'1','2','3','A'}, 
                                {'4','5','6','B'}, 
                                {'7','8','9','C'}, 
                                {'*','0','#','D'}}; 
 
void uart_initialization (void) 
{ 
 UBRR0H = (BAUDRATE>>8);        // shift the register right by 8 bits 
 UBRR0L = BAUDRATE;             // set baud rate 
 UCSR0B|= (1<<TXEN0)|(1<<RXEN0);  // enable receiver and transmitter 
 UCSR0C|= (1<<UCSZ00)|(1<<UCSZ01);   // 8bit data format 
} 
 
uart_transmission (unsigned char data) { 
 while (!( UCSR0A & (1<<UDRE0))); // wait while register is free 
 UDR0 = data; // load data in the register 
} 
 
int main(void) 
{ 
 uart_initialization(); 
 DDRD |= (1<<DDD4|1<<DDD5|1<<DDD6|1<<DDD7); 
 DDRB &= ~(1<<DDB0&1<<DDB1&1<<DDB2&1<<DDB3); 
    /* Replace with your application code */ 
    while (1)  
    { 
  PORTD |= (1<<4|1<<5|1<<6|1<<7); 
  PORTB |= (1<<0|1<<1|1<<2|1<<3); 
  for(int r = 0; r < 4; r++){ 
   PORTD &= ~(1<< r + 4); 
   for(int c = 0; c < 4; c++){ 
    if (!(PINB & (1 << c))){ 
     uart_transmission(keychar[r][c]); 
       while(!(PINB & (1 << c)));  
                                                   PORTD |= (1<<(r+4)); 
    } 
   } 
  } 
  _delay_ms(250); 
    } 
} 