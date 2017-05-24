/*
  VNG IoT Lab - 2017

  Website: 
    + http://iotviet.com.vn
    + https://www.facebook.com/bleviet

  Examples for VBLUno v2 board

  MBED-OS_Ex4: iBeacon device

*/

#include "mbed.h"
#include "ble/services/iBeacon.h"

BLE ble;
    
void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
{
    BLE &ble          = params->ble;
    ble_error_t error = params->error;

    if (error != BLE_ERROR_NONE) {
        return;
    }
    
    /**
     * The Beacon payload has the following composition:
     * 128-Bit / 16byte UUID = E2 0A 39 F4 73 F5 4B C4 A1 2F 17 D1 AD 07 A9 61
     * Major/Minor  = 0x1122 / 0x3344
     * Tx Power     = 0xC8 = 200, 2's compliment is 256-200 = (-56dB)
     *
     * Note: please remember to calibrate your beacons TX Power for more accurate results.
     */
    const uint8_t uuid[] = {0xE2, 0x0A, 0x39, 0xF4, 0x73, 0xF5, 0x4B, 0xC4,
                            0xA1, 0x2F, 0x17, 0xD1, 0xAD, 0x07, 0xA9, 0x61};
    uint16_t majorNumber = 1122;
    uint16_t minorNumber = 3344;
    uint16_t txPower     = 0xC8;
    iBeacon *ibeacon = new iBeacon(ble, uuid, majorNumber, minorNumber, txPower);

    ble.gap().setAdvertisingInterval(1000); /* 1000ms. */
    ble.gap().startAdvertising();
}

int main(void)
{
    ble.init(bleInitComplete);
    
    /* SpinWait for initialization to complete. This is necessary because the
     * BLE object is used in the main loop below. */
    while (!ble.hasInitialized()) { /* spin loop */ }

    while (true) {
        ble.waitForEvent(); // allows or low power operation
    }
}
