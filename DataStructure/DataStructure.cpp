// DataStructure.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>

//#include "LinkedList.h"
#include "NodeSystem.h"
#include "Assembler.h"
#include "Storage.h"
#include "Mapper.h"
#include "Controller.h"
#include "Assembler.h"
#include "InputDevice.h"



int _tmain(int argc, _TCHAR* argv[])
{
	
	//Assembler assembler;
	Storage storage;
	Mapper mapper;
	Controller controller;
	Assembler assembler;
	TextDiagram textdiagram;
	InputDevice idevice;
	
	char ch;
	bool running = true;

	

	while (running)
	{
		string text;
		int ascChar;
		cout << "Please enter a line of text:" << endl;
		getline(cin, text);

		//cout << text << endl;
		/*
		for (int i = 0; i<text.length(); i++)
		{
			ascChar = text[i];
			abstractor.Input(ascChar);
			cout << ascChar << ": " << static_cast<char>(ascChar) << endl;

		}*/
		
		controller.SetStorage(&storage);
		controller.SetMapper(&mapper);
		

		storage.LoadFromDisk();

		assembler.SetNodeSystem(storage.nodes);
		assembler.SetConnections(storage.connections);

		mapper.SetAssembler(&assembler);
		mapper.SetStorage(&storage);

		textdiagram.SetNodeSystem(storage.nodes);
		textdiagram.SetConnections(storage.connections);

		/*
		assembler.CreateNode();
		cout << "Showing connnections for Node: " << assembler.pCurrentNode->node_id << endl;
		storage.connections->ShowConnections();
		storage.connections->Connect(assembler.pCurrentNode->node_id, 61);

		mapper.pCurrentNode = assembler.pCurrentNode;
		mapper.CreateRandomNodeConnections(assembler.pCurrentNode,1);
		storage.connections->GetConnections(assembler.generated_node);
		storage.connections->PrintNodeConnections();
		textdiagram.PrintNode(assembler.pCurrentNode);
		textdiagram.Print();

		//cout << "Node has Loop: " << mapper.IsCircular(mapper.pCurrentNode);
		//mapper.DisplayAllNodeConnections(mapper.pCurrentNode);

		storage.nodes->FindNode(0, 0, 117);
		mapper.pCurrentNode = storage.nodes->search_node;
		mapper.Iterate(mapper.pCurrentNode, 61);
		cout << "Result Node: " << mapper.pResultNode << endl;
		cout << "Result Node: " << mapper.pResultNode->node_id << endl;
		//assembler.DestroyNode();
		*/
		/*
		bool stop = false;

		while (!stop)
		{
			if (GetKeyState(VK_ESCAPE) & 0x80)
			{
				stop = true;
			}
			else
			{
				cout << "running" << endl;
				storage.nodes->printList();
				//storage.connections->ShowConnections();
			}
		}
		*/

		//idevice.Run();

		cout << "Continue? y/n: " << endl;
		cin.get(ch);
		cout << ch << endl;
		if (ch == 'y')
		{
			running = true;
		}
		else
		{
			running = false;
		}

		text = " ";
		getline(cin,text);
	}
	
	//controller.Close();


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

	system("pause");

	return 0;
}

