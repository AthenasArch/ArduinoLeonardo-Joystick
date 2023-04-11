#include <Arduino.h>
#include <Peripheral/PSX/psxManager.h>
#include <Hardware/hardware.h>
#include <PS2X_lib.h>
#include <Joystick.h>

#define pressures   false
#define rumble      false

PS2X ps2x;
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_JOYSTICK, 16, 0, true, true, false, false, false, false, false, false, false, false, false);

//  #define MAIN_DEBUG_ENABLE // descomente esta linha para habilitar o debug da Serial.
#ifdef PSX_DEBUG_ENABLE
    #define PSX_DEBUG_PRINT(...) { Serial.print(__VA_ARGS__); }
    #define PSX_DEBUG_PRINTLN(...) { Serial.println(__VA_ARGS__); }
#else
    #define PSX_DEBUG_PRINT(...) {}
    #define PSX_DEBUG_PRINTLN(...) {}
#endif

/**
 * @brief Inicializa todo o sistema de controle do Joystick
 * 
 * @param systemStatus sistema de status geral
 * 
 * @return void
*/
void psxManager_ini(SystemStatus *systemStatus){
    // pega erro de inicializacao se houver.
    systemStatus->error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble);

    // se nao teve erro ao inicializar os protocolos do PSX
    if (systemStatus->error == EXIT_SUCCESS) {
        systemStatus->joystickStatus = JOYSTICK_OK;
        PSX_DEBUG_PRINTLN("Controller configured successfully");
    } else {
        systemStatus->joystickStatus = NO_JOYSTICK;
        PSX_DEBUG_PRINTLN("Controller configuration failed");
    }

    systemStatus->type = ps2x.readType();

    Joystick.begin();
}

/**
 * @brief - Realiza a verificacao do funcionamento do controle.
 *        - 
 * 
 * @param systemStatus sistema de status geral
 * 
 * @return void
*/
void psxManager_run(SystemStatus *systemStatus){
    static unsigned long timerControlPs2 = 0;
    static unsigned long TIME_DELAY_PS2 = 50;

    if (systemStatus->error == 1) {
        return;
    }

    if ( millis() - timerControlPs2 > TIME_DELAY_PS2){
        timerControlPs2 = millis();
        
        ps2x.read_gamepad(false, systemStatus->vibrate);

        // Map the PS2 controller buttons to the emulated joystick buttons
        Joystick.setButton(0, ps2x.Button(PSB_TRIANGLE));
        Joystick.setButton(1, ps2x.Button(PSB_CIRCLE));
        Joystick.setButton(2, ps2x.Button(PSB_CROSS));
        Joystick.setButton(3, ps2x.Button(PSB_SQUARE));
        Joystick.setButton(4, ps2x.Button(PSB_L1));
        Joystick.setButton(5, ps2x.Button(PSB_R1));
        Joystick.setButton(6, ps2x.Button(PSB_L2));
        Joystick.setButton(7, ps2x.Button(PSB_R2));
        Joystick.setButton(8, ps2x.Button(PSB_SELECT));
        Joystick.setButton(9, ps2x.Button(PSB_START));
        Joystick.setButton(10, ps2x.Button(PSB_L3));
        Joystick.setButton(11, ps2x.Button(PSB_R3));

        // Map the PS2 controller D-pad to the emulated joystick buttons
        Joystick.setButton(12, ps2x.Button(PSB_PAD_UP));
        Joystick.setButton(13, ps2x.Button(PSB_PAD_DOWN));
        Joystick.setButton(14, ps2x.Button(PSB_PAD_LEFT));
        Joystick.setButton(15, ps2x.Button(PSB_PAD_RIGHT));


        // Print button states and analog stick positions
        PSX_DEBUG_PRINT("Triangle: "); PSX_DEBUG_PRINT(ps2x.Button(PSB_TRIANGLE));
        PSX_DEBUG_PRINT(" Circle: ");  PSX_DEBUG_PRINT(ps2x.Button(PSB_CIRCLE));
        PSX_DEBUG_PRINT(" Cross: ");   PSX_DEBUG_PRINT(ps2x.Button(PSB_CROSS));
        PSX_DEBUG_PRINTLN(" Square: ");  PSX_DEBUG_PRINT(ps2x.Button(PSB_SQUARE));
        PSX_DEBUG_PRINTLN();

        PSX_DEBUG_PRINT("Left Stick X: ");   PSX_DEBUG_PRINT(ps2x.Analog(PSS_LX));
        PSX_DEBUG_PRINT(" Left Stick Y: ");  PSX_DEBUG_PRINT(ps2x.Analog(PSS_LY));
        PSX_DEBUG_PRINT(" Right Stick X: "); PSX_DEBUG_PRINT(ps2x.Analog(PSS_RX));
        PSX_DEBUG_PRINT(" Right Stick Y: "); PSX_DEBUG_PRINTLN(ps2x.Analog(PSS_RY));

        // Map the PS2 controller analog sticks to the emulated joystick axes and scale the values to 16-bit range
        // mapeamento funcionando OK.
        // Joystick.setXAxis(map(ps2x.Analog(PSS_LX), 0, 255, 0, 1000));
        // Joystick.setYAxis(map(128, 0, 255, 0, 1000));
        // Joystick.setRxAxis(map(128, 0, 255, 0, 1000));
        // Joystick.setRyAxis(map(128, 0, 255, 0, 1000));


        // Imprime os estados dos botões D-pad no Monitor Serial
        PSX_DEBUG_PRINT("D-pad Up: ");     PSX_DEBUG_PRINT(ps2x.Button(PSB_PAD_UP));
        PSX_DEBUG_PRINT("D-pad Down: ");   PSX_DEBUG_PRINT(ps2x.Button(PSB_PAD_DOWN));
        PSX_DEBUG_PRINT("D-pad Left: ");   PSX_DEBUG_PRINT(ps2x.Button(PSB_PAD_LEFT));
        PSX_DEBUG_PRINT("D-pad Right: ");  PSX_DEBUG_PRINTLN(ps2x.Button(PSB_PAD_RIGHT));

        // mapeamento funcionando OK.
        Joystick.setXAxis(map(ps2x.Analog(PSS_LX), 0, 255, 0, 1000));
        Joystick.setYAxis(500);
        Joystick.setRxAxis(500);
        Joystick.setRyAxis(500);
    }
    psxManager_checkCommunication(systemStatus);
}

/**
 * 
*/
void psxManager_checkCommunication(SystemStatus *systemStatus){
    
    static unsigned long timerCheckCommunication = 0;
    const unsigned long TIME_CHECK_COMMUNICATION = 1000;
    
    if (millis() - timerCheckCommunication > TIME_CHECK_COMMUNICATION){

        timerCheckCommunication = millis();

        bool success = ps2x.read_gamepad(false, 0x00); // Leia os dados do controle

        if (!success) {
            systemStatus->joystickStatus = JOYSTICK_LOST_COMM;
            // A leitura falhou, o que pode indicar que o controle foi desconectado
            // Execute ações necessárias para lidar com a desconexão do controle, como parar o sistema ou emitir um alerta
        } else {
            systemStatus->joystickStatus = JOYSTICK_OK;
            // A leitura foi bem-sucedida, o que indica que o controle ainda está conectado
            // Continue a executar o código normalmente
        }
    }

}