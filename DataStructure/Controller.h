#ifndef Controller_h
#define Controller_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

#include "Storage.h"
#include "Assembler.h"
#include "Abstractor.h"

using namespace std;


class Controller
{

public:
	Storage storage;
	//Assembler assembler;
	//Abstractor abstractor;

	//For handling inputs
	list<int> dataset;

	Controller();

	void Input(int ascChar);
	void HandleInput();
	bool GetFeedback(bool response);



private:
	void Init();
	bool CheckConnections(Connection* connection);
};

#endif