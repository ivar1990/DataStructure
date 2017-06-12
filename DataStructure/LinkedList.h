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
	//friend class Connection;
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

	struct Connection
	{
		unsigned int position;
		node *Source;
		node *Target;
		Connection *Link;
	};

private:
	//Max number of nodes required for parallel search.
	unsigned const int MAX_LENGTH = 100;

	// Applies to the Linked List.
	// origin of the list contains no data, 
	// but points to the end of the list.
	node *origin = new node;
	node *end = new node;

	// Applies to the Connection List;
	Connection *start_connection = new Connection;
	Connection *end_connection = new Connection;

public:



	// Number of Nodes in the List.
	int listLength;

	// Number of Connections in the List
	int connection_count;

	// Result node at FindNode() operation.
	node *search_node;

	// Connection result at GetConnection() operation
	Connection *connection;

	// Connections result at GetConnections() operation
	Connection *node_connections;

	// Default Constructor creates the origin node.
	LinkedList();

	/***********************List of Nodes***********************/
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
	/***********************List of Nodes***********************/


	/***********************List of Connections***********************/
	void RepositionConnections();

	bool Connect(T source_data_value, T target_data_value);

	bool AddConnection(node *source, node *target);

	bool RemoveConnection(node *source, node *target, int position = 0);

	bool MoveConnection(int current_position, int destination_postion);

	bool GetConnection(node *source, int position = 0);

	void GetConnections(node *source);

	void ShowConnections();

	void PrintNodeConnections();

	void DeleteConnections(Connection *conn);



	/***********************List of Connections***********************/

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

	start_connection->position = 0;
	start_connection->Source = NULL;
	start_connection->Target = NULL;
	start_connection->Link = NULL;

	end_connection->position = 0;
	end_connection->Source = NULL;
	end_connection->Target = NULL;
	end_connection->Link = NULL;


	listLength = 0;
	connection_count = 0;
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


/*****************Connection**********************/
template<class T>
void LinkedList<T>::RepositionConnections()
{
	connection_count = 0;
	Connection *p = start_connection;
	while (p != end_connection)
	{
		p = p->Link;
		connection_count++;
		p->position = connection_count;
	}


}

template<class T>
bool LinkedList<T>::Connect(T source_data_value, T target_data_value)
{
	node *source;
	node *target;

	if (FindNode(source_data_value))
	{
		source = search_node;
		if (FindNode(target_data_value))
		{
			target = search_node;
			AddConnection(source, target);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

template<class T>
bool LinkedList<T>::AddConnection(node *source, node *target)
{
	Connection *new_connection = new Connection;
	Connection *p = start_connection;

	new_connection->Source = source;
	new_connection->Target = target;

	if (start_connection->Link == NULL)
	{
		start_connection->Link = new_connection;
		new_connection->Link = end_connection;
		connection_count++;
		new_connection->position = connection_count;
		return true;
	}
	else
	{
		while (p != end_connection)
		{
			p = p->Link;
			if (p->Link == end_connection)
			{
				p->Link = new_connection;
				new_connection->Link = end_connection;
				connection_count++;
				new_connection->position = connection_count;
				return true;
			}
		}
	}

	return false;
}

template<class T>
bool LinkedList<T>::RemoveConnection(node *source, node *target, int position = 0)
{
	///Needs to finish
	Connection *previous_connection = start_connection;
	Connection *current_connection = start_connection;
	Connection *next_connection = start_connection->Link;

	Connection *previous_conn = start_connection;
	Connection *current_conn = start_connection;
	Connection *next_conn = start_connection->Link;

	//Remove by Position.
	if (position > 0)
	{
		while (current_conn != end_connection)
		{
			previous_conn = current_conn;
			current_conn = current_conn->Link;
			next_conn = next_conn->Link;
			if (current_conn->position == position)
			{
				previous_conn->Link = next_conn;
				delete current_conn;
				RepositionConnections();
				return true;
			}
		}

	}



	while (current_connection != end_connection)
	{
		previous_connection = current_connection;
		current_connection = current_connection->Link;
		next_connection = next_connection->Link;
		if (current_connection->Source == source && current_connection->Target == target)
		{
			cout << " " << endl;
			cout << " " << endl;
			cout << "Match:" << endl;
			cout << " " << endl;
			cout << " " << endl;

			cout << "Previous Connection: " << previous_connection << endl;
			cout << "|| position: " << previous_connection->position << " Parent: " << previous_connection->Source << " Child: " << previous_connection->Target << endl;
			cout << "|| Next Connection: " << previous_connection->Link << endl;
			cout << " " << endl;

			cout << "Current Connection: " << current_connection << endl;
			cout << "|| position: " << current_connection->position << " Parent: " << current_connection->Source << " Child: " << current_connection->Target << endl;
			cout << "|| Next Connection: " << current_connection->Link << endl;
			cout << " " << endl;

			cout << "Next Connection: " << next_connection << endl;
			cout << "|| position: " << next_connection->position << " Parent: " << next_connection->Source << " Child: " << next_connection->Target << endl;
			cout << "|| Next Connection: " << next_connection->Link << endl;
			cout << " " << endl;
			cout << " " << endl;

			previous_connection->Link = next_connection;

			cout << "Previous Connection: " << previous_connection << endl;
			cout << "|| position: " << previous_connection->position << " Parent: " << previous_connection->Source << " Child: " << previous_connection->Target << endl;
			cout << "|| Next Connection: " << previous_connection->Link << endl;
			cout << " " << endl;

			cout << "Deleted Connection: " << current_connection << endl;
			cout << "|| position: " << current_connection->position << " Parent: " << current_connection->Source << " Child: " << current_connection->Target << endl;
			cout << "|| Next Connection: " << current_connection->Link << endl;
			cout << " " << endl;

			cout << "Next Connection: " << next_connection << endl;
			cout << "|| position: " << next_connection->position << " Parent: " << next_connection->Source << " Child: " << next_connection->Target << endl;
			cout << "|| Next Connection: " << next_connection->Link << endl;
			cout << " " << endl;
			cout << " " << endl;

			delete current_connection;
			RepositionConnections();
			return true;
		}

	}

	return false;
}


template<class T>
bool LinkedList<T>::MoveConnection(int current_position, int destination_position)
{
	if (current_position > 0 && destination_position < listLength + 1)
	{
		GetConnection(NULL, current_position);
		Connection *temp_current_connection = connection;
		Connection *current_connection = new Connection;
		current_connection->Source = temp_current_connection->Source;
		current_connection->Target = temp_current_connection->Target;
		current_connection->position = temp_current_connection->position;
		current_connection->Link = temp_current_connection->Link;

		cout << "Current Connection: " << current_connection << endl;
		cout << "|| position: " << current_connection->position << " Parent: " << current_connection->Source << " Child: " << current_connection->Target << endl;
		cout << "|| Next Connection: " << current_connection->Link << endl;
		cout << " " << endl;

		GetConnection(NULL , destination_position);
		Connection *temp_destination_connection = connection;
		Connection *destination_connection = new Connection;
		destination_connection->Source = temp_destination_connection->Source;
		destination_connection->Target = temp_destination_connection->Target;
		destination_connection->position = temp_destination_connection->position;
		destination_connection->Link = temp_destination_connection->Link;
		cout << "Destination Connection: " << destination_connection << endl;
		cout << "|| position: " << destination_connection->position << " Parent: " << destination_connection->Source << " Child: " << destination_connection->Target << endl;
		cout << "|| Next Connection: " << destination_connection->Link << endl;
		cout << " " << endl;

		temp_current_connection->Source = destination_connection->Source;
		temp_current_connection->Target = destination_connection->Target;
		//temp_current_node->position = destination_node->position;
		//temp_current_node->next = destination_node->next;

		temp_destination_connection->Source = current_connection->Source;
		temp_destination_connection->Target = current_connection->Target;
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
bool LinkedList<T>::GetConnection(node *source, int position = 0)
{
	Connection *current_connection = start_connection;

	//Search by Position.
	if (position > 0)
	{
		while (current_connection != end_connection)
		{
			current_connection = current_connection->Link;
			if (current_connection->position == position)
			{
				connection = current_connection;
				return true;
			}
		}
	}

	//Search by given Source node;
	while (current_connection != end_connection)
	{
		current_connection = current_connection->Link;
		if (current_connection->Source == source)
		{
			connection = current_connection;
			return true;
		}
	}
	return false;
}

template<class T>
void LinkedList<T>::GetConnections(node *source)
{
	int count = 0;

	Connection *current_connection = start_connection;
	Connection *new_connection = new Connection;
	Connection *head = new_connection;
	Connection *old_connection;
	new_connection->position = 0;
	new_connection->Source = NULL;
	new_connection->Target = NULL;
	new_connection->Link = NULL;



	//Gather connection by given Source node;
	while (current_connection != end_connection)
	{
		current_connection = current_connection->Link;
		if (current_connection->Source == source)
		{
			count++;
			old_connection = new_connection;

			new_connection = new Connection;
			new_connection->position = current_connection->position;
			new_connection->Source = current_connection->Source;
			new_connection->Target = current_connection->Target;
			new_connection->Link = NULL;
			old_connection->Link = new_connection;

		}
	}
	cout << "Number of connections: " << count << endl;
	node_connections = head;
}

template<class T>
void LinkedList<T>::ShowConnections()
{
	Connection *p = start_connection;
	Connection *q = end_connection;
	int count = 0;

	cout << "Starting Connection: " << start_connection << endl;
	while (p != end_connection)
	{
		if (p != q)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;
			p = p->Link;
			//q = p->next;
			count++;
		}
	}
	cout << "End Connection: n" << end_connection << endl;
}


template<class T>
void LinkedList<T>::PrintNodeConnections()
{
	Connection *p = node_connections;

	cout << " " << endl;
	cout << "Showing connections for: " << endl;
	cout << "Parent Node: " << p->Source << endl;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;
		}
		p = p->Link;
	}
}

template<class T>
void LinkedList<T>::DeleteConnections(Connection *conn)
{
	//Applies to Connections List.
	Connection *pointer = conn;
	Connection *e;

	while (pointer != NULL)
	{
		e = pointer;
		pointer = pointer->Link;
		delete e;

	}
	
}



/*****************End of Connection*********************/

template<class T>
LinkedList<T>::~LinkedList()
{
	//Applies to Nodes List;
	node *p = origin;
	node *q = end;
	/*bool exit = false;
	while (exit != true)
	{
	p = q;
	q = p->next;
	if (q) delete p;
	}*/

	while (p != end || p != NULL)
	{
		q = p;
		p = p->next;
		delete q;

	}
	delete end;

	//Applies to Connections List.
	Connection *pointer = start_connection;
	Connection *e = end_connection;

	while (pointer != end_connection)
	{
		e = pointer;
		pointer = pointer->Link;
		delete e;

	}
	delete end_connection;

	DeleteConnections(node_connections);
}











