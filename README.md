# COMPE 375 – Embedded Systems Programming

Lab assignments for an embedded systems course at San Diego State University, focused on programming the **ATmega328PB microcontroller** in C using Atmel Studio and AVR libraries.

**Topics covered:** GPIO, UART, Timers, PWM, ADC, Keypads, EEPROM

---

## Labs Overview

| Lab | Topic | Description |
|-----|-------|-------------|
| Lab 1 | GPIO & Morse Code | Blinks an LED on pin PB5 to output a name and ID in Morse code |
| Lab 2 | UART Transmission | Transmits a string over UART to a terminal via an FT232R breakout board |
| Lab 3 | UART + Keypad Input | Reads keypad button presses and sends the corresponding character to a terminal over UART |
| Lab 4 | PWM & Button Control | Gradually brightens/dims an LED using PWM based on a button press/release |
| Lab 5 | Timers & Tone Generation | Plays musical tones through an AUX speaker based on keypad input using CTC timer mode |
| Lab 6 | Keypad + PWM LED Control | Controls LED brightness via PWM based on which key is pressed on a 4x4 keypad |
| Lab 7 | ADC + Potentiometer | Reads analog input from a potentiometer via ADC and maps it to LED brightness using PWM |
| Lab 8 | EEPROM Persistence | Persists LED duty cycle across power cycles using EEPROM read/write |

---

## Hardware

- **Microcontroller:** ATmega328PB (Atmel AVR 8-bit)
- **Peripherals used:** LEDs, push buttons, 4x4 matrix keypad, potentiometer, AUX speaker, FT232R UART breakout board

---

## Project Structure

```
COMPE375-Embedded-Systems/
├── Lab 1/
│   ├── LAB 1.c
│   
├── Lab 2/
│   ├── LAB 2.c
│   
├── Lab 3/
│   ├── LAB 3.c
│   
├── Lab 4/
│   ├── LAB 4.c
│   
├── Lab 5/
│   ├── LAB 5.c
│  
├── Lab 6/
│   ├── LAB 6.c
│   
├── Lab 7/
│   ├── LAB 7.c
│   
└── Lab 8/
    ├── LAB 8.c
```

---

## Key Concepts Practiced

- **GPIO** – Configuring pins as input/output using DDR and PORT registers
- **UART** – Serial communication using USART registers at 9600 baud
- **Timers (CTC mode)** – Generating precise time intervals using Timer0/Timer2 with prescalers
- **PWM** – Controlling LED brightness via duty cycle using OCR registers
- **ADC** – Reading analog voltage from a potentiometer and mapping it to digital output
- **Interrupts** – Using ISRs for timer compare matches and ADC conversion complete events
- **EEPROM** – Reading and writing persistent data across power cycles using `avr/eeprom.h`

---

## Author

**Abdulmohsen Almunayes**  
Computer Engineering – San Diego State University  
GitHub: [@ASM701](https://github.com/ASM701)