#ifndef DIAGRAM_h
#define DIAGRAM_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>
#include <algorithm>

#include "NodeSystem.h"
#include "Connector.h"


using namespace std;

class Diagram
{
public:
	void SetType(string display_type)
	{
		display_type = display_type;
	}

	void SetNodeSystem(NodeSystem *pNodeSystem)
	{
		node_system = pNodeSystem;
	}

	void SetConnections(Connector *connections)
	{
		connections = connections;
	}

protected:
	string display_type;

	NodeSystem *node_system;
	Connector *connections;

};

class TextDiagram : public Diagram
{
public:
	TextDiagram();

	

	void DisplayNode(Node *pNode);

	void DisplayConnection(Connection *pConnection);

	bool IsPrintable();

	void Print();

	void PrintNode(Node *pNode);

private:

	void Init();

};

#endif