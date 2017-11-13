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
	/*for (int i = 0; i < 256; i++)
	{
		nodes->Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}*/
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
	inFile.open("data.dat");

	string numbers;
	char ch;
	int file_out = 0;

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			//get(inFile, STRING); // Saves the line in STRING.
			//cout << STRING; // Prints our STRING.
			inFile.get(ch);

			//cout << ch << ":" << static_cast<int>(ch);
			
			if (ch == '|')
			{
				numbers = "";
				cout << ch << endl;
			}
			
			if (ch == '\n')
			{
				numbers = "";
				cout << endl;
			}

			if (ch != '|' && ch != '\n')
			{
				//nodes->Add(atoi(&ch));
				numbers = numbers + ch;
				cout << "char:" << atoi(&ch) << endl;
				cout << "numbers:" << numbers << endl;
			}
			
		}
	}
	inFile.close();

	nodes->printList();
}

void Storage::WriteToDisk()
{
	ofstream outFile;
	const char separator = '|';
	const char terminator = '\n';
	outFile.open("data.dat", ios::app);

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
				
				outFile << nodes->search_node->data << separator;
				outFile << nodes->search_node->position << separator;
				outFile << nodes->search_node->node_id << terminator;
				//outFile.write((char*)&nodes->search_node->data, sizeof(nodes->search_node->data));
				//outFile.write(&separator, sizeof(separator));
				//outFile.write((char*)&nodes->search_node->position, sizeof(nodes->search_node->position));
				//outFile.write(&separator, sizeof(separator));
				//outFile.write((char*)&nodes->search_node->node_id, sizeof(nodes->search_node->node_id));
				//outFile.write(&separator, sizeof(separator));
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