#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <thread>
#include <chrono>

#include <string>
#include <iterator>     // std::advance
#include "InputDevice.h"

using namespace std;

InputDevice::InputDevice()
{
	Init();
	LoadNodeData();
}

void InputDevice::Init()
{
	
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

void InputDevice::LoadNodeData()
{
	for (int i = 0; i<=10; i++) data_nodes.push_back(i*10);
}

void InputDevice::CreateRandomNodes()
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

void InputDevice::EmptyBuffer()
{
	input_buffer.clear();
}

void InputDevice::Run()
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