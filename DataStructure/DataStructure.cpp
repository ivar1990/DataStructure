// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

//#include "LinkedList.h"
#include "Assembler.h"


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

	Assembler assembler;

	Structure structure;

	assembler.GenerateRandomNodes(&structure);
	assembler.GenerateRandomConnections(&structure);

	assembler.OutputStructure(&structure);
	
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

