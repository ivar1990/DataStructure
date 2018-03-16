#include "stdafx.h"
#include "Device.h"

void Device::Init()
{
	//Input/Output Device
	SetDeviceType(0);

	this->input[0] = 1; //green
	this->input[1] = 2; //yellow
	this->input[2] = 3; //red

	this->output[0] = "Go";
	this->output[1] = "Wait";
	this->output[2] = "Stop";

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
	//random number generation
	srand(time(NULL));
	//random index from input array
	input_node_position = (rand() % 3) + 1;
}

void Device::Transmit()
{

}

void Device::Output()
{
	const int num_Outputs = sizeof(this->output) / sizeof(output[0]);

	for (int count = 0; count < num_Outputs; count++)
		if (count == this->output_node_position)
			cout << "Output: " << this->output[count];
}