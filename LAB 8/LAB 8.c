#define F_CPU 16000000UL 
 
#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <avr/eeprom.h> 
 
uint8_t EEMEM address = 0; 
uint8_t dutyCycle; 
 
int main(void) { 
     
    DDRB |= (1 << 5); 
    Timer0_Init(); 
    sei(); 
 
    dutyCycle = eeprom_read_byte(&address); 
 
    if (dutyCycle >= 100) { 
        dutyCycle = 0; 
    } else { 
        dutyCycle += 10; 
    } 
 
    eeprom_update_byte(&address, dutyCycle); 
    OCR0B = OCR0A * (dutyCycle / 100.0);  
 
    while (1) {} 
} 
 
void Timer0_Init() { 
    TCCR0A |= (1 << WGM01); 
    TCCR0B |= (1 << CS02) | (1 << CS00); 
    OCR0A = 78; 
    TIMSK0 |= (1 << OCIE0A) | (1 << OCIE0B); 
} 
 
ISR(TIMER0_COMPA_vect) { 
    PORTB |= (1 << 5); 
} 
 
ISR(TIMER0_COMPB_vect) { 
    PORTB &= ~(1 << 5); 
} 