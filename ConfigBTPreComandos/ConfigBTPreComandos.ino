/*
 Desenvolvido por Italo Soares - 24/12/2014
 
 CONECTAR O PINO RX DO BLUETOOTH NO PINO 10 DO ARDUINO, E O PINO TX, NO PINO 11!!!
 CONECTAR O PINO EN DO BLUETOOTH NO PINO 9 DO ARDUINO (caso o modulo não tenha botão para entrar no modo AT)
 MODIFIQUE PARA SUAS CONFIGURAÇOES NO BLOCO DE STRINGS!!!!
 
 SERIAL DO ARDUINO IDE EM 38400 NL+CR 
 tutorial de conexao a outro dispositivo http://www.martyncurrey.com/connecting-2-arduinos-by-bluetooth-using-a-hc-05-and-a-hc-06-pair-bind-and-link/
 */
//vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv  MODIFICAR AQUI vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv 
String nome = "nome";
String senha = "9999";
String uart = "9600,0,0"; //velocidade de comunicacao fora do modo AT

//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^MODIFICAR AQUI ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^   

String entrada = "";   
int configurado = 0;

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3); // RX, TX - CASO O MODULO SEJA DE 3.3V, USE DIVISOR DE TENSÃO!!!

void setup() 
{
  pinMode(9,OUTPUT); 
  digitalWrite(9,HIGH);
  pinMode(13,OUTPUT); 
  digitalWrite(13,LOW);
  bluetooth.begin(38400);
  Serial.begin(38400);
  Serial.print("Iniciando");
}

void loop()
{
  bluetooth.println("AT");
  bluetooth.println("AT");
  bluetooth.println("AT");
  bluetooth.flush();
  bluetooth.println("AT");
  bluetooth.setTimeout(200);
  entrada = bluetooth.readString();
  Serial.println(entrada);

  if (entrada == "OK\r\n")
  {
    Serial.println("Modulo conectado");
    digitalWrite(13,HIGH);
    enviacomandos();
    configurado = 1;
  }
  else 
  {
    configurado = 0;
    Serial.println("Modulo nao encontrado, verifique as conexoes");
    delay (3000);
  }

  if (configurado == 1)
  {
    enviadireto();
  }
}

void enviacomandos()
{
  bluetooth.print("AT+NAME=");
  bluetooth.println(nome);  
  delay (50);
  bluetooth.print("AT+PSWD=");
  bluetooth.println(senha);  
  delay (50);
  bluetooth.print("AT+UART=");
  bluetooth.println(uart);  
}

void enviadireto()
{
  Serial.println("");
  Serial.println("");
  Serial.println("");
  Serial.println("Configuracao enviada!, para finalizar digite AT+RESET e faça o upload do seu programa, caso deseje modificar algo, digite os comandos no terminal. segue a lista de comandos possiveis:"); 
  Serial.println("AT : Checa a conexão, retorna AT");
  Serial.println("AT+NAME : Mostra o nome atual");
  Serial.println("AT+ADDR : Mostra o endereco atual");
  Serial.println("AT+VERSION : Mostra a versao");
  Serial.println("AT+UART : Mostra a velocidade (BaudRate)");
  Serial.println("AT+ROLE: Apenas para modulo MASTER - Seta modo master ou slave");
  Serial.println("AT+RESET : Reinicia o modulo");
  Serial.println("AT+ORGL : Configuracao de fabrica");
  Serial.println("AT+PSWD: Mostra a senha atual");
  Serial.println("AT+NAME=<NOVO_NOME>");
  Serial.println("AT+ADDR=<NOVOENDERECO>");
  Serial.println("AT+PSWD=<SENHA>");
  Serial.println("AT+UART=<VELOCIDADE,STOP,PARITY>");
  Serial.println("stop: 0 = 1 bit / 1 = 2 bits");
  Serial.println("parity bit  0----None / 1----Odd parity / 2----Even parity");
  Serial.println("Digite um comando, ou finalize digitando AT+RESET");
  Serial.println("");
  Serial.println("");
  Serial.println("");

  while (1)
  {
    {      
      if (bluetooth.available())     
        Serial.write(bluetooth.read());     
      if (Serial.available())     
        bluetooth.write(Serial.read());
    }
  }
}

