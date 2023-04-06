#ifndef LED_H_
#define LED_H_

#include <Database/Structures/systemStatus.h>

#define TOGGLE_DATA(DATA) ((DATA)?DATA=0:DATA=1) 

void led_ini(SystemStatus *systemStatus);
void led_run(SystemStatus *systemStatus);

#endif // LED_H_