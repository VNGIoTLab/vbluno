---
title: Truyền thông giữa Smartphone và máy tính qua “UART over BLE”
tags: [huong_dan]
sidebar: mydoc_sidebar
permalink: mydoc_arduino_tut5_vi.html
language: vi
folder: mydoc
---

# TRUYỀN THÔNG GIỮA SMARTPHONE VÀ MÁY TÍNH VỚI "UART over BLE"

***
## Mô hình hoạt động của UART over BLE (BLE Serial)

* Phần này trình bày một ứng dụng rất thú vị của Bluetooth Low Energy (BLE), đó là UART over BLE. Với ứng dụng này, các thiết bị không được tích hợp sẵn BLE có thể dễ dàng truyền thông không dây với các Smartphone thông qua chuẩn truyền thông UART.
Hình dưới là mô hình hoạt động của UART over BLE.

![](images/arduino/tut/tut5/1.png)

* Sử dụng tính năng này cho debug, giám sát không dây thì cực kỳ cool nhé các bạn, giúp nâng cao hiệu suất trong quá trình phát triển sản phẩm.
	
***
## Ví dụ demo trên VBLUno v2

* **Chạy demo:**

	+ Tải code cho VBLUno trên Arduino IDE tại [ĐÂY](https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/blob/master/Tutorial/Source/VBLUno_Tut6_BLE_Serial.ino) 

	+ Nạp và chạy chương trình

	+ Kết nối với PC thông qua cổng USB to UART trên mạch

	+ Sử dụng phần mềm nRF-UART2.0 của Nordic để tương tác với PC thông qua UART over BLE (VBLUno). Có thể tham khảo code phần mềm nRF UART 2.0 cho Android OS tại địa [ĐÂY](https://github.com/NordicSemiconductor/Android-nRF-UART) 

	+ Một số hình ảnh kết quả:

Phần mềm nRF UART v2.0 trên Android OS

![](images/arduino/tut/tut5/2.png)

Giao diện phần mềm nRF UART v2.0

![](images/arduino/tut/tut5/3.png)

Kết nối đến thiết bị VBLUno có tính năng UART over BLE

![](images/arduino/tut/tut5/4.png)

Kết quả truyền nhận giữa Smartphone và PC

![](images/arduino/tut/tut5/5.png)

Kết quả trên PC.

![](images/arduino/tut/tut5/6.png)

Các bạn cũng có thể tham khảo demo video do bạn Huỳnh Minh Quang thực hiện tại [ĐÂY](https://www.youtube.com/watch?v=U4xNDTFVvXg) 

Hy vọng tính năng này sẽ hữu ích với các bạn để nâng cao hiệu suất phát triển sản phẩm IoT.

* Mọi thắc mắc các bạn có thể trao đổi tại:

https://www.facebook.com/bleviet/messages

https://github.com/VNGIoTLab/Arduino_VBLUno_nRF51822/issues






