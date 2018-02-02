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

class Abstractor
{
public:

	

	
	
	Storage *storage;
	Assembler *assembler;
	TextDiagram textdiagram;

	Node *pParentNode;
	Node *pCurrentNode;

	Abstractor();

	void SetStorage(Storage *pStorage);

	//Creates A Map of nodes in an Object
	//Describes How They Are related
	//Node creation process
	Node* CreateNode();
	void CreateRandomNodeConnection(Node *pNode);

	void CreateRandomNodeConnections(Node *pNode, int max_size = 0);
	
	void MakeParentNode();


	

private:
	void Init();
};

#endif