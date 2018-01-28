
#include "stdafx.h"
#include <iostream>
#include <string>

#include "Assembler.h"

using namespace std;


Assembler::Assembler()
{
	
}

Assembler::Assembler(NodeSystem *pComponents)
{
	//Sets the User supplied inputs as the list that will be used
	node_system = pComponents;

	LoadAsciiTable();
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

void Assembler::CreateNode()
{
	ResetNode(generated_node);
	//Create new node ID
	int new_node_id = node_system->listLength + 1;
	//sets the created node's data to its node id
	node_system->Add(new_node_id);

	//Find and set resulting node
	node_system->FindNode(0, 0, new_node_id);
	//set the node to the generated node
	generated_node = node_system->search_node;
}

bool Assembler::Connect(Node *pParentNode, Node *pChildNode)
{

	return connections->AddConnection(pParentNode, pChildNode);
}

bool Assembler::Disconnect(Node *pChildNode)
{
	connections->GetConnections(generated_node);

	Connection *p = connections->node_connections;
	Connection *connection_to_be_removed = NULL;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			if(p->Target == pChildNode)
			{
				connection_to_be_removed = p;
			}
		}
		p = p->Link;
	}
	return connections->RemoveConnection(NULL,NULL,0,connection_to_be_removed->connection_id);
}

void Assembler::DestroyNode()
{
	DestroyConnections(generated_node);
	node_system->RemoveNode(generated_node);
	
}

void Assembler::DestroyConnections(Node *pNode)
{
	cout << "Number of Destroyed Connections: " << connections->RemoveAllConnections(pNode);
}

void Assembler::ResetNode(Node *pGeneratedNode)
{
	if (generated_node != NULL)
	{
		cout << "Generated Node will be overwritten!!!" << endl;
		DestroyConnections(generated_node);
		DestroyNode();

		generated_node = pGeneratedNode;
	}
	else
	{
		generated_node = pGeneratedNode;
	}
}