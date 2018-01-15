#include "stdafx.h"
#include "Diagram.h"

using namespace std;

TextDiagram::TextDiagram()
{
	Init();
}

void TextDiagram::Init()
{
	SetType("text");

}

void TextDiagram::DisplayNode(Node *pNode)
{
	cout << endl;
	cout << "Node: " << pNode->data << endl;
}

void TextDiagram::DisplayConnection(Connection *pConnection)
{
	cout << "	------->" << pConnection->Target->data << endl;
}

bool TextDiagram::IsPrintable()
{
	if (node_system != NULL && connections != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void TextDiagram::Print()
{
	if (IsPrintable())
	{
		//needs to finish
		//print all nodes and connection in
		//treelist text format

		//Set Node to beginning of Node System nodes
		node_system->FindNode(0, 1, 0);

		Node *p = node_system->search_node;

		while (p->next != NULL)
		{
			if (p != NULL)
			{
				PrintNode(p);
				p = p->next;
			}
		}

	}
	else
	{
		cout << "Nothing to Print." << endl;
	}
}

void TextDiagram::PrintNode(Node *pNode)
{
	if (IsPrintable())
	{
		DisplayNode(pNode);
		connections->GetConnections(pNode);

		Connection *p = connections->node_connections;

		while (p != NULL)
		{
			if (p->Source != NULL)
			{
				DisplayConnection(p);
			}
			p = p->Link;
		}
	}
	else
	{
		cout << "Nothing to Print." << endl;
	}
}