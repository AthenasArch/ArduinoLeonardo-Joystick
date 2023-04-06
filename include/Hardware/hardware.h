#ifndef HARDWARE_H_
#define HARDWARE_H_

// #include "Hardware/hardware.h"

#include <Arduino.h>
#include <stdio.h.>
#include <stdlib.h>
#include <string.h>

#define PS2_DAT 11 // marrom
#define PS2_CMD 10 // laranja
#define PS2_SEL 9  // amarelo
#define PS2_CLK 12 // azul

#define PIN_LED_STATUS 8

void hardware_initialize(void);

#endif /* HARDWARE_H_ */
