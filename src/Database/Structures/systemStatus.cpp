#include "Database/Structures/systemStatus.h"
#include "Database/Structures/systemStructures.h"
#include "Hardware/hardware.h"
#include <Arduino.h>

// static SystemStatus* _systemStatus = NULL;
 SystemStatus* _systemStatus = NULL;

/**
 * @brief inicialize o conteudo de status do projeto.
 * 
 * @param systemStatus - Estrutura geral de status do firmware.
 * 
 * @return void
 **/
void systemStatus_initialize(SystemStatus *systemStatus) {
    memset(systemStatus, 0, sizeof(SystemStatus));
}

/**
 * @brief Aponta para estrutura geral de status do firmware.
 * 
 * @param 
 * 
 * @return systemStatus - Estrutura geral de status do firmware.
 **/
SystemStatus *systemSystem_getSystemStatus( void ) {
    return _systemStatus;
}