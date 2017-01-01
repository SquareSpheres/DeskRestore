#include "DesktopStateManager.h"
#include "DesktopState.h"
#include "WinWrapper.h"
#include <iostream>





DesktopStateManager::~DesktopStateManager()
{
	delete DesktopStateManager::desktopStates;
	std::cout << "Deleting vector of desktopStates..." << std::endl;
}

void DesktopStateManager::makeSnapshot()
{
	std::vector<HWND> handles;
	std::vector<AppState> appStates;
	WinWrapper::GetOpenWindows(&handles);

	for each (HWND handle in handles)
	{

		std::string appName = WinWrapper::GetWindowTextAsString(handle);
		int appHeight = WinWrapper::GetWindowHeight(handle);
		int appWidth = WinWrapper::GetWindowWidth(handle);
		std::pair<int, int> pos = WinWrapper::GetWindowPos(handle);
		int posZ;




		//appStates.push_back(AppState())

	}
}

void DesktopStateManager::removeSnapshot()
{
}

bool DesktopStateManager::restoreLast()
{
	return false;
}

bool DesktopStateManager::restoreFirst()
{
	return false;
}
