/*
  VNG IoT Lab - 2017

  Website: 
    + http://iotviet.com.vn
    + https://www.facebook.com/bleviet

  Examples for VBLUno v2 board

  Arduino_Ex4: iBeacons device 

*/

#include <BLE_API.h>

#define DEVICE_NAME       "VBLUno_iBeacons"

BLEDevice ble;

const static uint8_t beaconPayload[] = {
  0x4C,0x00,                                                                       // Company Identifier Code = Apple
  0x02,                                                                            // Type = iBeacon
  0x15,                                                                            // Following data length
  0x71,0x3d,0x00,0x00,0x50,0x3e,0x4c,0x75,0xba,0x94,0x31,0x48,0xf1,0x8d,0x94,0x1e, // Beacon UUID
  0x00,0x49,                                                                       // Major
  0x00,0x0A,                                                                       // Minor
  0xC5                                                                             // Measure Power
};

void setup() {
  // put your setup code here, to run once
  // close peripheral power
  NRF_POWER->DCDCEN = 0x00000001;
  NRF_TIMER1->POWER = 0;
  NRF_TIMER2->POWER = 0;
  NRF_UART0->POWER  = 0;
  
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  
  ble.init(); 
  // set advertisement
  ble.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
  ble.accumulateAdvertisingPayload(GapAdvertisingData::MANUFACTURER_SPECIFIC_DATA, beaconPayload, sizeof(beaconPayload));
  ble.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
  // set advertise type  
  //  ADV_CONNECTABLE_UNDIRECTED
  //  ADV_CONNECTABLE_DIRECTED
  //  ADV_SCANNABLE_UNDIRECTED
  //  ADV_NON_CONNECTABLE_UNDIRECTED
  ble.setAdvertisingType(GapAdvertisingParams::ADV_NON_CONNECTABLE_UNDIRECTED);
  // 100ms; in multiples of 0.625ms
  ble.setAdvertisingInterval(160); 
  // set adv_timeout, in seconds
  ble.setAdvertisingTimeout(0);
  // start advertising
  ble.startAdvertising();
}

void loop() {
  // put your main code here, to run repeatedly:
  ble.waitForEvent();
}

