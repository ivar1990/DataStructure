//*******************************************************************
//  LinkedList.h
//  LinkedList_Project
//
//  Created by Ivar Juarez 29, Nov., 2015.
//  This header file contains a Templated versions of the LinkedList class.
//*******************************************************************

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;




//*******************************************************************
// LinkedList is a list of singly-linked nodes and a link node.
// The Link node provides a branching node for more variations.
//*******************************************************************
template<class T>
class LinkedList
{
	//*******************************************************************
	// Node structs contain data, position and a pointer to the next node.
	// The data can contain any primitive data type.
	//*******************************************************************

	struct node
	{
		T data;
		unsigned int position;
		node *next;

	};
private:
	//Max number of nodes required for parallel search.
	unsigned const int MAX_LENGTH = 100;

	// origin of the list contains no data, 
	// but points to the end of the list.
	node *origin = new node;
	node *end = new node;



public:

	// Number of Nodes in the List.
	int listLength;

	// Result node at FindNode() operation.
	node *search_node;

	// Default Constructor creates the origin node.
	LinkedList();


	///Takes the nodes and repositions them in ascending order.
	///Position starts at 1 with the origin as position 0.
	void repositionNodes();

	//// Setter adds a node to the list at a pre-determined position.
	//// Duplicates are allowed.
	//// Takes a value as parameters.
	//// Position is calculated between 1 and the number of data nodes.
	//// Returns true if the operation is successful.
	bool Add(T node_value);

	//// Setter removes a single node by a given value.
	//// Returns true if the operation is successful.
	bool removeNode(T node_value);

	//// Setter removes all duplicate nodes by a given value;
	//// Returns the number of nodes that were removed.
	int removeAllNodes(T node_value);

	//// Searches for a node by a given value.
	//// Or seach by a given position.
	//// Returns true if the operation is successful.
	//// Node can be access via *search_node
	bool FindNode(T node_value, int position = 0);

	bool Move(int current_position, int destination_position);


	// Prints each node in the list in consecutive order,
	// starting at the head and ending at the tail.
	// Prints list data to the console.
	void printList();

	// Destructor de-allocates memory used by the list.
	~LinkedList();
};

#endif

// Default Constructor creates the head node.
template<class T>
LinkedList<T>::LinkedList()
{

	origin->data = 0;
	origin->position = 0;
	origin->next = NULL;

	end->data = 0;
	end->position = 0;
	end->next = NULL;
	listLength = 0;
}

template<class T>
void LinkedList<T>::repositionNodes()
{
	listLength = 0;
	node *p = origin;
	while (p != end)
	{
		p = p->next;
		listLength++;
		p->position = listLength;
	}


}

template<class T>
bool LinkedList<T>::Add(T node_value)
{
	node *newNode = new node;
	node *p = origin;

	newNode->data = node_value;
	if (origin->next == NULL)
	{
		origin->next = newNode;
		newNode->next = end;
		listLength++;
		newNode->position = listLength;
		return true;
	}
	else
	{
		while (p != end)
		{
			p = p->next;
			if (p->next == end)
			{
				p->next = newNode;
				newNode->next = end;
				listLength++;
				newNode->position = listLength;
				return true;
			}
		}
	}

	return false;
}

template<class T>
bool LinkedList<T>::removeNode(T node_value)
{
	///Needs to finish
	node *previous_node = origin;
	node *current_node = origin;
	node *next_node = origin->next;
	while (current_node != end)
	{
		previous_node = current_node;
		current_node = current_node->next;
		next_node = next_node->next;
		if (current_node->data == node_value)
		{
			cout << " " << endl;
			cout << " " << endl;
			cout << "Match:" << endl;
			cout << " " << endl;
			cout << " " << endl;

			cout << "Previous Node: " << previous_node << endl;
			cout << "|| position: " << previous_node->position << " value: " << previous_node->data << endl;
			cout << "|| Next Node: " << previous_node->next << endl;
			cout << " " << endl;

			cout << "Current Node: " << current_node << endl;
			cout << "|| position: " << current_node->position << " value: " << current_node->data << endl;
			cout << "|| Next Node: " << current_node->next << endl;
			cout << " " << endl;

			cout << "Next Node: " << next_node << endl;
			cout << "|| position: " << next_node->position << " value: " << next_node->data << endl;
			cout << "|| Next Node: " << next_node->next << endl;
			cout << " " << endl;
			cout << " " << endl;

			previous_node->next = next_node;

			cout << "Previous Node: " << previous_node << endl;
			cout << "|| position: " << previous_node->position << " value: " << previous_node->data << endl;
			cout << "|| Next Node: " << previous_node->next << endl;
			cout << " " << endl;

			cout << "Deleted Node: " << current_node << endl;
			cout << "|| position: " << current_node->position << " value: " << current_node->data << endl;
			cout << "|| Next Node: " << current_node->next << endl;
			cout << " " << endl;

			cout << "Next Node: " << next_node << endl;
			cout << "|| position: " << next_node->position << " value: " << next_node->data << endl;
			cout << "|| Next Node: " << next_node->next << endl;
			cout << " " << endl;
			cout << " " << endl;

			delete current_node;
			repositionNodes();
			return true;
		}

	}

	return false;
}


template<class T>
int LinkedList<T>::removeAllNodes(T node_value)
{

	int count = 0;

	while (removeNode(node_value))
	{
		count++;
	}
	repositionNodes();
	return count;
}

template<class T>
bool LinkedList<T>::FindNode(T node_value, int position = 0)
{
	node *current_node = origin;

	//Search by Position.
	if (position > 0)
	{
		while (current_node != end)
		{
			current_node = current_node->next;
			if (current_node->position == position)
			{
				search_node = current_node;
				return true;
			}
		}
	}

	//Search by given Value;
	while (current_node != end)
	{
		current_node = current_node->next;
		if (current_node->data == node_value)
		{
			search_node = current_node;
			return true;
		}
	}
	return false;
}

template<class T>
bool LinkedList<T>::Move(int current_position, int destination_position)
{
	if (current_position > 0 && destination_position < listLength + 1)
	{
		FindNode(0, current_position);
		node *temp_current_node = search_node;
		node *current_node = new node;
		current_node->data = temp_current_node->data;
		current_node->position = temp_current_node->position;
		current_node->next = temp_current_node->next;

		cout << "Current Node: " << current_node << endl;
		cout << "|| position: " << current_node->position << " value: " << current_node->data << endl;
		cout << "|| Next Node: " << current_node->next << endl;
		cout << " " << endl;

		FindNode(0, destination_position);
		node *temp_destination_node = search_node;
		node *destination_node = new node;
		destination_node->data = temp_destination_node->data;
		destination_node->position = temp_destination_node->position;
		destination_node->next = temp_destination_node->next;
		cout << "Destination Node: " << destination_node << endl;
		cout << "|| position: " << destination_node->position << " value: " << destination_node->data << endl;
		cout << "|| Next Node: " << destination_node->next << endl;
		cout << " " << endl;

		temp_current_node->data = destination_node->data;
		//temp_current_node->position = destination_node->position;
		//temp_current_node->next = destination_node->next;

		temp_destination_node->data = current_node->data;
		//temp_destination_node->position = current_node->position;
		//temp_destination_node->next = current_node->next;

		/*current_node->data = temp_destination_node->data;
		current_node->position = temp_destination_node->position;
		current_node->next = temp_destination_node->next;

		destination_node->data = temp_current_node->data;
		destination_node->position = temp_current_node->position;
		destination_node->next = temp_current_node->next;*/

		/*delete temp_current_node;
		delete temp_destination_node;*/

		//delete current_node;
		//delete destination_node;

		return true;
	}
	else
	{
		cout << "Postion out of range." << endl;
		return false;
	}
}




template<class T>
void LinkedList<T>::printList()
{

	node *p = origin;
	node *q = end;
	int count = 0;

	cout << "Origin Node: " << origin << endl;
	while (p != end)
	{
		if (p != q)
		{
			cout << "Node: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " value: " << p->data << endl;
			cout << "|| Next Node: " << p->next << endl;
			cout << "n*****************************n" << endl;
			p = p->next;
			//q = p->next;
			count++;
		}
	}
	cout << "End Node: n" << end << endl;
}


template<class T>
LinkedList<T>::~LinkedList()
{
	node *p = origin;
	node *q = end;
	/*bool exit = false;
	while (exit != true)
	{
	p = q;
	q = p->next;
	if (q) delete p;
	}*/

	while (p != end)
	{
		q = p;
		p = p->next;
		delete q;

	}
	delete end;



}


