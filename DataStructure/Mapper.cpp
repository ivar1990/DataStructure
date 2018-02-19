#include "stdafx.h"
#include "Mapper.h"

#include <iomanip>

using namespace std;

Mapper::Mapper()
{
	
}

void Mapper::SetStorage(Storage *pStorage)
{
	storage = pStorage;

	assembler->SetNodeSystem(storage->nodes);
	assembler->SetConnections(storage->connections);

	textdiagram.SetNodeSystem(storage->nodes);
	textdiagram.SetConnections(storage->connections);
}

void Mapper::SetAssembler(Assembler *pAssembler)
{
	assembler = pAssembler;
}

/*Node Creation Process*/
Node* Mapper::CreateNode()
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

void Mapper::CreateRandomNodeConnection(Node *pNode)
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

void Mapper::CreateRandomNodeConnections(Node *pNode, int max_size)
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

void Mapper::MakeNode()
{
	pParentNode = CreateNode();
}

bool Mapper::IsCircular(Node *pStart)
{
	if (pStart == NULL)
		return false;

	Node *pSlow, *pFast;

	pSlow = pFast = pStart;

	while (true)
	{
		pSlow = pSlow->next;

		if (pFast->next != NULL)
			pFast = pFast->next->next;
		else
			return false;

		if (pSlow == NULL || pFast == NULL)
			return false;

		if (pSlow == pFast)
			return true;
	}

}

bool Mapper::CheckChildIsParent(Node *pParentNode)
{
	//needs to finish
	return false;
}

void Mapper::DisplayAllNodeConnections(Node *pParentNode)
{
	Connection *node_connections;
	Connection *current_connection;
    storage->connections->GetConnections(pParentNode);

	node_connections = storage->connections->node_connections;
	current_connection = node_connections->Link;

	//Parent's and Child connections
	while (current_connection != NULL)
	{
		cout << std::setw(2) << "******";
		textdiagram.PrintNode(current_connection->Target);
		//Children of Children connections
		cout << "Starting Child Connections" << endl;
		DisplayAllNodeConnections(current_connection->Target);
		cout << "Ending Child Connection" << endl;
		current_connection = current_connection->Link;
	}
}

//works but needs better implementation
//Return Parameter is useless
int Mapper::Iterate(Node *pParentNode, int stop_node_id)
{
	Connection *node_connections;
	Connection *current_connection;
	
	storage->connections->GetConnections(pParentNode);

	node_connections = storage->connections->node_connections;
	current_connection = node_connections->Link;

	//Parent's and Child connections
	while (current_connection != NULL)
	{
		cout << std::setw(2) << "******";
		textdiagram.PrintNode(current_connection->Target);
		if (current_connection->Target->node_id != stop_node_id && stop_node_id != 0)
		{
			//Children of Children connections
			cout << "Parent Node ID: " << current_connection->Source->node_id << " Child Node ID: " << current_connection->Target->node_id << " Query Node ID: " << stop_node_id << endl;
			Iterate(current_connection->Target, stop_node_id);
			//cout << "Ending Child Connection" << endl;
			current_connection = current_connection->Link;
		}
		else
		{
			cout << "Found node in connections! Node ID: " << current_connection->Target->node_id << endl;
			pResultNode = current_connection->Target;
			return 1;
		}
		
	}
	cout << "Could not Find Node ID: " << stop_node_id << endl;
	return 0;
}