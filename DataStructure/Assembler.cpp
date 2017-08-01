
#include "stdafx.h"
#include <iostream>
#include <string>

#include "Assembler.h"

using namespace std;


Assembler::Assembler()
{
	

	LoadAsciiTable();

	//Sets the default node system as the list that will be used 
	pNodeSystem = &default_node_system;
}

Assembler::Assembler(NodeSystem *pComponents)
{
	//Sets the User supplied inputs as the list that will be used
	pNodeSystem = pComponents;
}



void Assembler::LoadAsciiTable()
{
	//Adds 1-255 as nodes
	//See Ascii table for reference
	for (int i = 0; i < 256; i++)
	{
		default_node_system.Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}

	
}

void Assembler::GenerateRandomNodes(Structure *structure)
{
	cout << "Node Length: " << pNodeSystem->listLength << endl;

	srand(time(NULL));

	int new_data = (rand() % (pNodeSystem->listLength - 1)) + 1;
	int rand_num_nodes = (rand() % 50) + 1;
	int rand_num = 0;

	cout << "Amount of nodes generated: " << rand_num_nodes << endl;
	for (int i = 0; i < rand_num_nodes; i++) {
		/* generate random number between 1 and 255: */
		rand_num = (rand() % 255) + 1;

		structure->nodes->Add(rand_num);
		cout << rand_num << endl;
	}

}


void Assembler::GenerateRandomConnections(Structure *structure)
{
	cout << "Connection Length: " << pNodeSystem->listLength << endl;

	srand(time(NULL));

	int new_data = (rand() % (pNodeSystem->listLength - 1)) + 1;
	int rand_num_conn = (rand() % 10) + 1;
	int rand_num = 0;

	cout << "Amount of connections generated: " << rand_num_conn << endl;
	for (int i = 0; i < rand_num_conn; i++) {

		/* generate random number between 1 and 255: */

		rand_num = (rand() % 255) + 1;
		structure->connections->Connect(new_data, rand_num);
		cout << rand_num << endl;
	}
}


void Assembler::OutputStructure(Structure *structure)
{
	cout << "Structure identifier: " << structure->structure_id << endl;
	
	structure->nodes->printList();
	structure->connections->ShowConnections();
}

Structure* Assembler::AssembleStructure(list<int> components)
{
	Structure* structure = new Structure;

	list<int>::iterator it;

	for (it = components.begin(); it != components.end(); it++)
	{
		structure->nodes->Add(*it);
	}

	return structure;
}