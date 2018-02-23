#include "stdafx.h"
#include <iostream>
#include <Windows.h>

#include <string>

#include "Controller.h"

using namespace std;

Controller::Controller()
{

}

void Controller::SetStorage(Storage* storage)
{
	this->pStorage = storage;
}

void Controller::SetAssembler(Assembler* assembler)
{
	this->pAssembler = assembler;
}

void Controller::SetMapper(Mapper* mapper)
{
	this->pMapper = mapper;
}

void Controller::SetDevice(Device *device)
{
	this->pDevice = device;
}

void Controller::HandleInput(string text)
{
	//Gets numerical value of ascii character
	int ascChar;
	for (int i = 0; i<text.length(); i++)
	{
		//Convert Character to number
		ascChar = text[i];
		//Add number to Abstractor Node System
		//pAbstractor->Input(ascChar);
		//Add to container
		dataset.push_back(ascChar);
		//Output the number and character representation to the console
		cout << ascChar << ": " << static_cast<char>(ascChar) << endl;
	}
}

bool Controller::GetFeedback(bool response)
{
	return false;
}

void Controller::Init()
{

}

void Controller::InitDefaultDevice()
{

}



void Controller::LogStream(string text)
{
	//Gets numerical value of ascii character
	int ascChar;
	//Container to hold each character numerical value
	list<int> stream;

	for (int i = 0; i<text.length(); i++)
	{
		//Convert Character to number
		ascChar = text[i];
		//Add character to container
		stream.push_back(ascChar);
	}
	//Generate new ID for this keyboard input
	int j = inputstream.size() + 1;
	//Add new entry to Input history. 
	inputstream.insert(pair<int, list<int>>(j, stream));
}

void Controller::OutputStream()
{
	//inputstream is the map<int, list<int>> container

	cout << "Input Stream Table: " << endl;

	//Pointer to traverse map container
	map<int, list<int>>::iterator it;
	//Pointer to traverse list container
	list<int>::iterator l_it;
	//Track the number of inputs in input history
	int i = 0;

	///Traverse the Map<int, list<int> container
	for (it = inputstream.begin(); it != inputstream.end(); it++)
	{
		cout << endl;
		cout << "Inputs Stream No. " << i << endl;
		i++;

		///Traverse the list<int> container
		//it->second indicated the position of the List<int>
		for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			//*l_it is a pointer to the List<int> that is stored
			cout << static_cast<char>(*l_it);
			
		}

		cout << endl;
	}
}

void Controller::LogHistory()
{
	int i = history.size() + 1;
	history.insert(pair<int, list<int>>(i, dataset));
}

void Controller::ShowHistory()
{
	cout << "History Table: " << endl;
	map<int, list<int>>::iterator it;
	list<int>::iterator l_it;
	int i = 0;

	for (it = history.begin(); it != history.end(); it++)
	{
		cout << endl;
		cout << "History No. " << i << endl;
		i++;
		for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{
			cout << static_cast<char>(*l_it);
			
		}
		cout << endl;
	}
}

void Controller::Close()
{
	
	pStorage->WriteToDisk();
	//pStorage->PrintStorage();
}