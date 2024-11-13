#include <xc.h>
#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz


Definisci i pin per il controllo motori
#define MOTOR_1A LATBbits.LATB2
#define MOTOR_1B LATBbits.LATB3
#define MOTOR_2A LATBbits.LATB4
#define MOTOR_2B LATBbits.LATB5


Definisci i pin per il sensore ultrasonico
#define TRIG LATBbits.LATB0
#define ECHO PORTBbits.RB1


// Configurazione dei fuse (per esempio per PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Timer watchdog disabilitato
#pragma config PWRTE = ON // Timer di accensione abilitato
#pragma config MCLRE = OFF // MCLR disabilitato


void delay_us(unsigned int us) {
mentre (noi--) {
__delay_us, paragrafo 1;
    }
}


// Funzione per misurare la distanza usando il sensore HC-SR04
unsigned int measure_distance() {
    unsigned int pulse_width = 0;


Invia il trigger al sensore
    TRIG = 1;
delay_us, paragrafo 10; Impulso di 10us
    TRIG = 0;


Misura la durata del segnale di eco
while (ECHO == 0); Aspetta che il segnale Echo inizi
    while (ECHO == 1) { // Conta i microsecondi mentre Echo è alto
        pulse_width++;
delay_us, paragrafo 1;
    }


Calcola la distanza in cm (la velocità del suono è circa 343 m/s, 1 cm in 58 us)
distanza int senza segno = pulse_width / 58;
distanza di ritorno;
}


Funzione per muovere il robot in avanti
void move_forward() {
    MOTOR_1A = 1;
    MOTOR_1B = 0;
    MOTOR_2A = 1;
    MOTOR_2B = 0;
}


Funzione per muovere il robot indietro
void move_backward() {
    MOTOR_1A = 0;
    MOTOR_1B = 1;
    MOTOR_2A = 0;
    MOTOR_2B = 1;
}


Funzione per fermare il robot
void stop() {
    MOTOR_1A = 0;
    MOTOR_1B = 0;
    MOTOR_2A = 0;
    MOTOR_2B = 0;
}


void principale() {
TRISB = 0x00; Imposta tutti i pin della porta B come uscite (per motori e trigger)
distanza int senza segno;


    while(1) {
distanza = measure_distance(); Ottieni la distanza dal sensore ultrasonico


if (distanza < 10) { // Se un ostacolo è rilevato a meno di 10 cm
move_backward(); Muovi indietro
__delay_ms(1000); Continua per 1 secondo
stop(); Ferma
        } else {
move_forward(); Muovi in avanti
        }


__delay_ms(100); Pausa per evitare di fare troppe letture
    }
}

