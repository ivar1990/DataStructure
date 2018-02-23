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
	unsigned int device_type = 0;

	void SetDeviceType(unsigned int device_type)
	{
		this->device_type = device_type;
	}

	void SetNodeSystem(NodeSystem *pNodeSystem)
	{
		this->node_system = pNodeSystem;
	}

	void SetConnections(Connector *pConnections)
	{
		this->connections = pConnections;
	}

	void SetDeviceData();

	void Receive();

	void Transmit();

	void Output();

protected:

	NodeSystem *node_system;
	Connector *connections;
	Mapper mapper;

	void Init();
};


#endif
