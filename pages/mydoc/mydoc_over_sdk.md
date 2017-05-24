---
title: Software Development Kit
sidebar: mydoc_sidebar
permalink: mydoc_over_sdk.html
folder: mydoc
---

## Để phát triển phần mềm cho VBLUno51 ?

* VBLUno51 sử dụng vi điều khiển nRF51822 của hãng Nordic Semiconductor, với nhân ARM Cortex-M0 32 bit hỗ trợ các tính năng và giao diện cơ bản của một vi điều khiển. Điểm nhấn của nRF51822 là tích hợp giao tiếp truyền thông không dây 2.4 GHz Bluetooth Low Energy (System on Chip). Đây là giao tiếp phổ biến trong các hệ thống IoT với đặc điểm khoảng cách gần, siêu tiết kiệm năng lượng, thân thiện với môi trường sống và phổ biến trên các thiết bị điện thoại thông minh.

* nRF51822 là dòng chip BLE được sử dụng khá rộng rãi trên thế giới, nhiều kit phát triển cũng thiết kế dựa trên dòng chip này nên nó được hỗ trợ bởi khá nhiều SDK và Embedded OS. **Tuy giá thành không rẻ như một số dòng chip có hỗ trợ BLE của Trung Quốc, nhưng nRF51822 có ưu điểm là hoạt động rất ổn định và cực kỳ tiết kiệm năng lượng với giao tiếp không dây BLE.**

* Có thể tổng hợp các SDK và RTOS (open source) mà VBLUno51 được hỗ trợ như sau: 

	* **Nordic SDK:** Đây là SDK chính thức cho các dòng chip nRF51, nRF52 của hãng Nordic. SDK này cung cấp thư viện cho tất cả các thành phần bên trong chip nRF51822, bao gồm thư viện giao tiếp BLE. Nordic SDK hỗ trợ các IDE (Compiler) như Keil MDK, IAR,... Sự khó khăn khi sử dụng SDK này là người lập trình cần phải hiểu khá nhiều về phần cứng cũng như tiêu tốn nhiều thời gian tìm hiểu các hàm API.

	* ***Arduino IDE*:**  Arduino IDE hẳn không còn xa lạ với cộng đồng làm điện tử, công nghệ thông tin. Đây là môi trường phát triển phần mềm với các hàm API đơn giản, hiệu quả, cho phép người lập trình xây dựng nhanh ứng dụng mà không cần hiểu quá sâu về phần cứng. VNGIoTLab đã tham khảo và phát triển để Arduino IDE hỗ trợ VBLUno.

	* ***mbed-OS (2, 3, 5)*:** Với lợi thế của nhà thiết kế chip ARM, ARM Inc cung cấp một nền tảng hoàn chỉnh để phát triển hệ thống IoT với tên gọi ARM mbed IoT Device Platform. Thành phần quan trọng của ARM mbed IoT Device Platform chính là hệ điều hành nhúng mbed OS dành cho các vi điều khiển ARM Cortex-M. mbed-OS được cộng đồng đánh giá là hệ điều hành nhúng rất phù hợp để phát triển hệ thống IoT với các tính năng cơ bản như: tính an ninh, nhiều giao diện kết nối, có RTOS, nhiều thư viện cho các loại cảm biến và ngoại vi phổ biến và đặc biệt nó là open-source. 

	* **Apache Mynewt-OS:** Đây là một hệ điều hành nhúng thời gian thực, dạng mô đun dành cho các thiết bị IoT. Giao diện kết nối không dây đầu tiên mà OS này tập trung phát triển là Bluetooth Low Energy 4.2. Tuy nhiên do mới được phát triển nên các thư viện còn chưa phong phú.

	* **RIOT-OS:**  Đây là OS dành cho các IoT device, hỗ trợ real-time với dung lượng bộ nhớ cực kỳ ít. RIOT-OS có thể chạy trên các vi điều khiển 8 bit, 16 bit và 32 bit. Nó cung cấp các Network stacks như IPv6, 6LoWPAN, UDP, CoAP...

	* **Zephyr:** Là một hệ điều hành thời gian thực dung lượng nhỏ, an ninh, với kiến trúc nhân kiểu micro/nano kernel, hỗ trợ Bluetooth, Bluetooth LE, WiFi, 802.15.4, 6Lowpan, CoAP, IPv4, IPv6, và NFC. Vào tháng 2 năm 2016, Zephyr trở thành một project của Linux Foundation.

	* ...


**Tạm kết luận:** Để tiếp cận và nhanh chóng làm chủ VBLUno51 cũng như giao tiếp truyền thông Bluetooth Low Energy cho các ứng dụng IoT, chúng tôi khuyên bạn nên phát triển ứng dụng cho VBLUno51 sử dụng Arduino và mbed-OS. Hai công cụ này được cộng đồng quan tâm phát triển rất nhiều ví dụ mẫu. Hơn nữa, thư viện của chúng rất dễ để tìm hiểu và sử dụng. 
