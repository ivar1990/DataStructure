#ifndef Storage_h
#define Storage_h

#include <iostream>
#include <string>
#include <map>

#include "Structure.h"
#include "Assembler.h"

using namespace std;

class Storage
{

public:

	Storage();

	
	
	int GetStructureCount();

	
	//increments the structure_id
	//returns the new structure_id
	//new structure id can be added or removed
	int GenerateStructureID();

	//returns a stored structure
	Structure* GetStructure(int structure_id);

	bool AddStructure(Structure *pStructure);

	bool RemoveStructure(int structure_id);

	~Storage();

private:

	//Container for structures
	map<int, Structure*> storage;

	//Total amount of structures
	int num_of_structures = 0;

	void Init();

	bool RemoveAllReferenceToStructure();

};

#endif