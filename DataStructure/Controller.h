#ifndef Controller_h
#define Controller_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

#include "Mapper.h"
#include "Storage.h"
#include "Assembler.h"

using namespace std;

class Controller
{
public:

	Storage *pStorage;
	Assembler *pAssembler;
	Mapper *pMapper;

	map<int, list<int>> inputstream;
	map<int, list<int>> history;

	//For handling inputs
	list<int> dataset;

	Controller();

	void HandleInput(string text);
	bool GetFeedback(bool response);

	void SetStorage(Storage *storage);
	void SetAssembler(Assembler *assembler);
	void SetAbstractor(Mapper *mapper);

	void LogStream(string text);
	void OutputStream();

	void LogHistory();
	void ShowHistory();

	void Close();


private:
	void Init();
	//bool CheckConnections(Connection *connection);
};

#endif