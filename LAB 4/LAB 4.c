#include <avr/io.h> 
#include <avr/interrupt.h> 
 
#define F_CPU 16000000UL  // AVR clock frequency 
#define LED_PIN PB5 
#define BUTTON_PIN PB7 
 
void setup_LED_Button() { 
DDRB |= (1 << LED_PIN);   // Set LED pin as output 
DDRB &= ~(1 << BUTTON_PIN);  // Set push button pin as input 
PORTB |= (1 << BUTTON_PIN);  // Enable pull-up resistor for button pin 
} 
void run_timer(int value); 
 
int main(void) { 
 
setup_LED_Button(); 
 
while (1) { 
static int brightness = 0; 
 
if (!(PINB & (1 << BUTTON_PIN))) { 
run_timer(brightness); 
if (brightness < 100) { 
brightness++; 
} 
} else { 
run_timer(brightness); 
if (brightness > 0) { 
brightness--; 
} 
} 
} 
} 
 
 
void run_timer(int value) { 
TCCR0A |= (1 << WGM01); // Set Timer0 for CTC mode 
OCR0A = 0x9B;           // Set output compare register A value 
OCR0B = value;          // Set output compare register B value 
TCCR0B |= (1 << CS00) | (1 << CS02); // Set prescale to 1024 
PORTB |= (1 << LED_PIN);   // Turn on LED 
 
while (!(TIFR0 & (1 << OCF0B))); // Wait until output compare match B 
TIFR0 |= (1 << OCF0B);  // Clear output compare flag B 
PORTB &= ~(1 << LED_PIN);    // Turn off LED 
 
while (!(TIFR0 & (1 << OCF0A))); // Wait until output compare match A 
TIFR0 |= (1 << OCF0A);  // Clear output compare flag A 
}#include <avr/io.h> 
#include <avr/interrupt.h> 
 
#define F_CPU 16000000UL  // AVR clock frequency 
#define LED_PIN PB5 
#define BUTTON_PIN PB7 
 
void setup_LED_Button() { 
DDRB |= (1 << LED_PIN);   // Set LED pin as output 
DDRB &= ~(1 << BUTTON_PIN);  // Set push button pin as input 
PORTB |= (1 << BUTTON_PIN);  // Enable pull-up resistor for button pin 
} 
void run_timer(int value); 
 
int main(void) { 
 
setup_LED_Button(); 
 
while (1) { 
static int brightness = 0; 
 
if (!(PINB & (1 << BUTTON_PIN))) { 
run_timer(brightness); 
if (brightness < 100) { 
brightness++; 
} 
} else { 
run_timer(brightness); 
if (brightness > 0) { 
brightness--; 
} 
} 
} 
} 
 
 
void run_timer(int value) { 
TCCR0A |= (1 << WGM01); // Set Timer0 for CTC mode 
OCR0A = 0x9B;           // Set output compare register A value 
OCR0B = value;          // Set output compare register B value 
TCCR0B |= (1 << CS00) | (1 << CS02); // Set prescale to 1024 
PORTB |= (1 << LED_PIN);   // Turn on LED 
 
while (!(TIFR0 & (1 << OCF0B))); // Wait until output compare match B 
TIFR0 |= (1 << OCF0B);  // Clear output compare flag B 
PORTB &= ~(1 << LED_PIN);    // Turn off LED 
 
while (!(TIFR0 & (1 << OCF0A))); // Wait until output compare match A 
TIFR0 |= (1 << OCF0A);  // Clear output compare flag A 
}