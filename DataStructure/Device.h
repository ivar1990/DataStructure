#ifndef DEVICE_h
#define DEVICE_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

using namespace std;

class Device
{
public:

	


	//raw data
	list<int> data_nodes;

	//contains nodes
	list<int> input_buffer;

	//Contains actual nodes
	list<Node*> raw_data_nodes;
	//Nodes that are generated
	list<Node*> input_node_buffer;


	Device();

	void SetDeviceID(unsigned int deviceId);

	unsigned int GetDeviceID();

	void LoadData();

	void CreateRandomData();

	void Run();


	void LoadNodeData(Storage *pStorage);

	void CreateRandomNodes();


private:

	//Identify each device
	unsigned int device_id = 0;

	//Number of nodes that can be generated in the input buffer
	unsigned const int MAX_SIZE = 7;
	//generates nodes every N seconds
	unsigned const int SECONDS_TO_WAIT = 5;

	//User specified number of nodes
	unsigned int max_size = 0;
	//User specified seconds
	unsigned int seconds_to_wait = 0;

	void Init();

	void EmptyBuffer();

	void EmptyNodeBuffer();
};

#endif