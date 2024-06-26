/*
 * File:   main.c
 * Author: Ing. Gustavo David Mendoza Pinto
 *
 * Created on March 21, 2024, 7:35 PM
 * 
 * Control de entradas y salidas digitales
 * Ejercicio simple sobre configuracion de los puertos A, B, C y D como digita-
 * -les, Realizando una calculadora binaria simple con operaciones de suma, res-
 * -ta y operacioies lógicas.
 */


#include <xc.h>
#include "configurationBits.h"

void main(void) {
    // Setup code here
    
    //Configuracion del puerto A
    
    PORTA = 0x00;
    LATA = 0x00;
    ADCON1 = 0x0F;
    CMCON = 0x07;
    TRISA |= 0x3F; //
    
    //Configuración del puerto B
    PORTB = 0x00;
    LATB = 0x00;
    TRISB = 0xFF; // Todo el puerto como entrada
    
    
    // Configuracion del Puerto C
    PORTC = 0x00;
    LATC = 0x00;
    //UCONbits.USBEN = 0;
    UCON &= 0b11110111;
    //UCFGbits.UTRDIS = 1;
    UCFG |= 0b00001000;
    
    TRISC |= 0xF0; // Puerto C < 7 : 4 > como entradas
    
    // COnfiguración del puerto D
    PORTD = 0x00;
    LATD = 0x00;
    TRISD = 0x00; // Todo el puerto D como Salida
    unsigned char data;
    
    
    
    
    while(TRUE){
        // Loop code here
        data  = PORTC >> 4;
        switch(data){
            case 0:
                LATD = PORTA;
                break;
            case 1:
                LATD = PORTB;
                break;
            case 2:
                LATD = PORTB + PORTA;
                break;
            case 3:
                LATD = PORTB - PORTA;
                break;
            case 4:
                LATD = PORTB & PORTA;
                break;
            case 5:
                LATD = PORTB | PORTA;
                break;
            case 6:
                LATD = PORTB ^ PORTA;
                break;
            case 7:
                LATD = ~PORTB;
                break;
            case 8:
                LATD = ~PORTA;
                break;
            case 9:
                LATD = PORTB << 4;
                break;
            case 10: 
                LATD = PORTA << 4;
                break;
            default:
                LATD = 0xF0;
                break;
        }
        
        __delay_ms(10);
    }
    
    return;
}