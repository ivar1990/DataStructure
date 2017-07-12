// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//#include "LinkedList.h"
#include "Assembler.h"
#include "Storage.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//LinkedList<int> list;

	//list.Add(2);
	//list.Add(3);
	//list.Add(4);

	//for (int i = 0; i < 5; i++)
	//{
	//	list.Add(i);
	//}

	//list.printList();
	////cout << "Amount of Nodes Deleted: " << list.removeAllNodes(3) << endl
	//if (list.FindNode(2,4))
	//{
	//	cout << "Found node value: " << list.search_node->data << " at position: " << list.search_node->position << endl;
	//}
	//else
	//{
	//	cout << "could not find value" << endl;
	//}
	//list.printList();

	//list.Move(5, 7);
	//cout << "Moving:........." << endl;

	//list.printList();
	//list.Connect(2, 2);
	//list.Connect(4, 1);
	//list.Connect(2, 1);
	//list.Connect(3, 2);
	//list.Connect(2, 4);

	//list.ShowConnections();

	//list.FindNode(2);

	//list.GetConnections(list.search_node);

	//list.PrintNodeConnections();

	//list.MoveConnection(2, 4);

	//list.ShowConnections();
	

	//Connector connector;
	//connector.Connect(119, 114);

	//connector.ShowConnections();

	//Reference Table
	//1 = number
	//2 = subtraction
	//3 = addition
	//4 = multiplication
	//5 = division
	//6 = equal
	Assembler assembler;
	Storage storage;

	for (int i = 0; i < 256; i++)
	{
		Structure *structure = new Structure;
		structure->Add(i);
		storage.AddStructure(structure);
	}

	Structure *structure256 = new Structure;
	structure256->Add(67);
	structure256->Add(68);
	structure256->Add(69);
	structure256->Add(70);

	structure256->connections->Connect(67, 68);
	structure256->connections->Connect(68, 69);
	structure256->connections->Connect(69, 70);
	structure256->connections->Connect(70, 67);

	Structure *structure257 = new Structure;
	structure257->Add(256);
	structure257->Add(68);

	structure257->connections->Connect(68, 256);


	storage.AddStructure(structure256);
	storage.AddStructure(structure257);



	storage.PrintAllStructures();


	/*Structure structure;
	Structure structure2;
	Structure *structure3 = new Structure;

	structure.nodes->Add(65);
	structure.nodes->Add(67);
	structure.nodes->Add(69);
	structure.nodes->Add(6);

	structure.connections->Connect(6, 65);
	structure.connections->Connect(6, 67);
	structure.connections->Connect(6, 69);

	structure2.nodes->Add(105);
	structure2.nodes->Add(114);
	structure2.nodes->Add(118);
	structure2.nodes->Add(65);

	structure2.connections->Connect(65, 105);
	structure2.connections->Connect(65, 114);
	structure2.connections->Connect(65, 65);
	structure2.connections->Connect(65, 118);
	structure2.nodes->FindNode(65);
	structure.nodes->FindNode(105);
	structure2.connections->AddConnection(structure2.nodes->search_node, structure.nodes->search_node);

	structure3->nodes->Add(65);
	structure3->nodes->Add(67);

	structure3->connections->Connect(65, 67);

	storage.AddStructure(structure3);
	storage.PrintAllStructures();

	//assembler.GenerateRandomNodes(&structure);
	//assembler.GenerateRandomConnections(&structure);

	//assembler.OutputStructure(&structure);
	//assembler.OutputStructure(&structure2);
	//assembler.OutputStructure(&structure3);
	*/
	
	
	//NodeSystem node_system;
	//Connector connector(&node_system);
	
	//Abstractor abstractor;

	//abstractor.ConstructRandomStructure();
	

	/*for (int i = 0; i < 256; i++)
	{
		node_system.Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}

	node_system.printList();

	node_system.FindNode(87);

	cout << "Node: " << node_system.search_node << endl;*/


	//connector.Connect(98, 114);
	////connector.Connect(114, 98);
	//connector.Connect(98, 119);
	//connector.Connect(114, 119);
	//connector.Connect(119, 114);
	//connector.Connect(119, 98);


	/*Abstractor abstractor(&node_system, &connector);

	string text;
	int ascChar;
	cout << "Please enter a line of text:" << endl;
	getline(cin, text);

	cout << text << endl;

	for (int i = 0; i<text.length(); i++)
	{
		ascChar = text[i];
		cout << ascChar << ": " << static_cast<char>(ascChar) << endl;
		
	}

	abstractor.Input(text);

	cout << "Please enter a line of text:" << endl;
	getline(cin, text);

	cout << text << endl;
*/



	//abstractor.Input(text);

	//connector.ShowConnections();

	//cout << "Status: " << connector.SearchConnections(connector.node_connections, 101) << endl;

	/*abstractor.RandomLink(87);
	abstractor.RandomLink(87);
	abstractor.RandomLink(87);
	abstractor.RandomLink(87);

	abstractor.OutputConstruct(87);*/

	//abstractor.Construct();
	

	
	//list.RemoveConnection(NULL, NULL, 2);

	//list.ShowConnections();

	//LinkedList<node> Connections;

	system("pause");

	return 0;
}

