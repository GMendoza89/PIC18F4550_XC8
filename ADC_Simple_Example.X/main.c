/*
 * File:   main.c
 * Author: gustavomendoza
 *
 * Created on June 26, 2024, 12:09 PM
 * 
 * Ejemplo simple de uso de convertidor Analógico Digital (ADC). 
 * Lectura de canal 0 y visualización de los 8 bits más significativos por el
 * puerto D con LEDs.
 * Pic con Oscilador de cristal externo de 20 MHz
 */


#include <xc.h>
#include <stdint.h>
#include "configurationBits.h"
#include "../Peripherals/ADC/ADC4550.h"

void main(void) {
    // Setup code here
    
    //Configuración del puerto D como salida
    PORTD = 0x00;
    LATD = 0x00;
    TRISD = 0x00;
    
    // Inicializando el ADC
    initADC(ADC_XTAL_20MHz, 1, JUSTIFIED_RIGHT);
    
    uint16_t data;
    while(TRUE){
        // Loop code here
        data = readADC(AN0);
        LATD = ADRESH;
        __delay_ms(10);
        
    }
    
    return;
}
