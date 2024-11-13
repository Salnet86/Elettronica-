#include <xc.h>

Configurazione dei fuse
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Watchdog Timer disabilitato
#pragma config PWRTE = ON // Power-up Timer abilitato
#pragma config MCLRE = OFF // MCLR disabilitato

#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (ad esempio 4 MHz)

void main() {
TRISBbits.TRISB0 = 0; Imposta RB0 come uscita
T1CON = 0x30; Imposta il timer 1 (prescaler 1:8)
TMR1H = 0xFC; Imposta il valore di partenza del timer
TMR1L = 0x18;
T1CONbits.TMR1ON = 1; Accende il timer 1

while(1) {
if (TMR1IF) { // Se il flag del timer è attivo
TMR1IF = 0; // Resetta il flag del timer
LATBbits.LATB0 = ! LATBbits.LATB0; // Inverte lo stato del LED
}
}
}
