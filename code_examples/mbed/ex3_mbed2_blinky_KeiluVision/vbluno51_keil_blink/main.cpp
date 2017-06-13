/********************************************
FOR VBLUNO51 BOARD
*********************************************/

#include "mbed.h"

/*For VBLUno51 board*/
#define PIN_TX  p10
#define PIN_RX  p11
#define PIN_RTS p12
#define PIN_CTS p13
#define PIN_LED p7
 
Serial pc(PIN_TX, PIN_RX); // tx, rx
DigitalOut led(PIN_LED);

int main() {        
    
    //Init
    pc.baud(115200);
    pc.set_flow_control(SerialBase::RTSCTS, PIN_RTS, PIN_CTS);
    pc.printf("\r\n-------------------------------------\r\n"
              "Tests for VNG VBLUno51 board\n\r"              
              "-------------------------------------\r\n");   
    
    //No condition loop
    while(1) {
        led = 1;
        wait(1);
        led = 0;
        wait(1);        
        pc.printf("Finish a period\r\n");
    }
    return 0;
}
