/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on June 3, 2024, 9:56 PM
 */


#include <xc.h>
#include"configurationBits.h"


void main(void) {
    //Incio de programa o configuraciones generales Setup
    
    // Configuramos el puerto D como salida
    PORTD = 0x00;
    LATD = 0x00;
    TRISD = 0x00;
    
    
    
    
    
    
    while(1){
        // Ciclo Infinito
        LATD = 0xFF;
        __delay_ms(500);
        LATD = 0x00;
        __delay_ms(500);
        
    }
    return;
}
