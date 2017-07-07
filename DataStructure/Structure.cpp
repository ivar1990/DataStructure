#include "stdafx.h"
#include <iostream>
#include <string>

#include "Structure.h"

using namespace std;

Structure::Structure()
{
	NodeSystem  *node_system = new NodeSystem();
	nodes = node_system;

	Connector *connector = new Connector(nodes);
	connections = connector;

	NodeSystem *instruction = new NodeSystem();
	instructions = instruction;
}

void Structure::Add(int data)
{
	//Any data is added as a int 
	nodes->Add(data);
}



//void Structure::ConstructRandomStructure()
//{
//	Structure *pStructure = new Structure;
//
//	//generates random nodes
//	srand(time(NULL));
//
//	int new_data = (rand() % (pNode_system->listLength - 1)) + 1;
//	int rand_num_conn = (rand() % 50) + 1;
//	int rand_num = 0;
//
//	for (int i = 0; i < rand_num_conn; i++) {
//
//		/* generate random number between 1 and 255: */
//
//		rand_num = (rand() % 255) + 1;
//		pStructure->nodes.Add(rand_num);
//		cout << rand_num << endl;
//	}
//
//	////generates random Connections
//	//srand(time(NULL));
//
//	//int new_data2 = (rand() % (pNode_system->listLength - 1)) + 1;
//	//int rand_num_conn2 = (rand() % 50) + 1;
//	//int rand_num2 = 0;
//
//	//for (int i = 0; i < rand_num_conn2; i++) {
//
//	//	/* generate random number between 1 and 255: */
//
//	//	rand_num2 = (rand() % 255) + 1;
//		pStructure->connector.Connect(2, 3);
//	//	cout << rand_num2 << endl;
//	//}
//
//	PrintStructure(pStructure);
//
//	delete pStructure;
//}



void Structure::LinkData()
{

}


//void Structure::RandomLink(int data)
//{
//	int rand_num;
//
//	/* initialize random seed: */
//	//srand(time(NULL));
//
//	for (int i = 0; i < 3; i++) {
//		/* generate random number between 1 and 255: */
//		rand_num = (rand() % 255) + 1;
//		pConnector->Connect(data, rand_num);
//		cout << rand_num << endl;
//	}
//
//}
//
//void Structure::OutputConstruct(int data)
//{
//	pNode_system->FindNode(data);
//	pConnector->GetConnections(pNode_system->search_node);
//	//node_system.PrintNodeConnections();
//
//	Connection *p = pConnector->node_connections;
//
//	cout << " " << endl;
//	cout << "Structure: " << endl;
//
//	while (p != NULL)
//	{
//		if (p->Source != NULL)
//		{
//			cout << "n-----------------------------n" << endl;
//			cout << p->Source->data << "----> " << p->Target->data << endl;
//			cout << static_cast<char>(p->Source->data) << "----> " << static_cast<char>(p->Target->data) << endl;
//			cout << "|| position: " << p->position << endl;
//			cout << "n-----------------------------n" << endl;
//		}
//		p = p->Link;
//	}
//}
//
//void Structure::Input(string text)
//{
//	int data_item = pNode_system->listLength + 1;
//
//	int ascChar;
//
//
//
//	cout << "New Node ID: " << data_item << endl;
//
//	pNode_system->Add(data_item);
//
//	for (int i = 0; i<text.length(); i++)
//	{
//		ascChar = text[i];
//
//		cout << ascChar << ": " << static_cast<char>(ascChar) << endl;
//
//
//
//		if (pNode_system->FindNode(ascChar))
//		{
//			pConnector->Connect(data_item, ascChar);
//		}
//	}
//
//	pNode_system->FindNode(data_item);
//
//	pConnector->GetConnections(pNode_system->search_node);
//
//	pConnector->PrintNodeConnections();
//
//	///for char connections
//
//	//pNode_system->FindNode(ascChar);
//
//	//pConnector->GetConnections(pNode_system->search_node);
//
//	//pConnector->PrintNodeConnections();
//
//	//NodeSystem inputs;
//
//	//inputs.Add(ascChar);
//
//}
//
////void Structure::PrintStructure(Structure *pStructure)
////{
////	
////
////}

Structure::~Structure()
{

}
