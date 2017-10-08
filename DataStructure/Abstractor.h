#ifndef Abstractor_h
#define Abstractor_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>

#include "NodeSystem.h"
#include "Connector.h"


using namespace std;

class Abstractor
{
public:

	map<int, int> frequency_table;
	map<int, int> accepted_frequency;
	map<int, list<int>> inputs;
	map<int, list<int>> patterns;
	list<int> current_pattern;

	list<int> dataset;
	
	NodeSystem *node_system;
	Connector *connections;

	int size = 0;

	Abstractor();

	void Input(int ascChar);

	void GetFeedback();

	void GenerateRandomDataSet(int max_size = 0);

	void GenerateRandomNodes(int max_size = 0);

	void GenerateRandomConnections(int max_size = 0);

	void OutputFrequencyTable();

	void SeparateByFrequency(int frequency_count);

	void Output();

	void LogInputs();

	void OutputInputs();

	bool IsChanged();

	//Node creation process
	Node* CreateNode();
	void CreateRandomNodeConnections(Node *pNode, int max_size = 0);
	

private:
	void GenerateFrequencyTable();
};

#endif