---
title:  Bắt đầu với mbed-OS và Keil uVision
tags: [getting_started]
sidebar: mydoc_sidebar
permalink: mydoc_getstart_keil.html
folder: mydoc
---

# BẮT ĐẦU SỬ DỤNG MẠCH VBLUNO51 VỚI MBED-OS (Keil uVision)


***
## VÍ DỤ NHÁY LED 

* Project sau đây sử dụng:
	+ Bo mạch  VBLUno51 của VNGIoTLab.
	+ MCU: Nordic nRF51822 (Cortex-M0).
	+ mbed-OS
	+ IDE: Keil uVision 4
	+ Project đơn giản: Nháy led và truyền thông UART, sử dụng mbed-OS

### Bước 1: Dowload ví dụ mẫu 

+ Download mã nguồn tại [ĐÂY](https://goo.gl/UMnGpg) 
	
### Bước 2: Biên dịch và nạp chương trình 

* Mở project được tải về 

* Nhấn **Build** để biên dịch chương trình

* Cài đặt giao tiếp debug và nạp chương trình

Thực hiện như 2 hình dưới đây:

![](images/mbed/getstart/keil/1.png)

![](images/mbed/getstart/keil/2.png)

* Nạp chương trình xuống mạch VBLUno51 bằng cách nhấn nút LOAD như hình dưới đây

![](images/mbed/getstart/keil/3.png)

### Bước 3: Debug

Tham khảo hình dưới dây:

![](images/mbed/getstart/keil/4.png)