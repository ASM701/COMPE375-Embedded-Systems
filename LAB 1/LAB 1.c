#define F_CPU 16000000UL  
#include <avr/io.h> 
#include <util/delay.h> 
 
void dot(void) { 
    PORTB |= (1 << PORTB5); 
    _delay_ms(200); 
    PORTB &= ~(1 << PORTB5); 
    _delay_ms(200); 
} 
 
void dash(void) { 
    PORTB |= (1 << PORTB5); 
    _delay_ms(600); 
    PORTB &= ~(1 << PORTB5); 
    _delay_ms(200); 
} 
 
void letter_A(void) { dot(); dash(); _delay_ms(400); } 
void letter_B(void) { dash(); dot(); dot(); dot(); _delay_ms(400); } 
void letter_C(void) { dash(); dot(); dash(); dot(); _delay_ms(400); } 
void letter_D(void) { dash(); dot(); dot(); _delay_ms(400); } 
void letter_E(void) { dot(); _delay_ms(400); } 
void letter_F(void) { dot(); dot(); dash(); dot(); _delay_ms(400); } 
void letter_G(void) { dash(); dash(); dot(); _delay_ms(400); } 
void letter_H(void) { dot(); dot(); dot(); dot(); _delay_ms(400); } 
void letter_I(void) { dot(); dot(); _delay_ms(400); } 
void letter_J(void) { dot(); dash(); dash(); dash(); _delay_ms(400); } 
void letter_K(void) { dash(); dot(); dash(); _delay_ms(400); } 
void letter_L(void) { dot(); dash(); dot(); dot(); _delay_ms(400); } 
void letter_M(void) { dash(); dash(); _delay_ms(400); } 
void letter_N(void) { dash(); dot(); _delay_ms(400); } 
void letter_O(void) { dash(); dash(); dash(); _delay_ms(400); } 
void letter_P(void) { dot(); dash(); dash(); dot(); _delay_ms(400); } 
void letter_Q(void) { dash(); dash(); dot(); dash(); _delay_ms(400); } 
void letter_R(void) { dot(); dash(); dot(); _delay_ms(400); } 
void letter_S(void) { dot(); dot(); dot(); _delay_ms(400); } 
void letter_T(void) { dash(); _delay_ms(400); } 
void letter_U(void) { dot(); dot(); dash(); _delay_ms(400); } 
void letter_V(void) { dot(); dot(); dot(); dash(); _delay_ms(400); } 
void letter_W(void) { dot(); dash(); dash(); _delay_ms(400); } 
void letter_X(void) { dash(); dot(); dot(); dash(); _delay_ms(400); } 
void letter_Y(void) { dash(); dot(); dash(); dash(); _delay_ms(400); } 
void letter_Z(void) { dash(); dash(); dot(); dot(); _delay_ms(400); } 
 
 
void number_0(void) { dash(); dash(); dash(); dash(); dash(); _delay_ms(400); } 
void number_1(void) { dot(); dash(); dash(); dash(); dash(); _delay_ms(400); } 
void number_2(void) { dot(); dot(); dash(); dash(); dash(); _delay_ms(400); } 
void number_3(void) { dot(); dot(); dot(); dash(); dash(); _delay_ms(400); } 
void number_4(void) { dot(); dot(); dot(); dot(); dash(); _delay_ms(400); } 
void number_5(void) { dot(); dot(); dot(); dot(); dot(); _delay_ms(400); } 
void number_6(void) { dash(); dot(); dot(); dot(); dot(); _delay_ms(400); } 
void number_7(void) { dash(); dash(); dot(); dot(); dot(); _delay_ms(400); } 
void number_8(void) { dash(); dash(); dash(); dot(); dot(); _delay_ms(400); } 
void number_9(void) { dash(); dash(); dash(); dash(); dot(); _delay_ms(400); } 
 
void space(void) { _delay_ms(1200); } 
 
int main(void) { 
    /* Replace with your application code */ 
    DDRB |= (1 << DDB5);  // Set port bit B5 in the data direction register to 1 (configure 
as output) 
 
    while (1) { 
        letter_A(); letter_B(); letter_D(); letter_U(); letter_L(); letter_M(); letter_O(); 
letter_H(); letter_S(); letter_E(); letter_N(); 
        space(); 
 
 
        number_8(); number_2(); number_3(); number_3(); number_4(); number_3(); 
number_5(); number_8(); number_0(); 
        space(); 
    } 
} 