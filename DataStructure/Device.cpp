#include "stdafx.h"
#include "Device.h"

void Device::Init()
{
	//Input/Output Device
	SetDeviceType(0);

}

void Device::GetDeviceData(NodeSystem *pNodeSystem, int device_data_id)
{
	Node *Start = pNodeSystem->Start;
	Node *End = pNodeSystem->End;

	Node *p = pNodeSystem->Start->next;

	while (p != NULL)
	{
		node_system.Add(p->data);
		p = p->next;
	}
}

void Device::Connect()
{

}

void Device::Receive()
{

}

void Device::Transmit()
{

}

void Device::Output()
{

}