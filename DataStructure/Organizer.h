#ifndef Organizer_h
#define Organizer_h

#include <iostream>
#include <string>

#include "LinkedList.h"

using namespace std;


class Organizer
{

	

public:
	unsigned int search_speed;
	unsigned int max_range;
	int minimum_range = 0;

	LinkedList<int> memory_space;

	Organizer();

	bool MoveNodeToPriority();
	bool MoveConnectionToPriority();

	bool GetNodeDistance();
	bool GetConnectionDistance();


	~Organizer();
};
#endif

Organizer::Organizer()
{

}

bool Organizer::MoveNodeToPriority()
{
	
	return false;
}

bool Organizer::MoveConnectionToPriority()
{
	return false;
}


Organizer::~Organizer()
{

}