#define F_CPU 16000000UL 
 
#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <math.h> 
 
float keypad[4][4] = { 
    {.1, .2, .3, 0}, 
    {.4, .5, .6, 0}, 
    {.7, .8, .9, 0}, 
    {0, 0, 0, 0} 
}; 
 
volatile float tmp = 0; 
 
void keypad_Init() { 
    DDRD |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); 
    PORTD |= (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); 
    DDRB &= ~(1 << 0) & ~(1 << 1) & ~(1 << 2) & ~(1 << 3); 
    PORTB |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3); 
    DDRB |= (1 << 5); 
} 
 
// X = 5 + 1 = 6ms 
// (Ps / 16MHz) * 2^8 = (1024/16*10^6) = 0.016384s = 16.384ms 
// Timer 0 = 256*6000/16384 = 93 
void timer_0() { 
    TCCR0A |= (1 << WGM01); 
    TCCR0B |= (1 << CS02) | (1 << CS00); // prescaler of 1024 
    OCR0A = 93; 
    TIMSK0 |= (1 << OCIE0A); 
} 
 
//  Z = (0 + 1) * 100 = 100Hz 
// (10000 * 256)/16384 = 156 - 1 = 155 
void timer_2() { // LED timer 
    TCCR2A |= (1 << WGM21); 
    TCCR2B |= (1 << CS22) | (0 << CS20); // prescaler of 1024 
    OCR2A = 155; 
    OCR2B = floor(tmp * OCR2A); 
    TIMSK2 |= (1 << OCIE2A | 1 << OCIE2B); 
} 
 
ISR(TIMER2_COMPA_vect) { // TURN ON LED 
    PORTB |= (1 << 5); 
} 
 
ISR(TIMER2_COMPB_vect) { // TURN OFF LED 
    PORTB &= ~(1 << 5); 
} 
 
int main() { 
    keypad_Init(); 
    timer_0(); 
    timer_2(); 
    sei(); 
 
    while (1) { 
    } 
 
    return 0; 
} 
 
ISR(TIMER0_COMPA_vect) { 
    for (int i = 0; i < 4; i++) { 
        PORTD &= ~(1 << (i + 4)); 
        for (int j = 0; j < 4; j++) { 
            if (!(PINB & (1 << j))) { 
                OCR2B = floor(keypad[i][j] * OCR2A); 
            } 
        } 
        PORTD |= (1 << (i + 4)); 
    } 
} 