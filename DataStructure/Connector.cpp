#include "stdafx.h"
#include <iostream>
#include <string>

#include "Connector.h"

using namespace std;

Connector::Connector(NodeSystem *pNode_system)
{
	connection_count = 0;

	pNodeSystem = pNode_system;

	start_connection->position = 0;
	start_connection->connection_id = 0;
	start_connection->source_id = 0;
	start_connection->target_id = 0;
	start_connection->Source = NULL;
	start_connection->Target = NULL;
	start_connection->Link = NULL;

	end_connection->position = 0;
	end_connection->connection_id = 0;
	end_connection->source_id = 0;
	end_connection->target_id = 0;
	end_connection->Source = NULL;
	end_connection->Target = NULL;
	end_connection->Link = NULL;
}

Connector::Connector()
{
	
	pNodeSystem = &default_node_system;

	for (int i = 0; i < 256; i++)
	{
		pNodeSystem->Add(i);
		cout << i << ": " << static_cast<char>(i) << endl;

	}

	pNodeSystem->printList();

	cout << "is node in system: " << pNodeSystem->FindNode(119) << endl;

	if (pNodeSystem->FindNode(119))
	{
		cout << "Found at node: " << pNodeSystem->search_node << endl;
	}
	else
	{
		cout << "Could not find node." << endl;
	}

	connection_count = 0;

	start_connection->position = 0;
	start_connection->connection_id = 0;
	start_connection->source_id = 0;
	start_connection->target_id = 0;
	start_connection->Source = NULL;
	start_connection->Target = NULL;
	start_connection->Link = NULL;

	end_connection->position = 0;
	end_connection->connection_id = 0;
	end_connection->source_id = 0;
	end_connection->target_id = 0;
	end_connection->Source = NULL;
	end_connection->Target = NULL;
	end_connection->Link = NULL;


	Connect(1, 5);
	Connect(2, 54);
	Connect(43, 67);

	PrintNodeConnections();
}

/*****************Connection**********************/
void Connector::RepositionConnections()
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

//bool Connector::Connect(int source_data_value, int target_data_value)
//{
//	Node *source;
//	Node *target;
//
//	if (pNodeSystem->FindNode(source_data_value))
//	{
//		source = pNodeSystem->search_node;
//		if (pNodeSystem->FindNode(target_data_value))
//		{
//			target = pNodeSystem->search_node;
//			AddConnection(source, target);
//			return true;
//		}
//		else
//		{
//			cout << "Could not find Target Value: " << target_data_value << endl;
//			return false;
//		}
//	}
//	else
//	{
//		cout << "Could not find Source Value: " << source_data_value << endl;
//		return false;
//	}
//}

bool Connector::Connect(unsigned int source_node_id, unsigned int target_node_id)
{
	Node *source;
	Node *target;

	if (pNodeSystem->FindNode(0,0,source_node_id))
	{
		source = pNodeSystem->search_node;
		if (pNodeSystem->FindNode(0,0,target_node_id))
		{
			target = pNodeSystem->search_node;
			AddConnection(source, target);
			return true;
		}
		else
		{
			cout << "Could not find Target Value: " << target_node_id << endl;
			return false;
		}
	}
	else
	{
		cout << "Could not find Source Value: " << source_node_id << endl;
		return false;
	}
}

bool Connector::AddConnection(Node *source, Node *target)
{
	Connection *new_connection = new Connection;
	Connection *p = start_connection;

	new_connection->Source = source;
	new_connection->Target = target;

	if (start_connection->Link == NULL)
	{
		start_connection->Link = new_connection;
		connection_count++;
		new_connection->position = connection_count;
		new_connection->affinity = 0;
		new_connection->connection_id = connection_count;
		new_connection->source_id = source->node_id;
		new_connection->target_id = target->node_id;
		new_connection->Source = source;
		new_connection->Target = target;
		new_connection->Link = end_connection;
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
				connection_count++;
				new_connection->position = connection_count;
				new_connection->affinity = 0;
				new_connection->connection_id = connection_count;
				new_connection->source_id = source->node_id;
				new_connection->target_id = target->node_id;
				new_connection->Source = source;
				new_connection->Target = target;
				new_connection->Link = end_connection;
				return true;
			}
		}
	}

	return false;
}

bool Connector::Insert(int affinity, int connection_id, int source_id, int target_id)
{
	Connection *new_connection = new Connection;
	Connection *p = start_connection;


	if (start_connection->Link == NULL)
	{
		start_connection->Link = new_connection;
		connection_count++;
		new_connection->position = connection_count;
		new_connection->affinity = 0;
		new_connection->connection_id = connection_count;
		new_connection->source_id = source_id;
		new_connection->target_id = target_id;
		pNodeSystem->FindNode(0, 0, source_id);
		new_connection->Source = pNodeSystem->search_node;
		pNodeSystem->FindNode(0, 0, target_id);
		new_connection->Target = pNodeSystem->search_node;
		new_connection->Link = end_connection;
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
				connection_count++;
				new_connection->position = connection_count;
				new_connection->affinity = 0;
				new_connection->connection_id = connection_count;
				new_connection->source_id = source_id;
				new_connection->target_id = target_id;
				pNodeSystem->FindNode(0, 0, source_id);
				new_connection->Source = pNodeSystem->search_node;
				pNodeSystem->FindNode(0, 0, target_id);
				new_connection->Target = pNodeSystem->search_node;
				new_connection->Link = end_connection;
				return true;
			}
		}
	}

	return false;
}

bool Connector::RemoveConnection(Node *source, Node *target, int position, int connection_id)
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
		while (next_conn != NULL || next_conn != end_connection)
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

	//Remove by Connection ID.
	if (connection_id > 0)
	{
		while (next_conn != NULL || next_conn != end_connection)
		{
			previous_conn = current_conn;
			current_conn = current_conn->Link;
			if (next_conn->Link != NULL)
			{
				next_conn = next_conn->Link;
			}
			else
			{
				next_conn = end_connection;
			}

			if (current_conn->connection_id != NULL && current_conn->connection_id == connection_id)
			{
				previous_conn->Link = next_conn;
				delete current_conn;
				RepositionConnections();
				return true;
			}
		}

	}


	while (next_connection != NULL || next_connection != end_connection)
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

bool Connector::MoveConnection(int current_position, int destination_position)
{
	if (current_position > 0 && destination_position < connection_count + 1)
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

		GetConnection(NULL, destination_position);
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

bool Connector::GetConnection(Node *source, int position, unsigned int connection_id)
{
	Connection *current_connection = start_connection;

	if (HasConnections())
	{
		//Search by given Source node;
		while (current_connection->Link != end_connection || current_connection->Link != NULL)
		{
			current_connection = current_connection->Link;
			if (current_connection->Source == source)
			{
				connection = current_connection;
				return true;
			}
		}
	

		//Search by Position.
		if (position > 0)
		{
			while (current_connection->Link != end_connection || current_connection->Link != NULL)
			{
				current_connection = current_connection->Link;
				if (current_connection->position == position)
				{
					connection = current_connection;
					return true;
				}
			}
			return false;
		}

		//Search by Connection ID.
		if (connection_id > 0)
		{
			while (current_connection->Link != end_connection || current_connection->Link != NULL)
			{
				current_connection = current_connection->Link;
				if (current_connection->position == position)
				{
					connection = current_connection;
					return true;
				}
			}
			return false;
		}
		return false;
	}
	else
	{
		return false;
	}
	
}

int Connector::GetConnections(Node *source)
{
	int count = 0;

	Connection *current_connection = start_connection;
	Connection *new_connection = new Connection;
	Connection *head = new_connection;
	Connection *old_connection;
	new_connection->position = 0;
	new_connection->affinity = 0;
	new_connection->connection_id = 0;
	new_connection->source_id = 0;
	new_connection->target_id = 0;
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
			new_connection->affinity = current_connection->affinity;
			new_connection->connection_id = current_connection->connection_id;
			new_connection->source_id = current_connection->source_id;
			new_connection->target_id = current_connection->target_id;
			new_connection->Source = current_connection->Source;
			new_connection->Target = current_connection->Target;
			new_connection->Link = NULL;
			old_connection->Link = new_connection;

		}
	}
	cout << "Number of connections: " << count << endl;
	//sets a linked list of nodes beginning at the head.
	node_connections = head;

	return count;
}

bool Connector::HasConnections()
{
	if (start_connection->Link != NULL || start_connection->Link != end_connection)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool Connector::FindConnection(unsigned int position, unsigned int connection_id)
{
	Connection *current_connection = start_connection;

	if (HasConnections())
	{
		//Search by Position.
		if (position > 0)
		{
			while (current_connection->Link != NULL || current_connection->Link != end_connection)
			{
				current_connection = current_connection->Link;
				if (current_connection->position == position)
				{
					result_connection = current_connection;
					return true;
				}
			}
			return false;
		}

		//Search by Connection ID.
		if (connection_id > 0)
		{
			while (current_connection->Link != NULL || current_connection->Link != end_connection)
			{
				current_connection = current_connection->Link;
				if (current_connection->connection_id == connection_id)
				{
					result_connection = current_connection;
					return true;
				}
			}
			return false;
		}
		return false;
	}
	else
	{
		return false;
	}
}

bool Connector::SearchConnections(Connection *source, int data)
{
	Connection *p = source;

	cout << " " << endl;
	cout << "Showing connections for: " << endl;
	//cout << "Parent Node: " << p->Source << endl;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			if (p->Target->data == data)
			{
				return true;
			}
			else
			{
				cout << "Nodes does not match!!!!" << endl;
				cout << "Connection: " << p << endl;

				cout << "n-----------------------------n" << endl;
				cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
				cout << "P: " << p->Source->data << "---->" << "C: " << p->Target->data << endl;
				cout << "Node: " << p->Source->data << "---->" << " " << static_cast<char>(p->Target->data) << endl;
				cout << "|| Next Connection: " << p->Link << endl;
				cout << "n*****************************n" << endl;
			}
		}
		p = p->Link;
	}

	return false;
}

void Connector::ShowConnections()
{
	Connection *p = start_connection;
	Connection *q = end_connection;
	int count = 0;

	cout << "Starting Connection: " << start_connection << endl;
	while (p->Link != NULL)
	{
		if (p != q)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
				if (p->Source != NULL)
				{
					cout << "P: " << p->Source->data << "---->" << "C: " << p->Target->data << endl;
					cout << "Node: " << static_cast<char>(p->Source->data) << "---->" << " " << static_cast<char>(p->Target->data) << endl;
				}
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;
			p = p->Link;
			//q = p->next;
			count++;
		}
	}
	cout << "End Connection: n" << end_connection << endl;
}

void Connector::PrintNodeConnections()
{
	Connection *p = node_connections;

	cout << " " << endl;
	cout << "Showing connections for: " << endl;
	//cout << "Parent Node: " << p->Source << endl;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
			cout << "P: " << p->Source->data << "---->" << "C: " << p->Target->data << endl;
			cout << "Node: " << p->Source->data << "---->" << " " << static_cast<char>(p->Target->data) << endl;
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;
		}
		p = p->Link;
	}
}

void Connector::PrintConnections(Connection *pConnections)
{
	Connection *p = pConnections;

	cout << " " << endl;
	cout << "Showing connections for: " << endl;
	//cout << "Parent Node: " << p->Source << endl;

	while (p != NULL)
	{
		if (p->Source != NULL)
		{
			cout << "Connection: " << p << endl;

			cout << "n-----------------------------n" << endl;
			cout << "|| position: " << p->position << " Parent: " << p->Source << " Child: " << p->Target << endl;
			cout << "P: " << p->Source->data << "---->" << "C: " << p->Target->data << endl;
			cout << "Node: " << p->Source->data << "---->" << " " << static_cast<char>(p->Target->data) << endl;
			cout << "|| Next Connection: " << p->Link << endl;
			cout << "n*****************************n" << endl;
		}
		p = p->Link;
	}
}



void Connector::DeleteConnections(Connection *conn)
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


Connector::~Connector()
{
	//Applies to Connections List.
	Connection *pointer = start_connection;
	Connection *e = end_connection;

	while (pointer->Link != NULL)
	{
		e = pointer;
		pointer = pointer->Link;
		delete e;

	}
	delete end_connection;

	DeleteConnections(node_connections);
}