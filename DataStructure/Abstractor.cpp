#include "stdafx.h"
#include "Abstractor.h"

using namespace std;

Abstractor::Abstractor()
{
	NodeSystem *n_sys = new NodeSystem();
	Connector *conn = new Connector(n_sys);

	node_system = n_sys;
	connections = conn;
}

Abstractor::Abstractor(NodeSystem *pNodeSystem)
{

	Connector *conn = new Connector(pNodeSystem);

	node_system = pNodeSystem;
	connections = conn;
}


void Abstractor::Input(int ascChar)
{
	dataset.push_back(ascChar);
}

void Abstractor::GetFeedback()
{
	cout << "FeedBack Table: " << endl;
	map<int, int>::iterator it;
	int i = 0;
	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
	{
		cout << endl;
		cout << "Solution No. " << i << endl;
		i++;
		cout << static_cast<char>(it->first) << " => " << it->second << '\n';
		SeparateByFrequency(it->first);
	}
}

void Abstractor::GenerateRandomDataSet(int max_size)
{
	if (max_size < 1)
	{
		max_size = (rand() % 50) + 1;
	}


	srand(time(NULL));
	int rand_num = 0;

	cout << "Amount of nodes generated: " << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		/* generate random number between 1 and 255: */
		rand_num = (rand() % 255) + 1;

		dataset.push_back(rand_num);
		
		//cout << rand_num << endl;
	}

	for (std::list<int>::iterator it = dataset.begin(); it != dataset.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

void Abstractor::GenerateRandomNodes(int max_size)
{
	//Maximun of 50 nodes will be generated
	if (max_size < 1)
	{
		max_size = (rand() % 50) + 1;
	}


	srand(time(NULL));
	int rand_num = 0;

	cout << "Amount of NODES generated: " << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		/* generate random number between 1 and 255: */
		rand_num = (rand() % 255) + 1;

		node_system->Add(rand_num);

		//cout << rand_num << endl;
	}

	cout << "NodeSystem from Abstractor" << endl;
	node_system->printList();
}

void Abstractor::GenerateRandomConnections(int max_size)
{
	//Node positions
	int parent_node_position = 0;
	int child_node_position = 0;

	//Node with data
	Node *parent_node;
	Node *child_node;

	//Maximun of 50 connections will be generated
	if (max_size < 1)
	{
		max_size = (rand() % 50) + 1;
	}

	srand(time(NULL));
	int rand_num = 0;

	cout << "Amount of CONNECTIONS generated: " << max_size << endl;
	for (int i = 0; i < max_size; i++) {
		//generate random number between 1 and node list length
		//sets the random number as the position of the parent node's position in the list
		parent_node_position = (rand() % node_system->listLength) + 1;
		//search for the node in the position(the generated random number) in the list of nodes 
		node_system->FindNode(0, parent_node_position);
		//assigns the searched node to the parent node pointer.
		parent_node = node_system->search_node;


		child_node_position = (rand() % node_system->listLength) + 1;
		node_system->FindNode(0, child_node_position);
		child_node = node_system->search_node;

		connections->AddConnection(parent_node, child_node);

		//cout << rand_num << endl;
	}

	connections->ShowConnections();
}

void Abstractor::GenerateFrequencyTable()
{
	//dataset is a list<int> container
	//frequency_table is a map<int, int> container

	list<int>::iterator dataset_it;
	map<int, int>::iterator frequencytable_it;

	if (frequency_table.empty())
	{
		frequency_table.insert(pair<int, int>(0, 0));
	}

	///Traverse list<int> container
	for (dataset_it = dataset.begin(); dataset_it != dataset.end(); ++dataset_it)
	{
		//std::cout << "dataset number: " << *dataset_it << endl;
		///traverse map<int,int> container
		for (frequencytable_it = frequency_table.begin(); frequencytable_it != frequency_table.end(); ++frequencytable_it)
		{
				//*dataset_it is the numeric value stored from input
				//frequencytable_it->first is a none repeating numeric value from input
				//frequencytable_it->second is how many time the *dataset_it value is repeated
				//E.g: *dataset_it  = { 1, 2, 2, 4, 3, 1  }   
				//frequencytable_it->first   | frequencytable_it->second
				//		1					 |			2
				//		2					 |			2
				//		3					 |			1
				//		4					 |			1
				if (*dataset_it == frequencytable_it->first)
				{
					//increment the count
					frequencytable_it->second++;
				}
				else
				{
					//insert a new unique value
					frequency_table.insert(pair<int, int>(*dataset_it, 0));
				}

			//cout << frequencytable_it->first << " => " << frequencytable_it->second << '\n';
		}
	}
}

void Abstractor::OutputFrequencyTable()
{
	GenerateFrequencyTable();
	// show content:
	cout << "Frequency Table: " << endl;
	map<int, int>::iterator it;

	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
		cout << it->first << " => " << it->second << '\n';
}

void Abstractor::SeparateByFrequency(int frequency_num)
{

	list<int>::iterator it;

	for (it = dataset.begin(); it != dataset.end(); it++)
	{
		if (frequency_num != *it)
		{
			cout << static_cast<char>(*it);
		}
		else
		{
			cout << "\n";
			cout << static_cast<char>(frequency_num) << "\n";
		}
	}
}

void Abstractor::Output()
{
	cout << "Response Table: " << endl;
	map<int, int>::iterator it;
	int i = 0;
	for (it = frequency_table.begin(); it != frequency_table.end(); it++)
	{
		cout << endl;
		cout << "Solution No. " << i << endl;
		i++;
		cout << static_cast<char>(it->first) << " => " << it->second << '\n';
		SeparateByFrequency(it->first);
	}
}

void Abstractor::LogInputs()
{
	int i = inputs.size() + 1;
	inputs.insert(pair<int, list<int>>(i, dataset));
}

bool Abstractor::IsChanged()
{
	if (dataset.size() > size)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void Abstractor::OutputInputs()
{
	cout << "Input Table: " << endl;
	map<int, list<int>>::iterator it;
	list<int>::iterator l_it;
	int i = 0;

	for (it = inputs.begin(); it != inputs.end(); it++)
	{
		cout << endl;
		cout << "Inputs No. " << i << endl;
		i++;
		for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << static_cast<char>(*l_it);
		}
	}
}

/* Abstraction of Trial and Error method*/

/*Node Creation Process*/
Node* Abstractor::CreateNode()
{
	Node *pResult;

	//Create new node ID
	int new_node_id = node_system->listLength + 1;
	node_system->Add(new_node_id);

	//Find and set resulting node
	node_system->FindNode(0,0,new_node_id);
	pResult = node_system->search_node;
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
	child_node_position = (rand() % node_system->listLength) + 1;
	//Get Node 
	node_system->FindNode(0, child_node_position);
	child_node = node_system->search_node;

	connections->AddConnection(parent_node, child_node);
}

void Abstractor::CreateRandomNodeConnections(Node *pNode, int max_size)
{
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
		
		child_node_position = (rand() % node_system->listLength) + 1;
		node_system->FindNode(0, child_node_position);
		child_node = node_system->search_node;

		connections->AddConnection(parent_node, child_node);

		//cout << rand_num << endl;
	}

	connections->ShowConnections();
}
/*End of Node Creation Process*/


float Abstractor::GetFeedBack()
{
	float affinity = 0.0;
	cout << "********************************" << endl;
	cout << "Test Node: " << test_node << endl;
	cout << "Node ID: " << test_node->node_id << endl;
	cout << "Position: " << test_node->position << endl;
	cout << "Node Data: " << test_node->data << endl;
	cout << "--------------------------------" << endl;
	connections->GetConnections(test_node);
	cout << "--------------------------------" << endl;

	cout << "Enter correctness of node using float 0.0 - 0.1: " << endl;
	cin >> affinity;

	return affinity;
}

void Abstractor::ModifyTestNode(int hint, float affinity)
{
	//Needs to finish
	switch (hint)
	{
		case 1 :
			///Add another connection
			CreateRandomNodeConnection(test_node);
			break;

		case 2 :
			///remove a connection
			connections->RemoveConnection(test_node, NULL, 0, 0);
			break;
		case 3 :
			///reorder connections
			break;
	default:
		///generate new connections
		connections->RemoveConnection(test_node, NULL, 0, 0);
		CreateRandomNodeConnections(test_node);
		break;
	}


}