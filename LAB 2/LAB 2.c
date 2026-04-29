#define F_CPU 16000000UL 
 
#include <util/delay.h> 
 
#include <avr/io.h> 
 
#define BAUD 9600                                   // define baud 
 
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate 
 
 
 
 
 
void uart_init (void) 
 
{ 
 
UBRR0H = (BAUDRATE>>8);        // shift the register right by 8 bits 
 
UBRR0L = BAUDRATE;             // set baud rate 
 
UCSR0B|= (1<<TXEN0) | (1<<RXEN0);  // enable transmitter and receiver 
(respectively) 
 
UCSR0C|= (1<<UCSZ00) | (1<<UCSZ01);   // 8bit data format 
 
} 
 
 
 
uart_transmit (unsigned char data) { 
 
while (!( UCSR0A & (1<<UDRE0))); // wait until the buffer is free 
 
UDR0 = data; // load the data in the register 
 
} 
 
 
 
int main(void) 
 
{ 
 
 
 
uart_init(); 
 
char red_ID[] = "823343580\r\n"; 
 
while (1) 
 
{ 
 
for(int i = 0; i < sizeof(red_ID); i++){ 
 
uart_transmit(red_ID[i]); 
 
} 
 
_delay_ms(500); 
 
} 
 
}