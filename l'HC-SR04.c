#include <xc.h>

#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz
#define TRIG_PIN LATBbits.LATB0
#define ECHO_PIN PORTBbits.RB1

Configurazione dei fuse
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = OFF

void main() {
TRISBbits.TRISB0 = 0; Imposta il pin TRIG come uscita
TRISBbits.TRISB1 = 1; Imposta il pin ECHO come ingresso
TRISBbits.TRISB2 = 0; Pin per eventuali LED

while (1) {
TRIG_PIN = 1; // Imposta il trigger a HIGH per 10 microsecondi
__delay_us(10); // Aspetta 10us
TRIG_PIN = 0; // Imposta il trigger a LOW

// Misura il tempo di ritorno del segnale
while (! ECHO_PIN); Aspetta che Echo diventi HIGH
TMR1 = 0; Azzeramento del timer
T1CON = 0x01; Avvia il timer 1 (prescaler 1:1)

while (ECHO_PIN); Aspetta che Echo diventi LOW
unsigned int duration = TMR1; Legge la durata del timer

// La distanza in cm è (tempo in microsecondi) / 58
unsigned int distance = duration / 58;

// Azioni in base alla distanza
if (distance < 10) {
LATBbits.LATB2 = 1; // Accende un LED se la distanza è inferiore a 10 cm
} else {
LATBbits.LATB2 = 0; // Spegne il LED se la distanza è maggiore
}

__delay_ms(500); Attende mezzo secondo prima della prossima lettura
}
}
