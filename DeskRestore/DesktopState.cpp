#include "DesktopState.h"
#include <iostream>






DesktopState::~DesktopState()
{
	delete DesktopState::appStates;
	std::cout << "Deleting vector of appStates..." << std::endl;
}

std::string DesktopState::toString()
{
	std::string desktopStateString;
	for (int i = 0; i < DesktopState::appStates->size(); i++)
	{
		desktopStateString += (DesktopState::appStates->at(i).toString() +"\n");
	}
	return desktopStateString;
}


