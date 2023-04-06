#ifndef PSX_MANAGER_H_
#define PSX_MANAGER_H_

#include <Arduino.h>
#include <Database/Structures/systemStatus.h>

void psxManager_ini(SystemStatus *systemStatus);
void psxManager_run(SystemStatus *systemStatus);
void psxManager_checkCommunication(SystemStatus *systemStatus);

#endif // PSX_MANAGER_H_