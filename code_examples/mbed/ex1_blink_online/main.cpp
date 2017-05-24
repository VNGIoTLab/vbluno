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

DigitalOut myled(p7);			//LED on VBLUno board
Serial pc(p10, p11);     	//TX:p10, RX:p11

//variables
int count = 0;
		
int main() { 		
	
		//Init
		pc.baud(115200);
    pc.printf("Start application\r\n");
	
		//No condition loop
    while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
				count++;
        pc.printf("Finish a period\r\n");
    }
    return 0;
}
