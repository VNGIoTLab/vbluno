/*
  VNG IoT Lab - 2017

  Website: 
    + http://iotviet.com.vn
    + https://www.facebook.com/bleviet

  Examples for VBLUno v2 board

  MBED-OS_Ex1: Blink LED and transmit over UART

*/

/*
FOR VBLUNO v2 BOARD
Note: - Must select Nordic nRF51822 board. 
      If you select NRF51_DK board, may this code be been IDLE status with Serial. 
      Because NRF51_DK use Hardware FlowControl for UART
            - Small error with Keil uVision:
            After flash firmware to VBLUno, Keil do not auto run application. You need switch board power off/on
            - Can debug for VBLUno
*/

#include "mbed.h"

/*Config modules*/
DigitalOut myled(p7);   /*VBLUno: LED is p7*/
Serial pc(p10, p11);    /*VBLUno: TX is p10, RX is p11 (Serial)*/

/*MAIN funcrion*/
int main() {
	int varTest=0;		/*Variable for Debug*/

    /*Init*/
    pc.baud(9600);              
    
    /*Endless Loop*/
    while(1) {
    	varTest++;
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
        pc.printf("VBLUno - mbed OS - Hello World!\r\n");
    }
}
