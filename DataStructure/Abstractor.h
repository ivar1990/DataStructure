#ifndef Abstractor_h
#define Abstractor_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

#include "Controller.h"

class Abstractor
{
public:
	map<int, int> frequency_table;
	list<int> dataset;
	Controller controller;

	Abstractor();
	void Input();
	bool GetFeedback(bool response);

	void GenerateRandomDataSet(int max_size = 0);

	void OutputFrequencyTable();

private:
	void GenerateFrequencyTable();
};

#endif