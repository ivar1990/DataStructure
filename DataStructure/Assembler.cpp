
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

Node* Assembler::CreateNode()
{
	//Points to node created
	Node *pResult;

	//Create new node ID
	int new_node_id = node_system->listLength + 1;
	//sets the created node's data to its node id
	node_system->Add(new_node_id);

	//Find and set resulting node
	node_system->FindNode(0, 0, new_node_id);
	pResult = node_system->search_node;

	return pResult;
}

Connection* Assembler::CreateConnection(Node *pParentNode, Node *pChildNode)
{

	connections->AddConnection(pParentNode, pChildNode);
}

void Assembler::DestoryNode()
{

}

void Assembler::DestroyConnections(Node *pNode)
{
	connections->RemoveConnection(pNode,NULL,0);
}