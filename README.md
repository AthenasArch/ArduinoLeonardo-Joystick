### :wolf: Olá, sou o Leonardo Hilgemberg, criador da AthenasArch.
- Neste projeto, utilizamos Arduino e, futuramente, ESP32 para reativar um antigo volante de PC, conectando-o via USB. O volante é compatível com emuladores de PS2. O código fornecido foi testado e funciona perfeitamente, oferecendo uma solução prática para revitalizar dispositivos mais antigos.

#

# ArduinoLeonardo-Joystick
Projeto com Arduino Leonardo como driver HID para controlar joysticks de PS2

# Bibliotecas externas utilizadas
- PS2X_lib.h - From: http://www.billporter.info/?p=240
  - Esta biblioteca é utilizada para coletar os protocolos do PS2 e fazer o arduino entender as informações.
- Joystick.h - From: https://github.com/MHeironimus/ArduinoJoystickLibrary
  - Esta biblioteca é utilizada para converter informações do arduino para que o PC consiga interpretar como um dispositivo reconhecível.

---

# Organização das pastas do projeto:
- src/: Arquivos de código desenvolvidos pelo autor do projeto e suas respectivas implementações.
        Contem arquivos como main.cpp (outros arquivos .cpp e .h)
- doc: Arquivos e documentos importantes para o projeto / HELP.
- lib: bibliotecas completas, externas de outros desenvolvedores e do criador do projeto.
- test: arquivos de teste.
- examples: Exemplos de uso geral do projeto.

---

# HARDWARE

- Foi adicionado um led de Status ao pino 8 do Arduino Leonardo.
- Descrição de status do LED:
  - 0 - Led Apagado = Arduino não reconheceu um controle.
  - 1 - Led piscando a cada 500ms = Arduino reconheceu um controle e está funcionando perfeitamente no PC.
  - 2 - Led Acesso direto = O controle foi reconhecido pelo PC mas perdeu a comunicação com o controle. 

#
- Descrição dos pinos abaixo:
  - OBS: Eu cheguei a desmontar mais de 5 controles diferentes de PS2, volante e até guitarra, todos seguiam esta ordem de cores.

<div>
  <a href="https://youtube.com/shorts/N5RL5DKm5p0?feature=share" target="_blank"><img width="60%" src="https://github.com/AthenasArch/ArduinoLeonardo-Joystick/blob/d26b65ddf5c984d6bf9a3b7a06d35c673a465b63/doc/pinout_joystick.png" target="_blank"></a> 
</div>  
<!-- END  -->

---
# PROJETO OK
<div align="center">
  <table style="margin-left: auto; margin-right: auto;">
    <tr>
      <td align="center"><img src="https://github.com/AthenasArch/ArduinoLeonardo-Joystick/blob/ed66b19df0fbb343284c1568258d04fffa7c6bcc/doc/img/1-Volante-VGA.jpg" width="150"/><br><b>Placa inferior</b></td>
      <td align="center"><img src="https://github.com/AthenasArch/ArduinoLeonardo-Joystick/blob/ed66b19df0fbb343284c1568258d04fffa7c6bcc/doc/img/2-ConectorPSX-Placa.jpg" width="150"/><br><b>placa superior</b></td>
    </tr>
    <tr>
      <td align="center"><img src="https://github.com/AthenasArch/ArduinoLeonardo-Joystick/blob/ed66b19df0fbb343284c1568258d04fffa7c6bcc/doc/img/3-ConectorPSX-Placa.jpg" width="150"/><br><b>Volante funcionando</b></td>
      <td align="center"><img src="https://github.com/AthenasArch/ArduinoLeonardo-Joystick/blob/ed66b19df0fbb343284c1568258d04fffa7c6bcc/doc/img/4-Comm-OK.jpg" width="150"/><br><b>Conector 15 vias</b></td>
    </tr>
  </table>
</div>


