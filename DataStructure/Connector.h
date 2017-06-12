//*******************************************************************
//  LinkedList.h
//  LinkedList_Project
//
//  Created by Ivar Juarez 29, Nov., 2015.
//  This header file contains a Templated versions of the LinkedList class.
//*******************************************************************

#ifndef Connector_h
#define Connector_h

#include <iostream>
#include <string>

#include "NodeSystem.h"

using namespace std;


struct Connection
{
	unsigned int position;
	Node *Source;
	Node *Target;
	Connection *Link;
};

class Connector
{
	

public:

	NodeSystem default_node_system;

	NodeSystem *pNodeSystem;

	// Number of Connections in the List
	int connection_count;

	// Connection result at GetConnection() operation
	Connection *connection;

	// Connections result at GetConnections() operation
	Connection *node_connections;

	Connector(NodeSystem *pNode_system);

	Connector();

	/***********************List of Connections***********************/
	void RepositionConnections();

	bool Connect(int source_data_value, int target_data_value);

	bool AddConnection(Node *source, Node *target);

	bool RemoveConnection(Node *source, Node *target, int position = 0);

	bool MoveConnection(int current_position, int destination_postion);

	bool GetConnection(Node *source, int position = 0);

	void GetConnections(Node *source);

	bool SearchConnections(Connection *source, int data);

	void ShowConnections();

	void PrintNodeConnections();

	void PrintConnections(Connection *pConnections);

	void DeleteConnections(Connection *conn);

	~Connector();

	/***********************List of Connections***********************/

private:

	// Applies to the Connection List;
	Connection *start_connection = new Connection;
	Connection *end_connection = new Connection;
};


#endif