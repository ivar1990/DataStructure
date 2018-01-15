#ifndef Assembler_h
#define Assembler_h

#include <iostream>
#include <string>
#include <list>

#include "NodeSystem.h"
#include "Connector.h"


using namespace std;


//assembles Nodes into a structure
class Assembler
{
public:
	//Sets the list of nodes 
	void SetNodeSystem(NodeSystem *pNodeSystem)
	{
		node_system = pNodeSystem;
	}

	//Sets the list of connections
	void SetConnections(Connector *pConnections)
	{
		connections = pConnections;
	}

	//Creates an empty list of nodes.
	NodeSystem default_node_system;

	//Points to list of nodes 
	NodeSystem *node_system;

	//Points to list of connections
	Connector  *connections;

	/// <summary>
	/// Data that the assembler will use 
	/// To construct Structures
	/// </summary>
	/// <param name="NodeSystem">User Supplied list of int nodes..</param>
	/// <returns></returns>
	Assembler(NodeSystem *pComponents);

	//Uses default Data(numbers 1-255 of the ascii table)
	//To construct Structures
	Assembler();

	//Adds Data(numbers 1-255 of the ascii table) to the node_system
	void LoadAsciiTable();

	//creates a node 
	Node* CreateNode();

	/// <summary>
	/// Creates a connection
	/// </summary>
	/// <param name=""></param>
	/// <returns></returns>
	Connection* CreateConnection(Node *pParentNode, Node *pChildNode);

	//removes node from NodeSystem and connections from connector
	void DestoryNode();
	
	//remove connections to Connector 
	void DestroyConnections(Node *pNode);


	
	
};

#endif