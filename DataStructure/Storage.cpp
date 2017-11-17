#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

#include "Storage.h"

using namespace std;

Storage::Storage()
{
	Init();
}

void Storage::Init()
{
	NodeSystem  *node_system = new NodeSystem();
	nodes = node_system;

	Connector *connector = new Connector(nodes);
	connections = connector;

	//Adds 1-255 as nodes
	//See Ascii table for reference
	/*for (int i = 0; i < 256; i++)
	{
		nodes->Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}*/
}

void Storage::PrintStorage()
{
	//track node in the node system
	int current_node_position = 1;
	cout << "Begin write.!!!!" << endl;
	if (nodes->HasNodes())
	{
		//Set search Node to node position 0
		nodes->FindNode(0, 0);
		cout << "Has Node to write.!!!!" << endl;
		while (current_node_position != nodes->listLength + 1)
		{

			nodes->FindNode(0, current_node_position);


			//Write Node data to console
			cout << "Node " << nodes->search_node->position << ": " << nodes->search_node << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| value: " << nodes->search_node->data << endl;
			cout << "n*****************************n" << endl;
			current_node_position++;

		}
	}
	else
	{
		cout << "No nodes to write to disk!!!!." << endl;
	}

	cout << "End Node: n" << endl;
}

void Storage::LoadFromDisk()
{
	LoadNodes();
	LoadConnections();
}

void Storage::LoadNodes()
{
	ifstream inFile;
	inFile.open("data.dat");

	string numbers;
	int node_id = 0;
	int data_value = 0;
	char ch;
	int file_out = 0;

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			//get(inFile, STRING); // Saves the line in STRING.
			//cout << STRING; // Prints our STRING.
			inFile.get(ch);

			//cout << ch << ":" << static_cast<int>(ch);

			if (ch == '|')
			{
				cout << "at |: " << numbers << endl;
				//cout << ch << endl;
				node_id = stoi(numbers);
				numbers = "";
			}

			if (ch == '\n' && numbers != "")
			{
				cout << "at new line: " << numbers << endl;
				data_value = stoi(numbers);
				nodes->Insert(data_value, node_id);
				numbers = "";
			}

			if (ch != '|' && ch != '\n')
			{
				//nodes->Add(atoi(&ch));
				numbers = numbers + ch;
				//cout << "char:" << atoi(&ch) << endl;
				//cout << "numbers:" << numbers << endl;
			}

		}
	}
	inFile.close();

	nodes->printList();
}

void Storage::LoadConnections()
{
	ifstream inFile;
	inFile.open("Connections.dat");

	string numbers;
	
	int affinity = 0;
	int connection_id = 0;
	int source_id = 0;
	int target_id = 0;
	char ch;
	int file_out = 0;

	if (inFile.is_open()) {
		while (!inFile.eof()) {
			//get(inFile, STRING); // Saves the line in STRING.
			//cout << STRING; // Prints our STRING.
			inFile.get(ch);

			//cout << ch << ":" << static_cast<int>(ch);

			if (ch == ',')
			{
				cout << "at ,: " << numbers << endl;
				//cout << ch << endl;
				affinity = stoi(numbers);
				numbers = "";
			}

			if (ch == '^')
			{
				cout << "at ^: " << numbers << endl;
				//cout << ch << endl;
				connection_id = stoi(numbers);
				numbers = "";
			}

			if (ch == '|')
			{
				cout << "at |: " << numbers << endl;
				//cout << ch << endl;
				source_id = stoi(numbers);
				numbers = "";
			}

			if (ch == '\n' && numbers != "")
			{
				cout << "at new line: " << numbers << endl;
				target_id = stoi(numbers);
				connections->Insert(affinity, connection_id, source_id, target_id);
				numbers = "";
			}

			if (ch != ',' && ch != '^' && ch != '|' && ch != '\n')
			{
				//nodes->Add(atoi(&ch));
				numbers = numbers + ch;
				//cout << "char:" << atoi(&ch) << endl;
				//cout << "numbers:" << numbers << endl;
			}

		}
	}
	inFile.close();

	//nodes->printList();
}

void Storage::WriteToDisk()
{
	if (nodes->listLength > 0)
	{
		cout << "Saving Nodes:.........." << endl;
		SaveNodes();
		cout << "Nodes Saved!" << endl;
	}
	
	if (connections->connection_count > 0)
	{
		cout << "Saving Connections:.........." << endl;
		SaveConnections();
		cout << "Connections Saved!" << endl;
	}
	
}

void Storage::SaveNodes()
{
	ofstream outFile;
	const char separator = '|';
	const char terminator = '\n';
	outFile.open("data.dat");

	//track node in the node system
	int current_node_position = 1;
	cout << "Begin write.!!!!" << endl;
	if (nodes->HasNodes())
	{
		//Set search Node to node position 0
		nodes->FindNode(0, 0);
		cout << "Has Node to write.!!!!" << endl;
		while (current_node_position != nodes->listLength + 1)
		{

			nodes->FindNode(0, current_node_position);


			//Write Node data to console
			cout << "Node " << nodes->search_node->position << ": " << nodes->search_node << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| value: " << nodes->search_node->data << endl;
			cout << "n*****************************n" << endl;

			outFile << nodes->search_node->node_id << separator;
			outFile << nodes->search_node->data << terminator;

			current_node_position++;


		}
	}
	else
	{
		cout << "No nodes to write to disk!!!!." << endl;
	}

	cout << "End Node: n" << endl;


	outFile.close();
}

void Storage::SaveConnections()
{
	ofstream outFile;
	const char pipe_separator = '|';
	const char comma_separator = ',';
	const char caret_separator = '^';
	const char terminator = '\n';
	outFile.open("Connections.dat");

	//track connections in the connector
	int current_connection_position = 1;
	cout << "Begin write.!!!!" << endl;
	if (connections->HasConnections())
	{
		
		cout << "Has Connections to write.!!!!" << endl;
		while (current_connection_position != connections->connection_count + 1)
		{

			connections->FindConnection(current_connection_position,0);


			//Write Node data to console
			cout << "Connection: " << connections->result_connection << endl;
			cout << "n-----------------------------n" << endl;
			cout << "position: " << connections->result_connection->position << endl;
			cout << "Affinity: " << connections->result_connection->affinity << endl;
			cout << "Connection ID" << connections->result_connection->connection_id << endl;
			cout << "Source ID" << connections->result_connection->source_id << endl;
			cout << "Target ID" << connections->result_connection->target_id << endl;
			cout << "n*****************************n" << endl;

			outFile << connections->result_connection->affinity << comma_separator;
			outFile << connections->result_connection->connection_id << caret_separator;
			outFile << connections->result_connection->source_id << pipe_separator;
			outFile << connections->result_connection->target_id << terminator;

			current_connection_position++;


		}
	}
	else
	{
		cout << "No connections to write to disk!!!!." << endl;
	}

	cout << "End Connection: n" << endl;


	outFile.close();
}


Storage::~Storage()
{
	
}