#include "stdafx.h"
#include "DeviceManager.h"

bool DeviceManager::Receive(Data data)
{
	std::list<Device>::iterator it;

	for (it = devices.begin(); it != devices.end(); ++it)
	{
		if (it->device_id == data.output_device_id)
		{
			it->Output();
		}
	}
}

Data DeviceManager::Transmit()
{
	Data data;
	std::list<Device>::iterator it;

	for (it = devices.begin(); it != devices.end(); ++it)
	{
		data.input_device_id = it->device_id;
		data.data = it->input[it->input_node_position];
	}

}