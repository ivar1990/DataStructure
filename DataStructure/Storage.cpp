#include "stdafx.h"
#include <iostream>
#include <string>

#include "Storage.h"

using namespace std;

Storage::Storage()
{

}

void Storage::Init()
{
	
}

int Storage::GetStructureCount()
{
	return num_of_structures;
}

int Storage::GenerateStructureID()
{
	//tracks Structures
	static unsigned int structure_id = 0;
	return structure_id++;
}

Structure* Storage::GetStructure(int structure_id)
{
	map<int, Structure*>::iterator it;

	it = storage.find(structure_id);
	if (it != storage.end())
	{
		return it->second;
	}
	else {
		return NULL;
	}
}

bool Storage::AddStructure(Structure *pStructure)
{
	int new_structure = GenerateStructureID();
	storage.insert(pair<int, Structure*>(new_structure, pStructure));

	map<int, Structure*>::iterator it;

	it = storage.find(new_structure);
	if (it != storage.end())
	{
		num_of_structures++;
		return true;
	}
	else {
		return false;
	}
}

bool Storage::RemoveStructure(int structure_id)
{

	storage.erase(structure_id);
	map<int, Structure*>::iterator it;

	it = storage.find(structure_id);
	if (it == storage.end())
	{
		num_of_structures--;
		return true;
	}
	else {
		return false;
	}
}

bool Storage::RemoveAllReferenceToStructure()
{
	return true;
}