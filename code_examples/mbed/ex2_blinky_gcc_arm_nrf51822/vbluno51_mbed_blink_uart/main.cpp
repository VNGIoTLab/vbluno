
#include "mbed.h"

/*For VBLUno51 board*/
#define PIN_TX  p10
#define PIN_RX  p11
#define PIN_RTS p12
#define PIN_CTS p13
#define PIN_LED p7
 
/* Peripheral Variables */
Serial pc(PIN_TX, PIN_RX);
DigitalOut led(PIN_LED);

int main() {
    
	int counter = 0;												                     //variable for debug

	pc.baud(115200);
	pc.set_flow_control(SerialBase::RTSCTS, PIN_RTS, PIN_CTS);		//Normal: Over DAPLink CDC (Virtual COM port): Default RTS(p12), CTS(p13)
    
    pc.printf("\r\n-------------------------------------\r\n"
              "Tests for VNG VBLUno51 board\r\n"
              "Case: Blink LED and Transmit via UART\r\n"
    		      "For DEBUG\r\n"
              "-------------------------------------\r\n");   
    led = 1;
    while(1) {
    	if(counter++ > 10000) {
    		counter = 0;
		}
		led = !led;
		pc.printf("Blink and wait 1 second........\r\n");
		wait(1);
    }
}
