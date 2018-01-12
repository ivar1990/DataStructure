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
	cout << "Node: " << pNode->data << endl;
}

void TextDiagram::DisplayConnection(Connection *pConnection)
{
	cout << "		------->" << pConnection->Target->data << endl;
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