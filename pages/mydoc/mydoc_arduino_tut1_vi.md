---
title: Thiết bị theo dõi nhịp tim với VBLUno
tags: [huong_dan]
sidebar: mydoc_sidebar
permalink: mydoc_arduino_tut1_vi.html
language: vi
folder: mydoc
---

# VÍ DỤ MINH HỌA THIẾT BỊ THEO DÕI NHỊP TIM VỚI VBLUNO V2

* Thiết bị theo dõi nhịp tim: Heart Rate Monitor– HRM

Hình dưới thể hiện cấu trúc của Heart Rate Service (HRS)

![](images/ble/introduce/12.png) 

* Ta thấy, HRS bao gồm 2 characteristics giúp cung cấp thông tin về nhịp tim và vị trí gắn cảm biến trên cơ thể. Chi tiết có thể xem tại đường dẫn sau:

https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.service.heart_rate.xml

* Ví dụ sau minh họa một thiết bị BLE có chức năng đo nhịp tim và truyền về BLE Central (Smartphones, tablets, PC). Vì không có cảm biến hỗ trợ tính năng này nên trong ví dụ này mình chỉ tạo giả tín hiệu theo mô tả sau:

	+ Giá trị nhịp tim thay đổi tuyến tính từ 100 đến 175 với độ tăng là 1

	+ Vị trí cảm biến trên cơ thể: Finger (mã = 0x03)
	
* Thực hiện:

	+ Mở Arduino IDE 
	
	+ Chạy ví dụ HRM: `File --> Examples --> BLE_Examples --> BLE_HRM`

	+ Tiến hành biên dịch và upload xuống bo mạch VBLUno. Nếu thành công bạn đã có một thiết bị BLE minh họa tính năng theo dõi nhịp tim.
	
	+ Để kết nối đến thiết bị này, bạn cần một BLE Central (Smart phone, tablet, PC). Ở đây mình dùng phần mềm nRF Toolbox của Nordic và phần mềm BLE Tool để minh họa.

![](images/ble/introduce/13.png) 

* Trên điện thoại Android hoặc iPhone, chạy phần mềm nRF Toolbox, chọn mục HRM, nhấn Connect để tìm kiếm thiết bị HRM và yêu cầu kết nối.

![](images/ble/introduce/14.png) 

![](images/ble/introduce/15.png) 

![](images/ble/introduce/16.png) 

Mã nguồn của chương trình ví dụ khá đơn giản, bạn có thể tự đọc và tìm hiểu.
