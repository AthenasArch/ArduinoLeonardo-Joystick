#include <Arduino.h>
#include "Hardware/hardware.h"

/**
 * @brief inicializa os pinos do uC
 * 
 * @param void
 *  
 * @return void
 **/
void hardware_initialize(void){

    /////////////////////////////////////////////////
    /////   Inicializa pinos analogicos
    analogReference(DEFAULT);
    // nalogReference(INTERNAL1V1);
    // analogReference(INTERNAL2V56);
}