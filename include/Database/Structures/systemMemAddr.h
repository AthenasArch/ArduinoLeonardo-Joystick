#ifndef SYSTEM_MEM_ADDR_H_
#define SYSTEM_MEM_ADDR_H_

#include <Arduino.h>

 /*-----------------------------------------===--------------------------------------
 *
 * Arquivo utilizado apenas para localizar as posicoes da memoria EEPROM Externa 
 *
 *------------------------------------------===------------------------------------*/

#define ADDR_24C32 0x57

#define EEPROM_DEV_ADDR ADDR_24C32

/**
 * @brief espaco usado para garantir que a memoria esta funcionando
 **/
#define LIFE_TIME_ADDR_CHECK_INIT 0
#define LIFE_TIME_ADDR_CHECK_END 1

/**
 * @brief espaco usado para o tempo de operacao da maquina
 **/
#define MEM_EXT_LIFE_TIME_ADDR_INIT 2
#define MEM_EXT_LIFE_TIME_ADDR_END 10 // // 8 enderecos

/**
 * @brief espaco utilizado para cadastro dos controles RF
 **/
#define MEM_EXT_RF_CONTROLLER_ADDR_INIT 11
#define MEM_EXT_RF_CONTROLLER_ADDR_END  60 // 49 enderecos

/**
 * @brief espaco utilizado para salvar os alarmes
 **/
#define MEM_EXT_ALARMS_ADDR_INIT 61
#define MEM_EXT_ALARMS_ADDR_END  157 // 96 enderecos

/**
 * @brief espaco utilizado para gerenciar os tampers
 **/
#define MEM_EXT_TAMPER_ADDR_INIT 160
#define MEM_EXT_TAMPER_ADDR_END  165 // 5 enderecos

/**
 * @brief ESPACO UTILIZADO PARA GERENCIAR SENTIDO DE GIRO DO SERVO MOTOR
 **/
#define MEM_EXT_SERVO_ROTATION_ADDR 166

#endif /* SYSTEM_MEM_ADDR_H_ */