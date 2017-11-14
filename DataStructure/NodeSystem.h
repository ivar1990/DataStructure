//*******************************************************************
//  LinkedList.h
//  LinkedList_Project
//
//  Created by Ivar Juarez 29, Nov., 2015.
//  This header file contains a Templated versions of the LinkedList class.
//*******************************************************************

#ifndef NodeSystem_h
#define NodeSystem_h

#include <iostream>
#include <string>
using namespace std;




//*******************************************************************
// LinkedList is a list of singly-linked nodes and a link node.
// The Link node provides a branching node for more variations.
//*******************************************************************
//friend class Connection;
//*******************************************************************
// Node structs contain data, position and a pointer to the next node.
// The data can contain any primitive data type.
//*******************************************************************
struct Node
{
	int data;
	unsigned int position;
	unsigned int node_id;
	Node *next;

};



class NodeSystem
{

public:

	// Applies to the Linked List.
	// origin of the list contains no data, 
	// but points to the end of the list.
	Node *origin = new Node;

	// End of Linked list
	Node *end = new Node;

	// Number of Nodes in the List.
	int listLength;

	// Result node at FindNode() operation.
	Node *search_node;

	// Default Constructor creates the origin node.
	NodeSystem();

	/***********************List of Nodes***********************/
	//Takes the nodes and repositions them in ascending order.
	//Position starts at 1 with the origin as position 0.
	void repositionNodes();

	///
	bool Insert(int data, int node_id = 0);

	// adds a node to the list at a pre-determined position.
	// Duplicates are allowed.
	// Takes a value as parameters.
	// Position is calculated between 1 and the number of data nodes.
	// Returns true if the operation is successful.
	bool Add(int node_value);

	// removes a single node by a given value.
	// Returns true if the operation is successful.
	bool removeNode(int node_value);

	// Setter removes all duplicate nodes by a given value;
	// Returns the number of nodes that were removed.
	int removeAllNodes(int node_value);

	// Searches for a node by a given value.
	// Or search by a given position.
	// Returns true if the operation is successful.
	// Node can be access via *search_node
	bool FindNode(int node_value, int position = 0, unsigned int node_id = 0);

	// Checks to see if the NodeSystem has nodes to deallocate
	bool HasNodes();

	// Moves node to a different position
	//
	bool Move(int current_position, int destination_position);
	/***********************List of Nodes***********************/

	// Checks if nodes are the same in both NodeSystem list of nodes.
	friend bool operator==(const NodeSystem &n_sys1, const NodeSystem &n_sys2);


	// Prints each node in the list in consecutive order,
	// starting at the head and ending at the tail.
	// Prints list data to the console.
	void printList();

	// Destructor de-allocates memory used by the list.
	~NodeSystem();

private:
	//Max number of nodes required for parallel search.
	unsigned const int MAX_LENGTH = 100;

	


};


#endif
