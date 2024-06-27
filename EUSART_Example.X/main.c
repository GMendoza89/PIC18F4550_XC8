/*
 * File:   main.c
 * Author: Ing. Gustavo David Mendoza Pinto
 *
 * Created on June 27, 2024
 * 
 *  Ejemplo de uso de comunicaci�n Serial con el m�dulo EUSART
 * Lectura del puerto P y se envia como codificaci�n ASCII, y al recivir un ca-
 * -racter por la terminal de serial muestra su codificaci�n binaria a travez de
 * LEDs en el puerto D
 */


#include <xc.h>
#include "configurationBits.h"
#include "../Peripherals/EUSART/EUSART18f4550.h"

void main(void) {
    // Setup code here
    
    //Configuraci�n del puerto B como entrada
    PORTB = 0x00;
    LATB = 0x00;
    TRISB = 0xFF;
    
    //configurando bit C7 como entrada
    PORTC = 0x00;
    LATC = 0x00;
    TRISC |= 0x80;
    
    //Configuramos puerto D como salida
    PORTD = 0x00;
    LATD = 0x00;
    TRISD = 0x00;
    
    //Configuramos la trasmici�n y recepci�n serial
    
    setupUART(XTAL_20MHz, BAUD_RATE_9600);
    unsigned char *message0 = "Ing. Gustavo David Mendoza Pinto \n";
    unsigned char *message1 = "ingresa una letra para ver su combinaci�n en ASCII...";
    printUART(message0);
    printUART(message1);
    unsigned char dataOutput;
    unsigned char dataInput;
    
    while(TRUE){
        // Loop code here
        
        dataOutput =  PORTB;
        if(!PORTCbits.RC7){
            sendUART(dataOutput);
        }
        dataInput = readUART();
        
        __delay_ms(500);
        
        
        
    }
    
    return;
}
