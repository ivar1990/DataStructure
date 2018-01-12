#ifndef Abstractor_h
#define Abstractor_h

#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  /* time */
#include <map>
#include <list>
#include <algorithm>

#include "NodeSystem.h"
#include "Connector.h"
#include "Diagram.h"


using namespace std;

class Abstractor
{
public:

	map<int, int> frequency_table;
	map<int, int> accepted_frequency;
	map<int, list<int>> inputs;

	//Changes generated by addition or removeal of random nodes 
	map<int, list<int>> modifications;
	//Child connection nodes of Parent
	list<int> changes;
	//tracks the response after each modification
	map<int, int> feedback;

	list<int> dataset;
	
	NodeSystem *node_system;
	Connector *connections;

	TextDiagram textdiagram;

	int size = 0;

	Abstractor();

	Abstractor(NodeSystem *pNodeSystem);

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

	/*   
	*Abstraction of trial and error method
	*Create a new node.
	*Create random connections.
	*Get Feedback on correctness of the random generated connection nodes(guess).
	*Compare previous node connections
	*modify guess by add or remove nodes.
	*Get feedback on nodes
	*retry until solution is reached.
	*/

	Node *test_node = NULL;
	//use to compare modification
	//with previous modifications
	list<int> current_modification;

	list<int> consolidated_modification;

	list<int> unwanted_items;

	//Node creation process
	Node* CreateNode();
	void CreateRandomNodeConnection(Node *pNode);

	void CreateRandomNodeConnections(Node *pNode, int max_size = 0);
	

	//Feedback and update
	int GetFeedBack();

	void ModifyTestNode(int hint = 0, int  position = 0);

	void LogChanges(int responses, int affinity);

	void OutputModifications();

	void OutputFeedback();

	int GetModifiedNodeID(int modification_id);

	int CompareFeedBack(int feedback);

	int GenerateHint(int feedback);

	int GetPreviousAction(int modification_id);

	void UpdateChanges();

	void ClearChanges();

	void GenerateModifiedConnections();

	void ConsolidateBestModification();

	void Run();


private:
	void GenerateFrequencyTable();
};

#endif