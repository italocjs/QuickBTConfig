#include <Arduino.h> //useful when used on platformio
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(5, 6); // RX | TX

String nome = "HC05_GPS_TEST";
String senha = "0000";
String uart = "9600,0,0"; //velocidade de comunicacao fora do modo AT

void serial_tunnel()
{
  Serial.println("Legenda de comandos uteis para configuracao");

  Serial.println("");
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
  Serial.println("");
  Serial.println("Digite um comando, ou finalize digitando AT+RESET");
  Serial.println("");

  while (1)
  {
    if (bluetooth.available()) // read from HC-05 and send to Arduino Serial Monitor
      Serial.write(bluetooth.read());

    if (Serial.available()) // Keep reading from Arduino Serial Monitor and send to HC-05
      bluetooth.write(Serial.read());
  delay(50);
  digitalWrite(13,!digitalRead(13));
  delay(50);
  }
}

bool is_connected() //Check wether a HC05 has been detected in AT MODE (boot button must be pressed WHILE powering on)
{
  String inData;
  Serial.println("Procurando modulo Bluetooth.");
  bluetooth.println("AT");
  delay(20);
  if (bluetooth.available() == 0)
  {
    return false;
  }
  else
  {
    while (bluetooth.available() > 0) //Check if there is something in the serial buffer
    {
      // Serial.print("TO NO WHILE "); Serial.println(bluetooth.available());
      char recieved = bluetooth.read();
      inData += recieved;
      if (recieved == '\n') // Add data into the "inData" until a \n is received
      {
        if (inData == 'OK\n' || inData == "OK\r\n") // Add data into the "inData" until a \n is received
        {
          Serial.println("Modulo encontrado");
          //inData = ""; // Clear recieved buffer
          return true;
        }
      }
    }
  }
}

void send_AT_commands()
{
  bluetooth.print("AT+NAME=");
  bluetooth.println(nome);  
  delay (100);
  bluetooth.print("AT+PSWD=");
  bluetooth.println(senha);  
  delay (100);
  bluetooth.print("AT+UART=");
  bluetooth.println(uart);  
  delay(400);
  Serial.println("Configuração finalizada");
}

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  Serial.println("Programador de modulo Bluetooth HC05 => RX = D6, TX = D5");
  bluetooth.begin(38400); // HC-05 default speed in AT command more

  while (is_connected() == false)
  {
    delay(2000);
  }
  send_AT_commands();
  serial_tunnel();
}

void loop()
{
}
