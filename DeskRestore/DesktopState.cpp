#include "DesktopState.h"



DesktopState::~DesktopState()
{

}

void DesktopState::printState()
{


	std::cout << "============STATE START===============" << std::endl;
	for (size_t i = 0; i < DesktopState::deskState.size(); i++)
	{
		AppState tmp(DesktopState::deskState[i]);
		std::cout << tmp.toString() << std::endl;
	}
	std::cout << "============STATE END=================" << std::endl;
}


