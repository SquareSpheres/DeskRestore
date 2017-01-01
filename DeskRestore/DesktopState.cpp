#include "DesktopState.h"
#include <iostream>


DesktopState::~DesktopState()
{
	delete DesktopState::appStates;
	std::cout << "Deleting vector of appStates..." << std::endl;
}


