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
	map<int, int> accepted_frequency;
	map<int, list<int>> inputs;

	list<int> dataset;

	int size = 0;

	Abstractor();

	void Input(int ascChar);

	void GetFeedback();

	void GenerateRandomDataSet(int max_size = 0);

	void OutputFrequencyTable();

	void SeparateByFrequency(int frequency_count);

	void Output();

	void LogInputs();

	void OutputInputs();

	bool IsChanged();

private:
	void GenerateFrequencyTable();
};

#endif