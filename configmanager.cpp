#include "configmanager.h"


deviceIds ConfigManager::readRegisteredDevices()
{
    if (!ifstream("configuration.json")) {
        // ERROR: no configuration file
    }
    else {
        ifstream i("configuration.json");
        json j;
        i >> j;
        deviceIds registeredDevices;

        for ( auto &device : j["registeredDevices"].get<json>() ) {
            registeredDevices.push_back(make_pair(device["vendorId"], device["productId"]));
        }

        return registeredDevices;
    }
}



