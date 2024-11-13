#include <xc.h>
#define _XTAL_FREQ 4000000 // Frequenza dell'oscillatore in Hz (ad esempio 4 MHz)


#define RS LATBbits.LATB0 // Pin RS collegato a RB0
#define EN LATBbits.LATB1 // Pin EN collegato a RB1
#define D4 LATBbits.LATB2 // Pin D4 collegato a RB2
#define D5 LATBbits.LATB3 // Pin D5 collegato a RB3
#define D6 LATBbits.LATB4 // Pin D6 collegato a RB4
#define D7 LATBbits.LATB5 // Pin D7 collegato a RB5


// Configurazione dei fuse (per esempio per PIC16F84A)
#pragma config FOSC = INTRC_NOCLKOUT // Oscillatore interno
#pragma config WDTE = OFF // Timer watchdog disabilitato
#pragma config PWRTE = ON // Timer di accensione abilitato
#pragma config MCLRE = OFF // MCLR disabilitato


Funzione per un breve ritardo (in millisecondi)
void delay_ms(unsigned int ms) {
    while(ms--) {
__delay_ms, paragrafo 1;
    }
}


// Funzione per inviare un comando al display LCD
void lcd_send_command(unsigned char cmd) {
RS = 0; Seleziona il registro di comando
    D4 = (cmd >> 4) & 0x01;
    D5 = (cmd >> 5) & 0x01;
    D6 = (cmd >> 6) & 0x01;
    D7 = (cmd >> 7) & 0x01;
EN = 1; Attiva il display
__delay_ms, paragrafo 1;
EN = 0; Disattiva il display
    
    D4 = cmd & 0x01;
    D5 = (cmd >> 1) & 0x01;
    D6 = (cmd >> 2) & 0x01;
    D7 = (cmd >> 3) & 0x01;
EN = 1; Attiva il display
__delay_ms, paragrafo 1;
EN = 0; Disattiva il display
}


// Funzione per inviare un carattere al display LCD
void lcd_send_data(dati char senza segno) {
RS = 1; Seleziona il registro dei dati
D4 = (dati >> 4) & 0x01;
D5 = (dati >> 5) & 0x01;
D6 = (dati >> 6) & 0x01;
D7 = (dati >> 7) & 0x01;
EN = 1; Attiva il display
__delay_ms, paragrafo 1;
EN = 0; Disattiva il display
    
D4 = dati & 0x01;
D5 = (dati >> 1) & 0x01;
D6 = (dati >> 2) & 0x01;
D7 = (dati >> 3) & 0x01;
EN = 1; Attiva il display
__delay_ms, paragrafo 1;
EN = 0; Disattiva il display
}


// Funzione per inizializzare il display LCD
void lcd_init() {
TRISB = 0x00; Imposta i pin RB0 a RB5 come uscite


delay_ms(20); Attendi che il display si accenda
lcd_send_command(0x02); Imposta la modalità 4 bit
lcd_send_command(0x28); Imposta 2 righe, 5x8 font
lcd_send_command(0x0C); Abilita il display, senza il cursore
lcd_send_command(0x06); Incrementa automaticamente la posizione del cursore
lcd_send_command(0x01); Pulisce lo schermo
delay_ms, paragrafo 2; Aspetta che il display esegua il comando
}


// Funzione per stampare una stringa sul display LCD
void lcd_print(const char *str) {
    while(*str) {
        lcd_send_data(*str++);
    }
}


void principale() {
    lcd_init(); // Inizializza il display LCD
lcd_print("Ciao PIC16!"); Visualizza un messaggio


    while(1) {
Loop infinito
    }
}

