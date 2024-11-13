#include <xc.h>


#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (ad esempio 4 MHz)


Definisci i bit per ciascun segmento
#define SEG_A LATBbits.LATB0
#define SEG_B LATBbits.LATB1
#define SEG_C LATBbits.LATB2
#define SEG_D LATBbits.LATB3
#define SEG_E LATBbits.LATB4
#define SEG_F LATBbits.LATB5
#define SEG_G LATBbits.LATB6


// Configurazione dei fuse (ad esempio per PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Timer watchdog disabilitato
#pragma config PWRTE = ON // Timer di accensione abilitato
#pragma config MCLRE = OFF // MCLR disabilitato


void delay_ms(unsigned int ms) {
    while(ms--) {
__delay_ms, paragrafo 1; Funzione di ritardo
    }
}


Funzione per visualizzare il numero sul display a 7 segmenti
void display_digit(cifra di carattere senza segno) {
Spegni tutti i segmenti
    SEG_A = 0;
    SEG_B = 0;
    SEG_C = 0;
    SEG_D = 0;
    SEG_E = 0;
    SEG_F = 0;
    SEG_G = 0;


Accendi i segmenti in base al numero da visualizzare
interruttore(cifra) {
Caso 0:
            SEG_A = 1;
            SEG_B = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_E = 1;
            SEG_F = 1;
rompere;
Caso 1:
            SEG_B = 1;
            SEG_C = 1;
rompere;
Caso 2:
            SEG_A = 1;
            SEG_B = 1;
            SEG_D = 1;
            SEG_E = 1;
            SEG_G = 1;
rompere;
Caso 3:
            SEG_A = 1;
            SEG_B = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_G = 1;
rompere;
Caso 4:
            SEG_B = 1;
            SEG_C = 1;
            SEG_F = 1;
            SEG_G = 1;
rompere;
Caso 5:
            SEG_A = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_F = 1;
            SEG_G = 1;
rompere;
Caso 6:
            SEG_A = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_E = 1;
            SEG_F = 1;
            SEG_G = 1;
rompere;
Caso 7:
            SEG_A = 1;
            SEG_B = 1;
            SEG_C = 1;
rompere;
Caso 8:
            SEG_A = 1;
            SEG_B = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_E = 1;
            SEG_F = 1;
            SEG_G = 1;
            break;
        case 9:
            SEG_A = 1;
            SEG_B = 1;
            SEG_C = 1;
            SEG_D = 1;
            SEG_F = 1;
            SEG_G = 1;
            break;
        default:
            break;
    }
}


void main() {
    TRISB = 0x00; // Imposta porta B come uscita (per i segmenti)


    unsigned char digit = 0;


    while(1) {
        display_digit(digit); // Visualizza il numero sul display
        digit = (digit + 1) % 10; // Incrementa il numero e ritorna a 0 dopo 9
        delay_ms(1000); // Attendi 1 secondo prima di cambiare il numero
    }
}

