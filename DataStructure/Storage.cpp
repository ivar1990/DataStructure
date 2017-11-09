#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "Storage.h"

using namespace std;

Storage::Storage()
{
	Init();
}

void Storage::Init()
{
	NodeSystem  *node_system = new NodeSystem();
	nodes = node_system;

	Connector *connector = new Connector(nodes);
	connections = connector;

	//Adds 1-255 as nodes
	//See Ascii table for reference
	for (int i = 0; i < 256; i++)
	{
		nodes->Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}
}

void Storage::PrintStorage()
{
	//track node in the node system
	int current_node_position = 1;

	if (nodes->HasNodes())
	{
		while (nodes->search_node != NULL)
		{

			nodes->FindNode(0, current_node_position);

			if (nodes->search_node != NULL)
			{
				//Write Node data to console
				cout << "Node " << nodes->search_node->position << ": " << nodes->search_node << endl;

				cout << "n-----------------------------n" << endl;
				cout << "|| value: " << nodes->search_node->data << endl;
					//Write Node Connections to console
					connections->GetConnections(nodes->search_node);
					connections->PrintNodeConnections();

				cout << "n*****************************n" << endl;

				current_node_position++;
			}
			
		}
	}
	cout << "End Node: n" << endl;
}

void Storage::LoadFromDisk()
{
	ifstream inFile;
	inFile.open("data.dat", ios::binary);

	string STRING;

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			getline(inFile, STRING); // Saves the line in STRING.
			cout << STRING; // Prints our STRING.
		}
		}
	inFile.close();
}

void Storage::WriteToDisk()
{
	ofstream outFile;
	const char separator = ',';
	outFile.open("data.dat", ios::binary | ios::app);

	//track node in the node system
	int current_node_position = 1;
	cout << "Begin write.!!!!" << endl;
	if (nodes->HasNodes())
	{
		//Set search Node to node position 0
		nodes->FindNode(0, 0);
		cout << "Has Node to write.!!!!" << endl;
		while (current_node_position != nodes->listLength + 1)
		{
			
			nodes->FindNode(0, current_node_position);

			
				//Write Node data to console
				cout << "Node " << nodes->search_node->position << ": " << nodes->search_node << endl;

				cout << "n-----------------------------n" << endl;
				cout << "|| value: " << nodes->search_node->data << endl;
				//Write Node Connections to console
				//connections->GetConnections(nodes->search_node);
				//connections->PrintNodeConnections();

				cout << "n*****************************n" << endl;

				outFile.write((char*)&nodes->search_node->data, sizeof(nodes->search_node->data));
				outFile.write((char*)&nodes->search_node->position, sizeof(nodes->search_node->position));
				outFile.write((char*)&nodes->search_node->node_id, sizeof(nodes->search_node->node_id));
				outFile.write(&separator, sizeof(separator));
				current_node_position++;
			

		}
	}
	else
	{
		cout << "No nodes to write to disk!!!!." << endl;
	}
	
	cout << "End Node: n" << endl;


	outFile.close();
	
}


Storage::~Storage()
{
	
}