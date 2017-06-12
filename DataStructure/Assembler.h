#ifndef Assembler_h
#define Assembler_h

#include <iostream>
#include <string>

#include "Structure.h"


using namespace std;

class Assembler
{
public:

	//List of int nodes from 1-255(reference to the ascii table).
	NodeSystem default_node_system;

	//References User supplied data(User list of int nodes)
	NodeSystem *pNodeSystem;

	//Data that the assembler will use 
	//To construct Structures
	//User Supplied list of int nodes.
	Assembler(NodeSystem *pComponents);

	//Uses default Data(numbers 1-255 of the ascii table)
	//To construct Structures
	Assembler();

	//Adds Data(numbers 1-255 of the ascii table) to the node_system
	void LoadAsciiTable();

	void GenerateRandomNodes(Structure *structure);

	void GenerateRandomConnections(Structure *structure);

	void OutputStructure(Structure *structure);
};

#endif