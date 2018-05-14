#ifndef INPUTDEVICE_h
#define INPUTDEVICE_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

using namespace std;

class InputDevice
{
public:

	//Number of nodes that can be generated in the input buffer
	unsigned const int MAX_SIZE = 7;
	//generates nodes every N seconds
	unsigned const int SECONDS_TO_WAIT = 5;
	
	//User specified number of nodes
	unsigned int max_size = 0;
	//User specified seconds
	unsigned int seconds_to_wait = 0;

	
	//raw data
	list<int> data_nodes;

	//contains nodes
	list<int> input_buffer;
	
	InputDevice();

	void LoadNodeData();

	void CreateRandomNodes();

	void Run();

	

private:
	void Init();
	
	void EmptyBuffer();
};

#endif