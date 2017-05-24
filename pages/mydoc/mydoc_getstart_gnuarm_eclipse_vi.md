---
title: Bắt đầu với mbed-OS và Eclipse IDE
tags: [bat_dau]
sidebar: mydoc_sidebar
permalink: mydoc_getstart_gnuarm_eclipse_vi.html
language: vi
folder: mydoc
---

# BẮT ĐẦU SỬ DỤNG MẠCH VBLUno51 VỚI MBED-OS (ARM EMBEDDED + ECLIPSE IDE)


***
## PHẦN 1: CÀI ĐẶT MÔI TRƯỜNG

Nhằm nâng cao hiệu suất làm việc của developers, việc sử dụng các môi trường phát triển (IDE) là điều cần thiết. Để phát triển các ứng dụng nhúng cho IoT, cụ thể là phát triển ứng dụng với bo mạch VBLUno51 của VNGIoTLab, chúng tôi đề xuất phương án sử dụng môi trường sau:

- Phần mềm (hoàn toàn miễn phí)
	+ Compiler: GCC ARM Embedded
	+ IDE: Eclipse C/C++ với GNU ARM Eclipse plugin
	+ Build Tools: Chỉ cần cài đặt nếu sử dụng Windows OS
	+ Flash và Debug: pyOCD hoặc OpenOCD
	
- Phần cứng:
	+ Bo mạch VBLUno51 của VNGIoTLab (tương đương VBLUno v1 + CMSIS-DAP)


Các bước cài đặt khá đơn giản, bạn thực hiện theo hướng dẫn dưới đây:

### Bước 1: Cài đặt GNU ARM Toolchain

http://gnuarmeclipse.github.io/toolchain/install/

### Bước 2: Cài đặt Eclipse C/C++

http://www.eclipse.org/downloads/?

### Bước 3: GNU ARM Eclipse plugin

* Đây là plugin cho phép sử dụng Eclipse IDE để phát triển ứng dụng cho các dòng vi điều khiển ARM với trình biên dịch GCC_ARM. So với việc chỉ sử dụng các command, sử dụng Eclipse cho phép bạn có thể lập trình, biên dịch và gỡ lỗi trên môi trường GUI rất tiện lợi cho các developers.

* Sau khi cài đặt Eclipse C/C++, bạn có thể vào Eclipse Marketplace, tìm với từ khóa “GNU ARM Eclipse” và install GNU ARM Eclipse plugin

![](images/mbed/getstart/eclipse/1.png)

* Tham khảo thêm tại http://gnuarmeclipse.github.io/

### Bước 4: Cài đặt GNU ARM Eclipse Windows Build Tool (Chỉ dành cho Windows OS)

* http://gnuarmeclipse.github.io/windows-build-tools/

* Sau khi cài đặt, không quên set path hệ thống cho thư mục vừa cài đặt. Ví dụ:
***“C:\Program Files (x86)\GNU ARM Eclipse\Build Tools\2.6-201507152002\bin”***

* Vào thư mục trên, copy **“busybox.exe”** và đổi tên thành “**mkdir.exe**”

### Bước 5: Cài đặt công cụ để merge các file hex cùng nhau

+ Linux: cài đặt srec_cat

+ Windows: 

Sử dụng **mergehex.exe** .  Bạn có thể download tại đây
https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP/tree/master/tools

Copy mergehex.exe vào chung thư mục “…GNU ARM Eclipse\Build Tools\2.6-201507152002\bin”

![](images/mbed/getstart/eclipse/2.png)

***
## PHẦN 2: XÂY DỰNG MỘT PROJECT 

* Project sau đây sử dụng:
	+ Bo mạch  VBLUno51 của VNGIoTLab.
	+ MCU: Nordic nRF51822 (Cortex-M0).
	+ Toolchain: GCC ARM Embedded.
	+ IDE: Eclipse với GNU ARM Eclipse plugin.
	+ Project đơn giản: Nháy led và truyền thông UART, sử dụng mbed-OS
	
### Bước 1: Export project về máy tính

+ Có nhiều cách để tạo một project sử dụng mbed-OS cho VBLUno, bài hướng dẫn này chọn cách đơn giản là export một project mẫu trên mbed Online Compiler về máy tính. Bản chất của việc làm này là nhờ mbed Online Compiler tạo cho chúng ta một Makefile có sẵn, phù hợp với nRF51822.

+ Truy cập vào mbed Online Compiler, export project đã làm trong tutorial sử dụng mbed online compiler về máy tính, lựa chọn toolchain là GCC (ARM Embedded)

![](images/mbed/getstart/eclipse/3.png)

![](images/mbed/getstart/eclipse/4.png)


### Bước 2: Tạo project với Eclipse

+ Chọn File -> New -> Project

+ C/C++ -> Makefile Project with Existing Code

![](images/mbed/getstart/eclipse/5.png)

![](images/mbed/getstart/eclipse/6.png)

![](images/mbed/getstart/eclipse/7.png)


### Bước 3: Cấu hình cho project

+ Nhấp chuột phải tại project -> chọn Properties

+ Tại mục C/C++ Build, chọn thẻ Builder Settings, sửa build command

![](images/mbed/getstart/eclipse/8.png)

### Bước 4: Build project

+ Chúng ta không cần tạo mới Makefile, do đã sử dụng makefile nhận được bởi việc export project từ mbed Online Compiler. Tuy nhiên, makefile mặc định này dành cho Linux, nếu sử dụng Windows OS bạn cần phải chỉnh sửa Makefile như sau:

Thêm dòng 53 trong hình sau:

![](images/mbed/getstart/eclipse/9.png)

Thêm dòng 125, 126 trong hình sau:

![](images/mbed/getstart/eclipse/10.png)

Sửa dòng 76 như hình sau:

![](images/mbed/getstart/eclipse/11.png)

Sửa dòng 41 như hình sau:

![](images/mbed/getstart/eclipse/12.png)

+ Nhấp chuột phải tại project -> chọn Build Project

+ Nếu thành công, kết quả biên dịch như hình dưới

![](images/mbed/getstart/eclipse/13.png)

### Bước 5: Nạp file thực thi xuống mạch VBLUno51

Chúng ta cần chú ý 2 file thực thi có phần mở rộng (*.hex) trong thư mục .build

+ **mbed_blinky.hex**: Chỉ là file thực thi của Application, không gồm softdevice

+ **combined.hex**: Gồm Softdevice và Application

![](images/mbed/getstart/eclipse/14.png)

Để chắc chắn, chúng ta nạp file combined.hex xuống mạch VBLUno bằng cách copy file này vào ổ đĩa của CMSIS-DAP

**Ghi chú: Hướng dẫn sử dụng pyOCD và OpenOCD để debug sẽ được trình bày trong mục Tutorial **

### Dowload

+ Có thể download mã nguồn tại [ĐÂY](https://goo.gl/C7SIex) 