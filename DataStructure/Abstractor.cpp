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
		
		child_node_position = (rand() % node_system->listLength) + 1;
		node_system->FindNode(0, child_node_position);
		child_node = node_system->search_node;

		connections->AddConnection(parent_node, child_node);

		//cout << rand_num << endl;
	}

	connections->ShowConnections();
}
/*End of Node Creation Process*/


int Abstractor::GetFeedBack()
{
	int affinity = 0;
	cout << "********************************" << endl;
	cout << "Test Node: " << test_node << endl;
	cout << "Node ID: " << test_node->node_id << endl;
	cout << "Position: " << test_node->position << endl;
	cout << "Node Data: " << test_node->data << endl;
	cout << "--------------------------------" << endl;
	connections->GetConnections(test_node);
	connections->ShowConnections();
	cout << "--------------------------------" << endl;

	cout << "Enter correctness of node using 0 - 9: " << endl;
	cin >> affinity;

	return affinity;
}

void Abstractor::ModifyTestNode(int hint, int affinity, int postion)
{
	//Needs to finish


	srand(time(NULL));
	int rand_num = (rand() % connections->connection_count) + 1;

	//Refresh changes  for new modifications.
	changes.clear();

	switch (hint)
	{
		case 1 :
			///Add another connection
			CreateRandomNodeConnection(test_node);
			break;

		case 2 :
			///remove a connection
			if (postion > 0)
			{
				//user specified
				connections->RemoveConnection(NULL, NULL, postion, 0);
			}
			else
			{
				//random
				cout << endl;
				cout << "Looking for random connection position: " << rand_num << endl;
				if (connections->FindConnection(rand_num,0))
				{
					connections->RemoveConnection(NULL, NULL, rand_num, 0);
				}
				else
				{
					cout << "Connection ID: " << rand_num << " not found. Please try again!" << endl;
				}
			}
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

void Abstractor::LogChanges(int responses,int affinity)
{
	//get all child node ids
	for (int i = 1; i < connections->connection_count + 1; i++)
	{
		connections->FindConnection(i, 0);
		changes.push_back(connections->result_connection->target_id);
		current_modification.push_back(connections->result_connection->target_id);
	}

	//Log changes
	modifications.insert(pair<int, list<int>>(responses, changes));
	//Log Feedback response
	feedback.insert(pair<int, int>(responses, affinity));
	//clear changes for next modification
	changes.clear();

}

void Abstractor::OutputModifications()
{
	cout << "Modifications: " << endl;
	map<int, list<int>>::iterator it;
	list<int>::iterator l_it;
	int i = 1;

	for (it = modifications.begin(); it != modifications.end(); ++it)
	{
		cout << endl;
		cout << "Modification No." << i << ":  ";
		
		for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << *l_it << ",";

		}
		i++;
		cout << endl;
	}
}

void Abstractor::OutputFeedback()
{
	cout << "FeedBack: " << endl;
	map<int,int>::iterator it;
	
	int i = 0;

	for (it = feedback.begin(); it != feedback.end(); it++)
	{
		cout << endl;
		cout << "Modification No:" << it->first << " FeedBack: " << it->second;
		cout << endl;
	}
}

int Abstractor::AnalizeModification(int modifcation_id)
{
	//Check the current modifications with the previous one
	//Gets last action(hint)
	//map<int, list<int>>::iterator it;
	//list<int>::iterator l_it;
	//list<int>::iterator current_modifications_it;

	int hint = 0;
	
	//it = modifications.find(modifcation_id);

	/*for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
	{
		if (find(current_modification.begin(), current_modification.end(), *l_it) != current_modification.end())
		{

		}

	}
	cout << endl;*/

	int current_modification_size = distance(current_modification.begin(), current_modification.end());
	int target_modification_list_size = distance(modifications.find(modifcation_id)->second.begin(), modifications.find(modifcation_id)->second.end());

	if (current_modification_size > target_modification_list_size)
	{
		hint = 1;
	}
	else
	{
		hint = 2;
	}

	return hint;

}

int Abstractor::CompareFeedBack(int current_feedback)
{

	//check this feedback with prevoius feedback 
	//call AnalizeModifications to see which nodes changed
	//see which list of modifications gave higher affinity
	map<int, int>::iterator it;
	//tracks the modification id with best feedback
	int modification_id = 0;

	for (it = feedback.begin(); it != feedback.end(); it++)
	{
		cout << endl;
		cout << "Modification No." << it->first << " FeedBack:  " << it->second;
		if (it->second > current_feedback)
		{
			//Sets modification id to best choice
			modification_id = it->first;
		}
		cout << endl;
	}

	return modification_id;

}

int Abstractor::GenerateHint(int feedback)
{
	//get feedback and make a decision to 
	//add, change, or remove children nodes
	return AnalizeModification(CompareFeedBack(feedback));
}

void Abstractor::Run()
{
	bool running = true;
	int hint = 0;
	int affinity = 0;
	int responses = 0;

	test_node = CreateNode();
	CreateRandomNodeConnections(test_node, 6);
	//for (int i = 1; i < connections->connection_count; i++)
	//{
	//	connections->FindConnection(i, 0);
	//	changes.push_back(connections->result_connection->target_id);
	//	current_modification.push_back(connections->result_connection->target_id);
	//}

	////Log changes
	//modifications.insert(pair<int, list<int>>(responses, changes));
	//changes.clear();
	list<int>::iterator l_it;

	while (running)
	{
		affinity = GetFeedBack();
		if (responses < 4)
		{
			cout << "Enter hint 1 or 2: " << endl;
			cin >> hint;
		}
		else
		{
			hint = GenerateHint(affinity);
			cout << "Generated hint: " << hint << endl;
		}
		ModifyTestNode(hint, affinity, 0);
		responses++;
		LogChanges(responses, affinity);
		

		
		cout << "Current Modifications: ";
		for (l_it = current_modification.begin(); l_it != current_modification.end(); l_it++)
		{
			cout << *l_it << ",";
		}
		cout << endl;
		OutputModifications();
		OutputFeedback();
		current_modification.clear();

		if ( affinity < 7)
		{
			running = true;
		}
		else
		{
			running = false;
			OutputModifications();
			OutputFeedback();
		}
	}
}