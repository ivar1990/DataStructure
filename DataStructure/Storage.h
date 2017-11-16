#ifndef Storage_h
#define Storage_h

#include <iostream>
#include <string>
#include <map>

//#include "Structure.h"
#include "Assembler.h"

using namespace std;

class Storage
{

public:

	Storage();

	unsigned int structure_id = 0;

	//Manages all Nodes and Connections
	//Reads and writes all nodes and connections to disk
	//Modify existing and new entries
	NodeSystem *nodes;
	Connector *connections;


	void PrintStorage();

	void LoadFromDisk();

	void WriteToDisk();

	~Storage();

private:

	void Init();

	void SaveNodes();

	void SaveConnections();

	

};

#endif