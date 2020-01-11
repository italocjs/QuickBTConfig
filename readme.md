# Description
Very simple program to config HC-05 bluetooth modules using an arduino serial

# How to use
1 - Set the ARDUINO IDE to BAUD 38400, activate CR/NL
2 - change the name/password in the .ino file
3 - Burn the code into arduino
4 - connect BT RX to arduino pin D10, connect BT TX to arduino D11
 
# Other useful AT commands:
 
 To read 
 AT : Checa a conexão, retorna OK
 AT+NAME : Mostra o nome atual
 AT+ADDR : Mostra o endereço atual
 AT+VERSION : Mostra a versão
 AT+UART : Mostra a velocidade (BaudRate)
 AT+ROLE: Apenas para modulo MASTER - Seta modo master ou slave
 AT+RESET : Reinicia o modulo
 AT+ORGL : Configuração de fabrica
 AT+PSWD: Mostra a senha atual
 
 
 To write
 AT+NAME=<NOVO_NOME>
 AT+ADDR=<NOVOENDEREÇO>
 AT+PSWD=<SENHA>
 AT+UART=<VELOCIDADE,STOP,PARITY>
 stop bit: 0----1 bit / 1----2 bits
 parity bit  0----None / 1----Odd parity /  2----Even parity
 EXEMPLO,  SETAR VELOCIDADE PARA 115200, 1 bit de parada, sem bit de paridade  =  AT+UART=115200,0,0 
 */
      
