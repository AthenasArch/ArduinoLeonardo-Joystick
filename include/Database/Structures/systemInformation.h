#ifndef SYSTEM_INFORMATION_H_
#define SYSTEM_INFORMATION_H_

#include <Arduino.h>

#define FIRMWARE_VERSION "5.042" // 

const char COMPILE_TM[] = __DATE__ " " __TIME__;

/**
 *  Atualizacoes da versao: V5.034 ate 5.03
 * 
 * @implements 
 *      1) Integrar ao sistema do buzzer, os LED RGB.
 *      Lembrando que esses LEDs interrompem o fluxo de 
 *      funcionamento da maquina, portanto deve ser acionado
 *      em momentos estrategicos no firmware para nao travar nenhuma operacao.
 * 
 * @implements
 *      2) Ativar e testar o menu de HASH/Senha da maquina, para 
 *      verificar se funciona sem prolemas e sem bugs.
 * 
 * @implements
 *      3) iniciar o processo de transicao das telas para o novo 
 *      formato.
 * 
 * @implements 
 *      4) Testar o sistema de GPS com a maquina.
 * 
 * @implements
 *      5) Reativar o tamper da placa eletronica
 * 
 * @implements 
 *      6) Definir como sera o tamper mecanico.
 * 
 * @implements
 *      7) O controle nao funciona no modo DEBUG, entao
 *      sera necessario implementar.
 * 
 * @implements
 *      8) Alarme de percentual do sensor de rotacao da maquina.
 * 
 * 
 * - Quando entra no menu horimetro esta ligando o motor FEEDER e nao
 * sei por qual motivo
 * 
 * - Foi imlementado uma estrutura switch case para controlar o menu de jogos
 * de forma externa as atualizacoes.
 *          Depois que foi adicionado o modo de prioridade de execucao da tela 
 *      Nextion, foi necessario criar um case para permitir que a maquina nao pare
 *      quando estiver em alguns menus, mas acade nao entrando neles por conta do  
 *      feeder.  
 * 
 * - Adicionado sistema de controle de LED RGB com CHIP WS2811 - Pixel
 * 
 * @implements
 * - Realizada alteracoes no modo de funcionamento das cores do led de Pixel,
 *      Agora e possivel criar uma lista que acione as cores dos LEDs
 *      nessa lista existe uma cor invalida, para nao realizar a alteracao
 *      
 *      Essa lista foi criada para poder acompanhar os status do buzzer.
 * 
 * - Foi adicionado a biblioteca do buzzer as macros que permitem o funcionamento 
 * do sistema de status de led de forma paralela.
 *      Ou seja, foi criada uma lista de cores de leds com a mesma quantidade 
 *      de ringtones que o buzzer possui, cada vez que um ringtone e tocado 
 *      existe uma cor proporcional ao status do ringtone.
 * 
 * @bug 
 *  o sistema de status de funcionamento de Play, Pause Stop da maquina esta com 
 * problema.
 *  Quando o play e pressionado, a maquina entra em funcionamento, mas quando o pause
 * e pressionado, ela entende como se fosse pressionado novamente o play e comeca a 
 * inverter os status.
 * 
 * @
 * 
 * @implements
 *  Foi adicionado a biblioteca do buzzer a macro para debug, pois a biblioteca comecou a 
 * ficar muito extensa.
 */

#endif /* SYSTEM_INFORMATION_H_ */ 