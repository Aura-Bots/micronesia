#pragma once

#include <ArduinoBLE.h>

BLEService messageService("180A");
BLEStringCharacteristic messageCharacteristic("2A57", BLERead | BLEWrite, 20);

void initBLE() {
    BLE.begin();
    BLE.setLocalName("Micronesia");
    BLE.setAdvertisedService(messageService);
    messageService.addCharacteristic(messageCharacteristic);
    BLE.addService(messageService);
    BLE.advertise();
}

