#include "stdafx.h"
#include <iostream>
#include <string>


#include "NodeSystem.h"

using namespace std;

// Default Constructor creates the head node.

NodeSystem::NodeSystem()
{

	origin->data = 0;
	origin->position = 0;
	origin->node_id = 0;
	origin->next = NULL;

	end->data = 0;
	end->position = 0;
	end->node_id = 0;
	end->next = NULL;

	listLength = 0;

}


void NodeSystem::repositionNodes()
{
	listLength = 0;
	Node *p = origin;
	while (p != end)
	{
		p = p->next;
		listLength++;
		p->position = listLength;
	}


}

bool NodeSystem::Insert(int data, int node_id)
{
	//&& FindNode(0,0,node_id) == false
	if (node_id > 0 )
	{
		Node *newNode = new Node;
		Node *p = origin;

		newNode->data = data;
		if (origin->next == NULL)
		{
			origin->next = newNode;
			newNode->next = end;
			listLength++;
			newNode->position = listLength;
			newNode->node_id = node_id;
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
					newNode->node_id = node_id;
					return true;
				}
			}
		}

		return false;
	}
	else
	{
		return false;
	}
}


bool NodeSystem::Add(int node_value)
{
	Node *newNode = new Node;
	Node *p = origin;

	newNode->data = node_value;
	if (origin->next == NULL)
	{
		origin->next = newNode;
		newNode->next = end;
		listLength++;
		newNode->position = listLength;
		newNode->node_id = listLength;
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
				newNode->node_id = listLength;
				return true;
			}
		}
	}

	return false;
}


bool NodeSystem::removeNode(int node_value)
{
	///Needs to finish
	Node *previous_node = origin;
	Node *current_node = origin;
	Node *next_node = origin->next;
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



int NodeSystem::removeAllNodes(int node_value)
{

	int count = 0;

	while (removeNode(node_value))
	{
		count++;
	}
	repositionNodes();
	return count;
}


bool NodeSystem::FindNode(int node_value, int position, unsigned int node_id)
{
	Node *current_node = origin;

	if (HasNodes())
	{
		//Search by Position.
		if (position > 0)
		{
			while (current_node->next != end || current_node->next != NULL)
			{
				current_node = current_node->next;
				if (current_node->position == position)
				{
					search_node = current_node;
					return true;
				}
			}
			return false;
		}

		//Search by Node ID.
		if (node_id > 0)
		{
			while (current_node->next != NULL || current_node->next != end)
			{
				current_node = current_node->next;
				if (current_node->node_id == node_id)
				{
					search_node = current_node;
					return true;
				}
			}
			return false;
		}
		else
		{
			return false;
		}

		//Search by given Value;
		while (current_node->next != end || current_node->next != NULL)
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
	else
	{
		return false;
	}
}

bool NodeSystem::HasNodes()
{
	if (origin->next != NULL || origin->next != end)
	{
		return true;
	}
	else
	{
		return false;
	}

}


bool NodeSystem::Move(int current_position, int destination_position)
{
	if (current_position > 0 && destination_position < listLength + 1)
	{
		FindNode(0, current_position);
		Node *temp_current_node = search_node;
		Node *current_node = new Node;
		current_node->data = temp_current_node->data;
		current_node->position = temp_current_node->position;
		current_node->next = temp_current_node->next;

		cout << "Current Node: " << current_node << endl;
		cout << "|| position: " << current_node->position << " value: " << current_node->data << endl;
		cout << "|| Next Node: " << current_node->next << endl;
		cout << " " << endl;

		FindNode(0, destination_position);
		Node *temp_destination_node = search_node;
		Node *destination_node = new Node;
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





void NodeSystem::printList()
{

	Node *p = origin;
	Node *q = end;
	int count = 0;

	cout << "Origin Node: " << origin << endl;
	if (HasNodes())
	{
		while (p->next != NULL)
		{
			if (p != q)
			{
				cout << "Node: " << p << endl;

				cout << "n-----------------------------n" << endl;
				cout << "|| Node ID: " << p->node_id << endl;
				cout << "|| position: " << p->position << " value: " << p->data << endl;
				cout << "|| Next Node: " << p->next << endl;
				cout << "n*****************************n" << endl;
				p = p->next;
				//q = p->next;
				count++;
			}
		}
	}
	cout << "End Node: n" << end << endl;
}


bool operator==(const NodeSystem &n_sys1, const NodeSystem &n_sys2)
{
	bool is_equal = true;

	Node *current_node = n_sys1.origin;
	Node *current_node2 = n_sys2.origin;

	//loop through NodeSystem1 nodes
	while (current_node != n_sys1.end)
	{
		current_node = current_node->next;
		current_node2 = current_node2->next;

		// Check postion and data for match
		if (current_node->position == current_node2->position && current_node->data == current_node2->data)
		{
			is_equal = true;
		}
		else
		{
			return false;
		}
	}

	return is_equal;
}


NodeSystem::~NodeSystem()
{
	//Applies to Nodes List;
	Node *p = origin;
	Node *q = end;
	/*bool exit = false;
	while (exit != true)
	{
	p = q;
	q = p->next;
	if (q) delete p;
	}*/

	while (p->next != NULL)
	{
		q = p;
		p = p->next;
		delete q;

	}
	delete end;


}
