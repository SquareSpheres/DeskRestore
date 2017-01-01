#include "AppStateManager.h"



AppStateManager::AppStateManager()
{
	AppStateManager::appStates = new std::vector<AppState>();
}


AppStateManager::~AppStateManager()
{
	delete AppStateManager::appStates;
}
