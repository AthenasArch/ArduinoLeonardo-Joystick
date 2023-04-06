#include <Arduino.h>
#include <Hardware/hardware.h>
#include <Peripheral/LED/led.h>

void led_ini(SystemStatus *systemStatus){
    pinMode(PIN_LED_STATUS, OUTPUT);
}

void led_run(SystemStatus *systemStatus){
    unsigned long TIME_LED_OK = 500;
    static unsigned long oldTime = 0;
    static uint8_t toggleLed = 0;

    // se perdeu a comunicacao com o joystic deixa o led acesso direto.
    if(systemStatus->joystickStatus == JOYSTICK_LOST_COMM){
        digitalWrite(PIN_LED_STATUS, 1);
    } else {
        // se nao teve erro ao inicializar os protocolos do PSX
        if (systemStatus->error == EXIT_SUCCESS) {
        
            if ( millis() - oldTime > TIME_LED_OK ){
                oldTime = millis();
                digitalWrite(PIN_LED_STATUS, TOGGLE_DATA(toggleLed));
            }
        }
    }
}
