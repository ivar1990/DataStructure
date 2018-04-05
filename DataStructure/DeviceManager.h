#ifndef DEVICEMANAGER_h
#define DEVICEMANAGER_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>
#include <algorithm>

#include "NodeSystem.h"
#include "Connector.h"
#include "Diagram.h"
#include "Mapper.h"
#include "Device.h"

using namespace std;

struct Data
{
	unsigned int input_device_id = 0;
	unsigned int output_device_id = 0;
	int data;
};

class DeviceManager
{
public:

	unsigned int num_of_devices = 0;
	list<Device> devices;
	
	void AddDevice(Device device);

	void RemoveDevice(Device device);

	Data Transmit();

	bool Receive(Data Data);

	void PollDevices();

};

#endif