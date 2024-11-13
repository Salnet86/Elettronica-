#include <xc.h>

Configurazione dei fuse (ad esempio per PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Watchdog Timer disabilitato
#pragma config PWRTE = ON // Power-up Timer abilitato
#pragma config MCLRE = OFF // MCLR disabilitato

#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (ad esempio 4 MHz)

Definizione del pin per il relè
#define RELAY_PIN LATBbits.LATB0 // Relè collegato a RB0

void main() {
TRISBbits.TRISB0 = 0; // Imposta RB0 come uscita per il relè

while (1) {
RELAY_PIN = 1; // Attiva il relè (accende il relè)
__delay_ms(1000); // Mantieni il relè attivo per 1 secondo
RELAY_PIN = 0; // Disattiva il relè (spegne il relè)
__delay_ms(1000); Mantieni il relè spento per 1 secondo
}
}
