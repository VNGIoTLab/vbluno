---
title: Đo nhiệt độ bên trong chip nRF51822
tags: [tutorials]
sidebar: mydoc_sidebar
permalink: mydoc_arduino_tut3.html
folder: mydoc
---

# ĐO NHIỆT ĐỘ BÊN TRONG CHIP nRF51822

***
## Cảm biến nhiệt độ bên trong chip nRF51822

* Bên trong chip nRF51822 của Nordic có tích hợp sẵn một cảm biến nhiệt độ giúp đo nhiệt độ hoạt động của chip. Cảm biến này có độ chính xác là 0.25 độ C (1 đơn vị đo được tương ứng với 0.25 độ C).

* Kết quả đo được không phải là nhiệt độ của môi trường xung quanh, mà là nhiệt độ bên trong con chip nRF51822 (CPU của bo mạch VBLUno)

* Theo tài liệu về nRF51822 của hãng Nordic Semiconductor, dải nhiệt độ hoạt động của chip trong khoảng từ -25 đến 75 độ C. Ta có thể sử dụng cảm biến này để giám sát nhiệt độ CPU (nRF51822), từ đó biết được mức tải làm việc của hệ thống, đưa ra các cảnh báo cần thiết khi tải làm việc quá cao. Điều này giúp hệ thống làm việc ổn định và bền bỉ hơn.

**Thủ tục đo nhiệt độ**

* Để tiến hành một lần đo nhiệt độ bên trong chip, thực hiện theo các bước sau:
	
	+ Kích hoạt lệnh START đến mô đun TEMP (cảm biến nhiệt độ) để bắt đầu quá trình đo
	
	+ Khi quá trình đo hoàn thành, cờ EVENTS_DATARDY được đặt lên 1. 
	
	+ Thực hiện hàm đọc giá trị nhiệt độ từ thanh ghi tương ứng
	
	+ Dừng quá trình đo bằng cách kích hoạt lệnh STOP đến mô đun TEMP

**Đo nhiệt độ môi trường?**

* Thông thường chúng ta sử dụng các cảm biến đo nhiệt độ các môi trường như: không khí, nước, đất,… Khi đó, cảm biến nhiệt độ được lắp tại các vị trí cần đo. Bạn cần nhớ rằng ví dụ này chỉ đề cập đến cảm biến nhiệt độ bên trong con chip nRF51822, điều đó có nghĩa rằng nhiệt độ đo được không phải là nhiệt độ môi trường xung quanh. 

* Một số bạn có thể nghĩ rằng, chúng ta có thể hiệu chuẩn lại giá trị đo này để nhận được giá trị nhiệt độ môi trường, nhưng điều đó có thể dẫn đến những kết quả có độ chính xác rất thấp, vì nhiệt độ bên trong con chip không thay đổi tuyến tính với sự thay đổi nhiệt độ môi trường.

***
## Ví dụ đo nhiệt độ chip nRF51822 trên mạch VBLUno V2
	
* Phần này trình bày một ví dụ đo nhiệt độ bên trong chip nRF51822 của bo mạch VBLUno trên môi trường Arduino IDE.

* Ví dụ này khá đơn giản, sử dụng các hàm trong thư viện nrf_temp của Nordic SDK dành cho họ nRF5. Trong đó, chúng tôi có viết hàm float read_temp_value() thực hiện một lần đo nhiệt độ bên trong chip. Các bước của một chu trình đo như đã trình bày ở phần trên.

```
/* brief    Hàm đọc giá trị nhiệt độ từ cảm biến nhiệt độ nội bộ của nRF51822
 * return   Giá trị nhiệt độ (float)*/
float read_temp_value(){
  float temp=0.0;
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
```

* Kết quả:

![](images/arduino/tut/tut3/1.png)

* Trong bài viết tiếp theo, chúng tôi sẽ hướng dẫn các bạn sử dụng cảm biến nhiệt độ bên trong chip nRF51822 để minh họa một thiết bị nhiệt kế  (Health Thermometer Monitor – HTM). HTM là một nhiệt kế thông minh giúp truyền giá trị nhiệt độ từ cảm biến nhiệt độ gắn trên người đến điện thoại thông minh, máy tính bảng.


* Mã nguồn đầy đủ của ví dụ đã trình bày:

```
*
 * VNGIoTLab VBLUno KIT
 * VÍ DỤ ĐỌC GIÁ TRỊ TỪ CẢM BIẾN NHIỆT ĐỘ BÊN TRONG nRF51822
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
```
