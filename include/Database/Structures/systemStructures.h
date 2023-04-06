#ifndef SYSTEM_STRUCTURES_H_
#define SYSTEM_STRUCTURES_H_

#include <Arduino.h>
#include "Database/Structures/systemDefines.h"

// typedef enum {
//     TESTING_OFF     = 0,
//     TESTING_ON      = 1
// } DbMachineMotorTesting;

typedef enum DB_JOYSTICK_STATUS{
    NO_JOYSTICK             = 0,
    JOYSTICK_OK             = 1,
    JOYSTICK_LOST_COMM      = 2
} DbJoystickStatus;

// typedef struct DB_DISPLAY_STATUS{
//     DbWaitUpdateDisplay feeder;
//     DbWaitUpdateDisplay buzzer;
// } DbDisplayStatus;

// typedef struct DB_TENNIS_MACHINE_STATUS{

//     uint32_t lifeTime;
// } DbTennisMachineStatus;

#endif /* SYSTEM_STRUCTURES_H_ */