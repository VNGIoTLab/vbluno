---
title: Note about the hardware versions 
sidebar: mydoc_sidebar
permalink: mydoc_over_hardware.html
folder: mydoc
---

*** 
## Note
>This wiki pages for VNG **VBLUno51** board which is upgrade version from the first version - VBLUno - VBLUno v1. If you want to refer documents for VBLUno v1 board, please access to [VBLUno_v1 on Github](https://goo.gl/KgcNjK) 


*** 
## The VBLUno board versions

Sau một thời gian giới thiệu bo mạch phát triển VBLUno đến cộng đồng, VBLUno đã giúp mọi người tiếp cận nhanh chóng với công nghệ Bluetooth Low Energy phục vụ phát triển ứng dụng Internet of Things. 

VNGIoTLab đã nhận được rất nhiều ý kiến nhận xét về ưu điểm của VBLUno phiên bản đầu tiên như:

-  Hỗ trợ nhiều nền tảng phát triển phần mềm:
    + Nordic SDK
    + Arduino 
    + mbed-OS
    + Mynewt-OS
    + RIOT-OS
    + ...
- Sử dụng vi điều khiển nRF51822 (ARM Cortex-M0) tích hợp sẵn giao tiếp BLE 4.2, giúp người dùng dễ dàng tiếp cận và làm chủ công nghệ này.
- Hoạt động ổn định, tiêu tốn ít năng lượng khi giao tiếp với Smartphone  thông qua giao tiếp Bluetooth Low Energy.
- Có nhiều bài hướng dẫn thực hiện các ví dụ điển hành của giao tiếp BLE như: Heart Rate Monitor, Heath Thermometer, iBeacons, điều khiển robot qua BLE,...

Bên cạnh các ưu điểm trên, VBLUno phiên bản đầu tiên vẫn tồn tại khuyết điểm như: không tích hợp một interface cho phép nạp và gỡ lỗi một cách dễ dàng. Với phiên bản đầu tiên, để nạp/gỡ lỗi dễ dàng, người dùng cần sử dụng thêm mô đun CMSIS-DAP, điều này gây trở ngại không nhỏ cho người dùng.

***Với tinh thần lắng nghe từ cộng đồng***, chúng tôi đã nâng cấp mạch VBLUno lên phiên bản 2.0 với tên gọi là **VBLUno51**, bản chất là tích hợp mô đun CMSIS-DAP (DAPLink) lên mạch VBLUno và một số cải tiến quan trọng khác liên quan đến nguồn và ngoại vi. Như vậy, việc nạp chương trình cho mạch VBLUno51 sẽ dễ dàng hơn nhiều, bạn có thể xem mục "Bắt đầu thôi!" để biết cách nạp chương trình cho VBLUno51.

**VBLUno51 = VBLUno 1.0 + giao diện DAPLink; và hơn thế nữa...**


* Bo mạch VBLUno51

![alt_tag](images/vbluno51_fact1.jpg  "VBLUno51 board")


* VBLUno 1.0 + CMSIS-DAP

![alt_tag](images/vbluno_cmsisdap.png  "VBLUno version 1.0_CMSIS-DAP")


  


