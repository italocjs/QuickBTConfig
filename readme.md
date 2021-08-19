# Description
Very simple program to config HC-05 bluetooth modules using an arduino serial

# How to use
- Change name/password/speed on the .ino file
- Burn the code
- Set the the IDE baud to 38400, activate CR/NL
- connect BT_RX to arduino pin D10, connect BT_TX to arduino D11
 
# Other useful AT commands:
 
 To read 
 AT : Check if its connected
 AT+NAME : Current name
 AT+ADDR : Current addr
 AT+VERSION : Current ver
 AT+UART : Current BaudRate
 AT+ROLE: Set Master/Slave
 AT+RESET : Restart
 AT+ORGL : Factory Reset
 AT+PSWD: Current password
 
 
 To write
 AT+NAME=<new_name>
 AT+ADDR=<new_address>
 AT+PSWD=<new_password>
 AT+UART=<SPEED,STOP,PARITY>
   stop bit: 0----1 bit / 1----2 bits
   parity bit  0----None / 1----Odd parity /  2----Even parity
