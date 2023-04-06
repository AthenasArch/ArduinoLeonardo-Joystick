#ifndef SYSTEM_STATUS_H_
#define SYSTEM_STATUS_H_

#include <Arduino.h>
#include "systemStructures.h"

typedef struct SYSTEM_STATUS {
    int error = 0;
    byte type = 0;
    byte vibrate = 0;
    DbJoystickStatus joystickStatus;
} SystemStatus;

void systemStatus_initialize(SystemStatus *systemStatus);
SystemStatus *systemSystem_getSystemStatus( void );

#endif /* SYSTEM_STATUS_H_ */