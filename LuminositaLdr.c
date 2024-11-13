#include <xc.h>


#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz
#define LDR_SENSOR_PIN 0 // Porta analogica AN0 per l'LDR


Configurazione dei fuse
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = DISATTIVATO


void principale() {
Configura il convertitore analogico-digitale (ADC)
ADCON1 = 0x06; Configura il Vref, disabilita i pin digitali per le analogiche
ADCON0 = 0x01; Abilita il canale AN0 (pin analogico)


TRISA = 0xFF; Imposta tutti i pin di porta A come ingressi
    TRISB = 0x00; // Imposta porta B come uscita (per eventuali LED)


    while(1) {
        // Avvia la conversione ADC
GO_nDONE = 1; Avvia la conversione
while(GO_nDONE); Attendi che la conversione finisca
        
Leggi il risultato della conversione
        unsigned int ldrValue = (ADRESH << 8) + ADRESL; // Combina i valori dei registri ADRESH e ADRESL


Se il valore di ldrValue è basso, significa che c'è poca luce
        if (ldrValue < 512) { // Soglia di esempio
LATBbits.LATB0 = 1; Accende il LED (simulando un'azione al buio)
        } else {
LATBbits.LATB0 = 0; Spegne il LED (simulando luce sufficiente)
        }


__delay_ms(1000); Attende per 1 secondo prima della lettura successiva
    }
}

