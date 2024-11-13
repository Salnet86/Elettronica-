#include <xc.h>

Configurazione dei fuse (ad esempio per un PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Watchdog Timer disabilitato
#pragma config PWRTE = ON // Power-up Timer abilitato
#pragma config MCLRE = OFF // MCLR disabilitato
#pragma config BOREN = OFF // Brown-out Reset disabilitato
#pragma config LVP = OFF // Programmazione a bassa tensione disabilitato
#pragma config CPD = OFF // Protezione codice EEPROM dati disabilitato
#pragma config CCP2MX = PORTC // CCP2 sulla porta C

Definizioni dei pin
#define LED LATBbits.LATB0 // Pin RB0 per il LED

void main() {
// Impostazione della configurazione del microcontrollore
TRISBbits.TRISB0 = 0; // Imposta il pin RB0 come uscita

// Loop infinito
while(1) {
LED = 1; // Accende il LED
__delay_ms(1000); // Attende per 1 secondo
LED = 0; // Spegne il LED
__delay_ms(1000); // Attende per 1 secondo
}
}
