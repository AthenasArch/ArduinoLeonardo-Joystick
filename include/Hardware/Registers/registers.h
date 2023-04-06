#ifndef REGISTERS_H_
#define REGISTERS_H_

#include <Arduino.h>

//  bitwise
//  https://playground.arduino.cc/Code/BitMath/

//  PORTS ARDUINO UNO (328p)
//
//  port B (digital pin 8 to 13)
//  port C (analog input pins)
//  port D (digital pins 0 to 7)

// Cada port é controlada por três registradores: 
//
//  - O registro DDR determina se o pino e uma entrada ou uma saída. 
//  - O registro PORT controla se o pino e ALTO ou BAIXO
//  - O registro PIN le o estado dos pinos INPUT configurados para entrada com pinMode ()
//
//  Os registros DDR e PORT podem ser gravados e lidos. 
//  Os registros PIN correspondem ao estado das entradas e só podem ser lidos.

// PB5  // (ARDUINO) 13
// PB4  // (ARDUINO) 12
// PB0  // (ARDUINO) 8


//  inverte nível lógico do pino
#define MODE_INPUT 	0
#define MODE_OUTPUT	1

#define PIN_MODE_INPUT(DDR, _PIN) (DDR &= ~(1<<_PIN))  // configura pino como ENTRADA)
#define PIN_MODE_OUTPUT(DDR, _PIN) (DDR|=(1<<_PIN))  // configura pino  como SAIDA)

#define SET_PIN(PORT, _PIN) (PORT^=(1 << _PIN)) // define estado do pino.

#define READ_PIN(PIN, _PIN) (PIN& (1<<_PIN)) // LE estado do pino.

#endif /* REGISTERS_H_ */