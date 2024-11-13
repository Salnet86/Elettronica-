#include <xc.h>


#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (ad esempio 4 MHz)
#define TEMP_SENSOR_PIN 0 // Porta analogica AN0 per il LM35


Configurazione dei fuse
#pragma config FOSC = INTRC_NOCLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config MCLRE = DISATTIVATO


void principale() {
Configura il convertitore analogico-digitale (ADC)
ADCON1 = 0x06; Configura il Vref, disabilita i pin digitali per le analogiche
ADCON0 = 0x01; Abilita il canale AN0 (pin analogico)
    
TRISA = 0xFF; Imposta tutti i pin di porta A come ingressi (per il sensore analogico)
    TRISB = 0x00; // Imposta porta B come uscita per eventuali LED


    while(1) {
        // Avvia la conversione ADC
GO_nDONE = 1; Avvia la conversione
while(GO_nDONE); Attendi che la conversione finisca
        
Leggi il risultato della conversione
        unsigned int temperature = (ADRESH << 8) + ADRESL; // Combina i valori dei registri ADRESH e ADRESL


Poiché il LM35 fornisce 10mV per grado Celsius, 1 grado = 10 unità di ADC a 5V (su 10-bit)
temperatura del galleggianteCelsius = temperatura * 5,0 / 1024,0 * 100,0;


Usa la variabile 'tempCelsius' per prendere decisioni, ad esempio accendere un LED se la temperatura è troppo alta.
        if (tempCelsius > 30.0) {
LATBbits.LATB0 = 1; Accende il LED se la temperatura è maggiore di 30°C
        } else {
LATBbits.LATB0 = 0; Spegne il LED se la temperatura è inferiore
        }


__delay_ms(1000); Attende per 1 secondo prima della lettura successiva
    }
}

