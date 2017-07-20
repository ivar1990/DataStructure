#include "stdafx.h"
#include <iostream>
#include <string>

#include "Controller.h"

using namespace std;

Controller::Controller()
{

}

void Controller::Input(int ascChar)
{
	dataset.push_back(ascChar);
}

void Controller::HandleInput()
{

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