#include "stdafx.h"
#include "Abstractor.h"

using namespace std;

Abstractor::Abstractor()
{
	
}

void Abstractor::SetStorage(Storage *pStorage)
{
	storage = pStorage;

	assembler->SetNodeSystem(storage->nodes);
	assembler->SetConnections(storage->connections);
}

/*Node Creation Process*/
Node* Abstractor::CreateNode()
{
	Node *pResult;

	//Create new node ID
	int new_node_id = storage->nodes->listLength + 1;
	storage->nodes->Add(new_node_id);

	//Find and set resulting node
	storage->nodes->FindNode(0,0,new_node_id);
	pResult = storage->nodes->search_node;
	return pResult;
	
}

void Abstractor::CreateRandomNodeConnection(Node *pNode)
{
	//Node positions
	int parent_node_position = 0;
	int child_node_position = 0;

	//Node with data
	Node *parent_node = pNode;
	Node *child_node;

	
	//random number generation
	srand(time(NULL));
	//Get a random Node position in the LinkedList 
	child_node_position = (rand() % storage->nodes->listLength) + 1;
	//Get Node 
	storage->nodes->FindNode(0, child_node_position);
	child_node = storage->nodes->search_node;

	storage->connections->AddConnection(parent_node, child_node);

}

void Abstractor::CreateRandomNodeConnections(Node *pNode, int max_size)
{
	//Modification Log for children nodes
	list<int> changes;

	//Node positions
	int parent_node_position = 0;
	int child_node_position = 0;

	//Node with data
	Node *parent_node = pNode;
	Node *child_node;

	//Maximun of 50 connections will be generated
	if (max_size < 1)
	{
		max_size = (rand() % 50) + 1;
	}

	srand(time(NULL));
	//int rand_num = 0;

	cout << "Amount of CONNECTIONS generated: " << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		
		child_node_position = (rand() % storage->nodes->listLength) + 1;
		storage->nodes->FindNode(0, child_node_position);
		child_node = storage->nodes->search_node;

		storage->connections->AddConnection(parent_node, child_node);

		//cout << rand_num << endl;
	}

	storage->connections->ShowConnections();
}
/*End of Node Creation Process*/

void Abstractor::MakeParentNode()
{
	pParentNode = CreateNode();
}

