#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

#include <string>
#include <iterator>     // std::advance
#include "Storage.h"
#include "Device.h"

using namespace std;

Device::Device()
{
	Init();
	LoadData();
}

void Device::SetDeviceID(unsigned int deviceId)
{
	device_id = deviceId;
}

unsigned int Device::GetDeviceID()
{
	return device_id;
}

void Device::Init()
{
	device_id = 1;

	cout << "Please enter the size of the input buffer(must be less than 8): ";
	cin >> max_size;

	if (max_size > MAX_SIZE)
	{
		max_size = MAX_SIZE;
	}
	cout << "The input buffer size is " << max_size << endl;

	cout << "Please enter the number of seconds to wait until buffer is cleared: ";
	cin >> seconds_to_wait;

	if (seconds_to_wait > SECONDS_TO_WAIT)
	{
		seconds_to_wait = SECONDS_TO_WAIT;
	}
	cout << "The input buffer size is " << seconds_to_wait << endl;
}

void Device::LoadData()
{
	for (int i = 0; i <= 10; i++)
	{
		data_nodes.push_back(i * 10);
		cout << "Data: " << i * 10 << endl;
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

void Device::LoadNodeData(Storage *pStorage)
{
	

	//Locate Device ID stored in node system
	pStorage->nodes->FindNode(0, 0, device_id);

	pStorage->connections->GetConnections(pStorage->nodes->search_node);

	Connection *p = pStorage->connections->node_connections;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
			cout << "P: " << p->Source->data << "---->" << "C: " << p->Target->data << endl;
			cout << "Node: " << p->Source->data << "---->" << " " << static_cast<char>(p->Target->data) << endl;
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;

			raw_data_nodes.push_back(p->Target);

		}
		p = p->Link;
	}
}


void Device::CreateRandomData()
{

	srand(time(NULL));
	int rand_index = 0;
	int number_of_inputs = (rand() % max_size) + 1;
	list<int>::iterator it = data_nodes.begin();

	cout << "Amount of nodes generated: " << number_of_inputs << endl;
	for (int i = 0; i < number_of_inputs; i++) {
		rand_index = (rand() % data_nodes.size()) + 0;

		advance(it, rand_index);

		cout << "The " << rand_index << " element in mylist is: " << *it << '\n';
		input_buffer.push_back(*it);

		it = data_nodes.begin();
		//cout << rand_num << endl;
	}
}

void Device::CreateRandomNodes()
{

	srand(time(NULL));
	int rand_index = 0;
	int number_of_inputs = (rand() % max_size) + 1;
	list<Node*>::iterator it = raw_data_nodes.begin();

	cout << "Amount of nodes generated: " << number_of_inputs << endl;
	for (int i = 0; i < number_of_inputs; i++) {
		rand_index = (rand() % raw_data_nodes.size()) + 0;

		advance(it, rand_index);

		cout << "The " << rand_index << " element in mylist is: " << *it << '\n';
		input_node_buffer.push_back(*it);

		it = raw_data_nodes.begin();
		//cout << rand_num << endl;
	}
}

void Device::EmptyBuffer()
{
	input_buffer.clear();
}

void Device::EmptyNodeBuffer()
{
	input_node_buffer.clear();
}

void Device::Run()
{
	int time_to_wait = seconds_to_wait * 1000;
	bool stop = false;

	while (!stop)
	{
		if (GetKeyState(VK_ESCAPE) & 0x80)
		{
			stop = true;
		}
		else
		{
			cout << "running" << endl;

			CreateRandomNodes();
			for (std::list<int>::iterator it = input_buffer.begin(); it != input_buffer.end(); ++it)
				std::cout << ' ' << *it;

			std::cout << '\n';
			std::this_thread::sleep_for(std::chrono::milliseconds(time_to_wait));
			EmptyBuffer();
		}
	}
}