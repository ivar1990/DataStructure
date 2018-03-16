#ifndef DEVICE_h
#define DEVICE_h

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

using namespace std;

class Device
{
public:

	unsigned int device_id = 0;

	unsigned int device_type = 0;

	string name;

	NodeSystem node_system;
	Connector Connections;

	int input[3];
	string output[3];


	int input_node_position = 0;
	int output_node_position = 0;

	void SetDeviceID(unsigned int device_id)
	{
		this->device_id = device_id;
	}

	void SetDeviceType(unsigned int device_type)
	{
		this->device_type = device_type;
	}

	void SetDeviceName(string device_name)
	{
		this->name = device_name;
	}
	
	void Connect();

	void GetDeviceData(NodeSystem *pNodeSystem, int device_data_id);

	void Receive();

	void Transmit();

	void Output();

protected:

	Mapper mapper;

	void Init();
};


#endif
