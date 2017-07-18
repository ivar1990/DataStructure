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
	int new_structure_id = GenerateStructureID();

	pStructure->structure_id = new_structure_id;

	storage.insert(pair<int, Structure*>(new_structure_id, pStructure));

	map<int, Structure*>::iterator it;

	it = storage.find(new_structure_id);
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
		delete it->second;
		num_of_structures--;

		return true;
	}
	else {
		return false;
	}
}

void Storage::PrintAllStructures()
{

	for (std::map<int, Structure*>::iterator it = storage.begin(); it != storage.end(); it++)
	{
		std::cout << it->first << " => " << it->second->structure_id << endl;
		it->second->nodes->printList();
		/*if (it->first < 256)
		{			
				it->second->nodes->printList();
				it->second->connections->ShowConnections();
		}
		else
		{
			PrintInnerStructure(it->second);
		}*/
	
		//PrintInnerStructure(it->second);
	}
}

void Storage::PrintInnerStructure(Structure* pStructure)
{
	if (pStructure->structure_id > 256)
	{
		pStructure = GetStructure(pStructure->structure_id);
		PrintInnerStructure(pStructure);
	}
	else
	{
		pStructure->nodes->printList();
		pStructure->connections->ShowConnections();
	}
}

bool Storage::RemoveAllReferenceToStructure()
{
	return true;
}

Storage::~Storage()
{
	if (!storage.empty())
	{
		for (std::map<int, Structure*>::iterator it = storage.begin(); it != storage.end(); it++)
			delete it->second;
	}
}