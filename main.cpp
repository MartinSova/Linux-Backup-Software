#include "daemon.h"
#include "localmanager.h"
#include "connection.h"
#include "filemanager.h"
#include "statusmanager.h"
#include <iostream>
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <dirent.h>
#include <malloc.h>
#include <usb.h>
#include <typeinfo>

using namespace std;

#define BUF_SIZE 1024


pair<deviceIds, deviceIds> getAvailableDevices()
{
    // initiate usb library
    libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices
    libusb_context *ctx = NULL; //a libusb session
    int r; //for return values
    r = libusb_init(&ctx); //initialize a library session
    if(r < 0) {
        nullptr;
    }
    libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation
    pair<deviceIds, deviceIds> connectedDevices = localManager::availableDevices(ctx, devs);
    return connectedDevices;
}

int main(int argc, char *argv[])
{
    filemanager::existsConfigurationFile();
    filemanager::existsStatusFile();
    pair<deviceIds, deviceIds> availableDevices = getAvailableDevices();
    /*
    if (availableDevices == nullptr) {
        cerr << "Init Error" << r << endl; //there was an error
        return 1;
    }
    */



    deviceIds myvector;

    myvector.push_back(make_pair(66666,11666111));

    StatusManager::writeConnectedDevices(myvector, true);

    //connection *c = new connection();



    //l.canBeRegistered(ctx, devs, r, connectedDevices.);

/*
    libusb_register_hotplug_listeners(ctx, deviceAdded, deviceRemoved, 0);

    while(1) libusb_handle_events(ctx);
*/
    //libusb_free_device_list(devs, 1); //free the list, unref the devices in it





    return 0;

    /*

    device registered and connected? yes? do ---->
    no? ------> canBeRegistered and see if viable for registtration
    */
}


