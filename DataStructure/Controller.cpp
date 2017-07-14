#include "stdafx.h"
#include <iostream>
#include <string>

#include "Controller.h"

using namespace std;

Controller::Controller()
{

}

void Controller::Input()
{
	string text;
	int ascChar;
	cout << "Please enter a line of text:" << endl;
	getline(cin, text);

	cout << text << endl;

	for (int i = 0; i<text.length(); i++)
	{
		ascChar = text[i];
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

bool CheckConnections(Connection* connection)
{
	return false;
}