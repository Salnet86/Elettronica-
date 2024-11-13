#include <xc.h>


#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (4 MHz)
#define STEP_PIN1 LATBbits.LATB0 // Pin RB0 per il controllo della fase 1
#define STEP_PIN2 LATBbits.LATB1 // Pin RB1 per il controllo della fase 2
#define STEP_PIN3 LATBbits.LATB2 // Pin RB2 per il controllo della fase 3
#define STEP_PIN4 LATBbits.LATB3 // Pin RB3 per il controllo della fase 4


// Configurazione dei fuse (per esempio per PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Timer watchdog disabilitato
#pragma config PWRTE = ON // Timer di accensione abilitato
#pragma config MCLRE = OFF // MCLR disabilitato


void delay_ms(unsigned int ms) {
    while(ms--) {
__delay_ms, paragrafo 1;
    }
}


void step_motor(passaggio char senza segno) {
Ogni passo del motore passo-passo è una sequenza di accensione dei pin in un ordine specifico.
interruttore(passo) {
Caso 0:
            STEP_PIN1 = 1; STEP_PIN2 = 0; STEP_PIN3 = 0; STEP_PIN4 = 0;
rompere;
Caso 1:
            STEP_PIN1 = 0; STEP_PIN2 = 1; STEP_PIN3 = 0; STEP_PIN4 = 0;
rompere;
Caso 2:
            STEP_PIN1 = 0; STEP_PIN2 = 0; STEP_PIN3 = 1; STEP_PIN4 = 0;
rompere;
Caso 3:
            STEP_PIN1 = 0; STEP_PIN2 = 0; STEP_PIN3 = 0; STEP_PIN4 = 1;
rompere;
    }
}


void principale() {
TRISB = 0x00; Imposta porta B come uscita (per il controllo dei pin del motore)


passaggio di caratteri senza segno = 0; Variabile per tenere traccia del passo corrente


    while(1) {
Esegui un passo del motore
step_motor(passo);
passo = (passo + 1) % 4; Incrementa il passo (0-3) e ritorna a 0 dopo 3


delay_ms(100); Attendi per 100ms tra un passo e l'altro
    }
}

