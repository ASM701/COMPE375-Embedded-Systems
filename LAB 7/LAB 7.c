#include <avr/io.h> 
#include <avr/interrupt.h> 
#include <math.h> 
 
#define F_CPU 16000000 
 
uint16_t a; 
 
// X = 5 + 1 = 6ms 
// (Ps / 16MHz) * 2^8 = (1024/16*10^6) = 0.016384s = 16.384ms 
// Timer 0 = 256*6000/16384 = 93 
 
void timer_0(){ //ADC timer 
    TCCR0A |= (1<<WGM01); 
    TCCR0B |= (1 << CS02) | (0 << CS01) | (1 << CS00); //pre-scale of 1,024 
    OCR0A  = 93; 
    TIMSK0 |= (1<<OCIE0A); 
} 
 
//  Z = (0 + 1) * 100 = 100Hz 
// (10000 * 256)/16384 = 156 - 1 = 155 
 
void timer_2(){  //PWM timer 
    TCCR2A |= (1<<WGM21); 
    TCCR2B |= (1 << CS22) | (0 << CS21) | (1 << CS20); //pre-scale of 1024 
    OCR2A = 155; 
    TIMSK2 |= (1<<OCIE2A | 1<<OCIE2B); 
} 
 
void adc_init(void){ 
     
    DDRC &= ~(1 << PINC2); // Setting input 
    ADMUX |= (1<<6) | (1<<1); 
    //ADMUX |= (1 << REFS0) | (1 << MUX1) | (1 << MUX0); //VCC reference 
    ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS1) | (1 <<ADPS0); // Enable ADC Auto Trigger & Conversion Complete Interrupt 
    ADCSRB |= (1 << ADTS1) | (1 << ADTS0); //Compare Match 
} 
 
 
 
int main(){ 
     
DDRB |= (1<<5); 
    adc_init(); 
    timer_0(); 
    timer_2(); 
    sei(); 
    while (1){} 
} 
 
ISR(TIMER2_COMPA_vect){ 
    PORTB |= (1 << 5); 
} 
 
ISR(TIMER2_COMPB_vect){ 
    PORTB &= ~(1 << 5); 
} 
 
ISR(ADC_vect){ 
    uint16_t variable = ADC; 
    a = variable; 
     
    if (a == 0) 
        OCR2B = 0; 
    else 
        OCR2B = (OCR2A * (a / 1023.0)) - 1; 
}