/* 
 * File:   libUSART18f4550.h
 * Author: gustavomendoza
 *
 * Created on July 13, 2023, 10:21 PM
 */

#ifndef EUSART18F4550_H
#define	EUSART18F4550_H

#include <xc.h>
#include <stdint.h>
#include <stdio.h>


// Baud Rate
#define BAUD_RATE_2400 0U
#define BAUD_RATE_9600 1U
#define BAUD_RATE_19200 2U
#define BAUD_RATE_57600 3U
#define BAUD_RATE_115200 4U

#define XTAL_4MHz 0U
#define XTAL_8MHz 1U
#define XTAL_20MHz 2U
#define XTAL_40MHz 3U

#define ENDLINE "\n"

// Funasiones de Trasmicion y recepsion asincrona

void setupUART(uint8_t freq, uint8_t BaudRate);
// Funciones de envio de datos por serial asincrono
void sendUART(unsigned char data);
void printUART(char *string);
void printUARTLn(char *string);
void printUARTInt(int data);
void printUARTIntLn(int data);
void printUARTFloat(float data);
void printUARTFloatLn(float data);
//FUnciones de recepcion serial asincrono
unsigned char readUART();


#endif	/* LIBUSART18F4550_H */

