#ifndef Structure_h
#define Structure_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "LinkedList.h"
#include "NodeSystem.h"
#include "Connector.h"

using namespace std;

class Structure
{
public:

	unsigned int structure_id =0;

	NodeSystem *nodes;
	Connector *connections;
	NodeSystem *instructions;

	Structure();


	

	void Add(int data);

	

	void LinkData();

	//void RandomLink(int data);

	//////void OutputConstruct(int data);

	//void Input(string character);

	

	void PrintNodes();


	~Structure();
};



#endif

