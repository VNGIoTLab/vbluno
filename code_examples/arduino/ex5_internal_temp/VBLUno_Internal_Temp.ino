/*
  VNG IoT Lab - 2017

  Website: 
    + http://iotviet.com.vn
    + https://www.facebook.com/bleviet

  Examples for VBLUno v2 board

  Arduino_Ex5: Read temperature value inside nRF51822 chip

*/


#include "nrf_temp.h"

/*
 * brief    Hàm đọc giá trị nhiệt độ từ cảm biến nhiệt độ nội bộ của nRF51822
 * return   Giá trị nhiệt độ (float)
 */
float read_temp_value(){

  float temp=0;

  /* Bắt đầu quá trình đo nhiệt độ. */
  NRF_TEMP->TASKS_START = 1; 

  /* Chờ đến khi quá trình đo nhiệt độ hoàn thành. */
  while (NRF_TEMP->EVENTS_DATARDY == 0){
    // Do nothing.}
  }
  NRF_TEMP->EVENTS_DATARDY = 0;

  /* Đọc giá trị nhiệt độ từ cảm biến
   * Độ chính xác là 0.25 độ C <=> 1 đơn vị = 0.25 độ C
   * Cần chia cho 4 để nhận được giá trị độ C
   */
  temp = ((float)nrf_temp_read() / 4.);

  /* Hoàn thành quá trình đo. */
  NRF_TEMP->TASKS_STOP = 1; 

  return temp;
}


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  Serial.begin(9600);
  Serial.println("VBLUno - Read Internal Temperature");

  //for Temperature
  nrf_temp_init();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Gia tri nhiet do: ");
  Serial.println(read_temp_value());
  delay(1000);
}
