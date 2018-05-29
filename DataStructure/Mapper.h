#ifndef Abstractor_h
#define Abstractor_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>
#include <algorithm>

#include "Storage.h"
#include "Assembler.h"
#include "Diagram.h"


using namespace std;

class Mapper
{
public:
	
	Storage *storage;
	Assembler *assembler;
	TextDiagram textdiagram;

	Node *pParentNode;
	Node *pCurrentNode = NULL;
	Node *pResultNode = NULL;

	list<Node> generated_nodes;

	Mapper();

	void SetStorage(Storage *pStorage);

	void SetAssembler(Assembler *pAssembler);

	//Creates A Map of nodes in an Object
	//Describes How They Are related
	//Node creation process
	Node* CreateNode();
	void CreateRandomNodeConnection(Node *pNode);

	void CreateRandomNodeConnections(Node *pNode, int max_size = 0);
	
	void MakeNode();

	// Checks if there is a loop 
	// In a Connected Node list;
	bool IsCircular(Node *pStart);

	bool CheckChildIsParent(Node *pParentNode);

	void DisplayAllNodeConnections(Node *pParentNode);
	//Number returned is useless
	//Sets pResultNode
	int Iterate(Node *pParentNode, int stop_node_id = 0);
	
	bool AttachNode(Node *pTarget);



	/***************************************/

	Connection *current_node_connections;


	void GetNode(Node* pInputNodes);
	Connection* MapNode(Node* pNode);



	/**************************************/
private:
	void Init();
};

/*
enter a number: 5
search for number: 5
if 5 is found 
print connection steps
else
create a node 
create connections
test for result
*/

#endif