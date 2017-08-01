#include "stdafx.h"
#include <iostream>
#include <string>

#include "Controller.h"

using namespace std;

Controller::Controller()
{

}

void Controller::SetAbstractor(Abstractor* abstractor)
{
	pAbstractor = abstractor;
}

void Controller::HandleInput(string text)
{
	int ascChar;
	for (int i = 0; i<text.length(); i++)
	{
		ascChar = text[i];
		pAbstractor->Input(ascChar);
		dataset.push_back(ascChar);
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

//bool CheckConnections(Connection *connection)
//{
//	return false;
//}

void Controller::LogStream(string text)
{
	int ascChar;
	list<int> stream;

	for (int i = 0; i<text.length(); i++)
	{
		ascChar = text[i];
		stream.push_back(ascChar);
	}
	int j = inputstream.size() + 1;
	inputstream.insert(pair<int, list<int>>(j, stream));
}

void Controller::OutputStream()
{
	cout << "Input Stream Table: " << endl;
	map<int, list<int>>::iterator it;
	list<int>::iterator l_it;
	int i = 0;

	for (it = inputstream.begin(); it != inputstream.end(); it++)
	{
		cout << endl;
		cout << "Inputs Stream No. " << i << endl;
		i++;
		for (l_it = it->second.begin(); l_it != it->second.end(); l_it++)
		{

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
	}
}