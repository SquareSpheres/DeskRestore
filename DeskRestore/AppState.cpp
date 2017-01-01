#include "AppState.h"
#include <iostream>

AppState::~AppState()
{
	std::cout << "Deleting appstate..." << std::endl;
}

std::string AppState::toString()
{
	std::string name = appName;
	std::string height(" appHeight " + std::to_string(appHeight));
	std::string width(" appWidth " + std::to_string(appWidth));
	std::string posX(" posX " + std::to_string(posX));
	std::string posY(" posY " + std::to_string(posY));
	std::string posZ(" posZ " + std::to_string(posZ));

	return name + height + width + posX + posY + posZ;
}

