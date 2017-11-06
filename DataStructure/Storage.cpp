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

void Storage::WriteToDisk()
{

}


Storage::~Storage()
{
	WriteToDisk();
}