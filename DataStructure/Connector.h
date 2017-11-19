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
	//incremental ID of the connection in a linked list 
	unsigned int position;

	//checks likeness between source node and target node
	int affinity = 0;

	//Connection ID
	unsigned int connection_id;

	//Parent Node ID
	unsigned int source_id;

	//Child Node ID 
	unsigned int target_id;

	//Parent node pointer
	Node *Source;

	//Child node pointer
	Node *Target;

	//Pointer to the next connection node in the linked list
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

	//Connection result at FindConnection() operation
	Connection *result_connection;

	// Connections result at GetConnections() operation
	Connection *node_connections;

	Connector(NodeSystem *pNode_system);

	Connector();

	/***********************List of Connections***********************/
	void RepositionConnections();

	//bool Connect(int source_data_value, int target_data_value);

	bool Connect(unsigned int source_node_id, unsigned int target_node_id);

	bool AddConnection(Node *source, Node *target);

	bool Insert(int affinity, int connection_id, int source_id, int target_id);

	bool RemoveConnection(Node *source, Node *target, int position = 0);

	bool MoveConnection(int current_position, int destination_postion);

	bool GetConnection(Node *source, int position = 0, unsigned int connection_id = 0);

	void GetConnections(Node *source);

	bool HasConnections();

	bool FindConnection(unsigned int position = 0, unsigned int connection_id = 0);

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
