/**
 * @brief Gerenciamento de um volante que contem os protocolos PSX. 
 * Conversao e envio dessas informacoes para um PC.
 * 
 * 
 * |****************************************|
 * |DESCRICAO   |   PINO    |   COR_CABO    | 
 * |DAT         |   11      |   marrom      |
 * |CMD         |   10      |   laranja     |
 * |SEL         |   9       |   amarelo     |
 * |CLK         |   12      |   azul        |
 * |LED STATUS  |   8       |   -           |
 * |****************************************|
 * 
 * 
 * - Este arquivo main foi ajustado para funcionar com o Arduino Leonardo e foi desenvolvido pela empresa @AthenasArch.
 * - Foi utilizado a biblioteca (PS2X_lib.h) ja existente, para coletar os dados de protocolo da PSX.
 * - Tambem utilizei a biblioteca (Joystick.h) para fazer a conversao dos protocolos para o PC.
 * 
 * @name    | este aquivo main foi desenvolvido pela @AthenasArch, utilizando as bibliotecas ja existente: (PS2X_lib.h) e (Joystick.h)    
 * @version | 1.4.4                         |
 * @date    | 05/04/2023                    |
 * @github  | First update: 15/03/2023.     |
 * @author  | athenasarch@gmail.com         |
 * @DEV:    | Leonardo Hilgemberg Lopes     |
 * @file    | main.h                        |
 * @warning | -                             |
 **/

#include <Arduino.h>
#include <Hardware/hardware.h>
#include <Database/Structures/systemStatus.h>
#include <Peripheral/PSX/psxManager.h>
#include <Peripheral/LED/led.h>

//  #define MAIN_DEBUG_ENABLE // descomente esta linha para habilitar o debug da Serial.
#ifdef MAIN_DEBUG_ENABLE
    #define MAIN_DEBUG_PRINT(...) { Serial.print(__VA_ARGS__); }
    #define MAIN_DEBUG_PRINTLN(...) { Serial.println(__VA_ARGS__); }
    #define DEBUG_SERIAL_BEGIN(a)    Serial.begin(a)
#else
    #define MAIN_DEBUG_PRINT(...) {}
    #define MAIN_DEBUG_PRINTLN(...) {}
    #define DEBUG_SERIAL_BEGIN(a)    do{}while(0)
#endif

static SystemStatus systemStatus;

void setup() {
    
    delay(1000);
    
    DEBUG_SERIAL_BEGIN(115200);
    delay(300);

    systemStatus_initialize(&systemStatus);

    led_ini(&systemStatus);
    psxManager_ini(&systemStatus);
}

void loop() {
    psxManager_run(&systemStatus);
    led_run(&systemStatus);
}