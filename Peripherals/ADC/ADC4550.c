/*
 * File:   ADC4550.c
 * Author: gustavomendoza
 *
 * Created on August 2, 2023, 1:55 PM
 */


#include <xc.h>
#include"ADC4550.h"

void initADC(uint8_t xtal_frec, uint8_t channels, uint8_t justified){
    ADCON1bits.PCFG = 15 - channels;
    ADCON1bits.VCFG = 0;
    ADCON2bits.ADFM = justified; 
    switch(xtal_frec){
        case ADC_XTAL_4MHz:
            ADCON2bits.ADCS = 0b100;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 4 us
            
            break;
        case ADC_XTAL_8MHz:
            ADCON2bits.ADCS = 0b001;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 3 us
            break;
        case ADC_XTAL_20MHz:
            //configuramos el TAD
            ADCON2bits.ADCS = 0b101;
            ADCON2bits.ACQT = 2; // Tiempo de adquisición 3.2 us
            break;
        case ADC_XTAL_40MHz:
            ADCON2bits.ADCS = 0b010;
            ADCON2bits.ACQT = 2; //// Tiempo de adquisición 4 us
            break;
    }
    
    
}

uint16_t readADC(unsigned char channel){
    if(channel > 13){
        return 0;
    }
    ADCON0bits.CHS = channel;
    ADCON0bits.ADON = 1;
    ADCON0bits.GO_DONE = 1;
    while(ADCON0bits.GO_DONE);
    ADCON0bits.ADON = 0;
    return ADRES;  
}
