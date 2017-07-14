#ifndef Controller_h
#define Controller_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>

#include "Storage.h"


class Controller
{

public:
	map<int, int> frequency_table;
	Storage storage;

	Controller();
	void Input();
	bool GetFeedback(bool response);



private:
	void Init();
	bool CheckConnections(Connection* connection);
};

#endif