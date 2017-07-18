#ifndef Controller_h
#define Controller_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

#include "Storage.h"

using namespace std;


class Controller
{

public:
	Storage storage;
	Assembler assembler;

	Controller();

	void HandleInput(list<int> dataset);
	bool GetFeedback(bool response);



private:
	void Init();
	bool CheckConnections(Connection* connection);
};

#endif