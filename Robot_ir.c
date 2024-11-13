#include <xc.h>
#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (es. 4 MHz)


// Definisci i pin per i sensori IR
#define SENSOR_LEFT PORTBbits.RB0
#define SENSOR_RIGHT PORTBbits.RB1


Definisci i pin per i motori
#define MOTOR_1A LATBbits.LATB2
#define MOTOR_1B LATBbits.LATB3
#define MOTOR_2A LATBbits.LATB4
#define MOTOR_2B LATBbits.LATB5


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


Funzione per muovere il robot in avanti
void move_forward() {
    MOTOR_1A = 1;
    MOTOR_1B = 0;
    MOTOR_2A = 1;
    MOTOR_2B = 0;
}


Funzione per muovere il robot a destra
void turn_right() {
    MOTOR_1A = 0;
    MOTOR_1B = 1;
    MOTOR_2A = 1;
    MOTOR_2B = 0;
}


Funzione per muovere il robot a sinistra
void turn_left() {
    MOTOR_1A = 1;
    MOTOR_1B = 0;
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
TRISB = 0x03; Imposta i pin RB0 e RB1 come ingresso (sensori IR), gli altri come uscita


    while(1) {
        if (SENSOR_LEFT == 1 && SENSOR_RIGHT == 1) {
Entrambi i sensori vedono la linea (robot dritto)
            move_forward();
        }
        else if (SENSOR_LEFT == 1 && SENSOR_RIGHT == 0) {
Solo il sensore sinistro vede la linea (devia a destra)
            turn_right();
        }
        else if (SENSOR_LEFT == 0 && SENSOR_RIGHT == 1) {
Solo il sensore destro vede la linea (devia a sinistra)
            turn_left();
        }
        else {
Nessun sensore vede la linea (fermo o cerca la linea)
            stop();
delay_ms(100); Pausa per evitare movimenti rapidi
        }


delay_ms, paragrafo 10; Breve ritardo per stabilizzare la lettura dei sensori
    }
}

