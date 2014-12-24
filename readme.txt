PORTA SERIAL DO COMPUTADOR SETADA PARA BAUD 38400!!!!!  ATIVAR CR E NEWLINE!!! IMPORTANTE!




Desenvolvido por Italo Soares - 24/12/2014
 
 CONECTAR O PINO RX DO BLUETOOTH NO PINO 10 DO ARDUINO, E O PINO TX, NO PINO 11!!!
 CONECTAR O PINO EN DO BLUETOOTH NO PINO 9 DO ARDUINO (caso o modulo não tenha botão para entrar no modo AT)
 
 MODIFIQUE PARA SUAS CONFIGURAÇOES NO BLOCO DE STRINGS!!!!
 
 
 COMANDOS PADROES AT:
 LEITURA 
 AT : Checa a conexão, retorna OK
 AT+NAME : Mostra o nome atual
 AT+ADDR : Mostra o endereço atual
 AT+VERSION : Mostra a versão
 AT+UART : Mostra a velocidade (BaudRate)
 AT+ROLE: Apenas para modulo MASTER - Seta modo master ou slave
 AT+RESET : Reinicia o modulo
 AT+ORGL : Configuração de fabrica
 AT+PSWD: Mostra a senha atual
 
 
 ESCRITA
 AT+NAME=<NOVO_NOME>
 AT+ADDR=<NOVOENDEREÇO>
 AT+PSWD=<SENHA>
 AT+UART=<VELOCIDADE,STOP,PARITY>
 stop bit: 0----1 bit / 1----2 bits
 parity bit  0----None / 1----Odd parity /  2----Even parity
 EXEMPLO,  SETAR VELOCIDADE PARA 115200, 1 bit de parada, sem bit de paridade  =  AT+UART=115200,0,0 
 */
      