---
title: Nạp/Gỡ lỗi cho VBLUno bằng pyOCD và OpenOCD trên GNU ARM Embedded + Eclipse
tags: [huong_dan]
sidebar: mydoc_sidebar
permalink: mydoc_mbed_tut1_vi.html
language: vi
folder: mydoc
---

# NẠP CHƯƠNG TRÌNH/GỠ LỖI CHO VBLUNO V2 BẰNG pyOCD VÀ OpenOCD TRONG MÔI TRƯỜNG GNU_ARM + ECLIPSE 

***
## 0. Lưu ý:

Bài viết này tiếp tục cho nội dung tại `Getting Start --> Using mbed-OS --> GNU ARM Embedded & Eclipse IDE` 

***
## 1. Cài đặt

### 1.1. Cài đặt pyOCD

+ pyOCD là một chương trình mã nguồn mở cho phép nạp chương trình và gỡ lỗi cho các vi điều khiển ARM Cortex-M sử dụng CMSIS-DAP (DAPLink) interfaces.

+ pyOCD được xây dựng bằng ngôn ngữ lập trình Python, và dĩ nhiên nó hỗ trợ đa nền tảng: Windows, Linux và OSX.

+ Tham khảo cách cài đặt tại [ĐÂY](https://github.com/mbedmicro/pyOCD) 

+ Sau khi cài thành công, bạn thử gõ **pyocd-flashtool** tại Terminal, nếu hệ điều hành không nhận diện được đường dẫn, bạn cần bổ sung đường dẫn của pyOCD vào biến môi trường PATH. 

![](images/mbed/tut/tut1/1.png) 

### 1.2. Cài đặt OpenOCD

+ Trong khi pyOCD được mbed team thiết kế riêng cho CMSIS-DAP (DAPLink) interface thì OpenOCD là một phần mềm có chức năng tương tự nhưng có thể hoạt động với CMSIS-DAP và rất nhiều công cụ khác như: Jlink, ST-Link, Ulink, redbee-usb,….

+ Nếu bạn đã cài đặt GNU ARM Eclipse plugin cho Eclipse như đã hướng dẫn tại `Getting Start --> Using mbed-OS --> GNU ARM Embedded & Eclipse IDE`, thì OpenOCD đã được cài đặt sẵn vào máy tính của bạn. Nếu bạn sử dụng Windows OS, có thể OpenOCD sẽ được cài vào đường dẫn như hình sau

![](images/mbed/tut/tut1/2.png) 

+ Bạn cũng có thể cài đặt OpenOCD từ [ĐÂY](https://sourceforge.net/projects/openocd/) 

### 1.3. Cài đặt thêm các Device Packs

Device packs của nhà sản xuất chip giúp GNU ARM Eclipse plugin có thể hiển thị các thông tin về ngoại vi, thanh ghi, bộ nhớ,… của chip trong khi chúng ta tiến hành debug. Bạn cài đặt theo các hình sau

![](images/mbed/tut/tut1/3.png) 

![](images/mbed/tut/tut1/4.png) 

![](images/mbed/tut/tut1/5.png) 


***
## 2. Hướng dẫn nạp/gỡ lỗi cho VBLUno trên GNU ARM Eclipse.

### 2.1. Nạp chương trình

+ Sửa Makefile: 

Bổ sung thêm từ dòng 128 đến 134

![](images/mbed/tut/tut1/7.png) 

Trong đó dòng 134 có nội dung là:

"C:/Program Files/GNU ARM Eclipse/OpenOCD/0.10.0-201601101000-dev/bin/openocd.exe" -f "C:/Program Files/GNU ARM Eclipse/OpenOCD/0.10.0-201601101000-dev/scripts/interface/cmsis-dap.cfg" -f "C:/Program Files/GNU ARM Eclipse/OpenOCD/0.10.0-201601101000-dev/scripts/target/nrf51.cfg" -c "program combined.hex verify reset exit 0x0"     

+ Tạo target:

Tạo 2 target với tên là flash_pyocd và flash_openocd:

![](images/mbed/tut/tut1/8.png) 

+ Flash chương trình xuống mạch VBLUno

Sau khi build project, để nạp chương trình cho mạch bằng pyOCD, bạn nhấp đúp vào target flash_pyocd. Tương tự cho OpenOCD.

Hình dưới đây xuất hiện khi nạp bằng pyOCD

![](images/mbed/tut/tut1/9.png) 

Hình dưới đây xuất hiện khi nạp bằng OpenOCD

![](images/mbed/tut/tut1/10.png) 

Sau khi nạp xong thì mạch sẽ được reset và chương trình bắt đầu chạy.

### 2.2. Debug với pyOCD

+ Sửa Makefile

Chú ý dòng 68, 69 trong hình sau

![](images/mbed/tut/tut1/11.png) 

+ Sửa Build command

![](images/mbed/tut/tut1/12.png) 

+ Build lại project

+ Cấu hình debug

Chuột phải tại project -> Chọn Debug Configurations

![](images/mbed/tut/tut1/13.png) 

Nhấp đúp vào GDB pyOCD Debugging để tạo cấu hình debug mới:

![](images/mbed/tut/tut1/14.png) 

![](images/mbed/tut/tut1/15.png) 

![](images/mbed/tut/tut1/16.png) 

+ Nhấn Debug để bắt đầu quá trình debug

![](images/mbed/tut/tut1/17.png) 

pyOCD hỗ trợ đầy đủ các tính năng debug thông thường như: Run, Pause, Stop, Step Into, Step Over, Run to Line, Breakpoint, Watch biến và biểu thức,… Ngoài ra còn hỗ trợ xem giá trị Registers, Memory.

Một số hình ảnh minh họa:

![](images/mbed/tut/tut1/18.png) 

![](images/mbed/tut/tut1/19.png) 

![](images/mbed/tut/tut1/20.png) 

![](images/mbed/tut/tut1/21.png) 

### 2.3. Debug với OpenOCD

Thực hiện tương tự như với pyOCD, chú ý cấu hình theo các hình sau:

![](images/mbed/tut/tut1/22.png) 

![](images/mbed/tut/tut1/23.png) 

![](images/mbed/tut/tut1/24.png) 

OpenOCD cũng hỗ trợ các tính năng debug như pyOCD

![](images/mbed/tut/tut1/25.png) 


* Có thể thấy, Eclipse + GNU ARM Eclipse plugin + GNU ARM Embedded toolchain + pyOCD, OpenOCD hỗ trợ developers phát triển ứng dụng cho bo mạch VBLUno một cách dễ dàng. Một môi trường lập trình hỗ trợ GUI, cho phép nạp và gỡ lỗi chương trình một cách thuận tiện sẽ giúp nâng cao hiệu suất làm việc của các lập trình viên.

**Mọi thắc mắc hoặc ý kiến đóng góp bạn có thể trao đổi tại đây:**

https://www.facebook.com/bleviet/messages/

https://github.com/VNGIoTLab/mbed_for_VBLUno-CMSIS-DAP/issues
