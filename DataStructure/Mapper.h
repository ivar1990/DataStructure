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
	Node *pCurrentNode;

	Mapper();

	void SetStorage(Storage *pStorage);

	//Creates A Map of nodes in an Object
	//Describes How They Are related
	//Node creation process
	Node* CreateNode();
	void CreateRandomNodeConnection(Node *pNode);

	void CreateRandomNodeConnections(Node *pNode, int max_size = 0);
	
	void MakeNode();

	void 
	

private:
	void Init();
};

#endif