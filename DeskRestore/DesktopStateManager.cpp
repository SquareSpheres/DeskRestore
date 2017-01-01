#include "DesktopStateManager.h"
#include "DesktopState.h"
#include "WinWrapper.h"
#include <iostream>





bool DesktopStateManager::restoreSnapshot(DesktopState & snapshoot)
{
	return false;
}



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

	std::unordered_map<HWND, int> order;
	order = WinWrapper::GetOpenWindowsZOrder();




	for (HWND handle : handles)
	{

		std::string appName = WinWrapper::GetWindowTextAsString(handle);
		int appHeight = WinWrapper::GetWindowHeight(handle);
		int appWidth = WinWrapper::GetWindowWidth(handle);
		std::pair<int, int> pos = WinWrapper::GetWindowPos(handle);
		int posZ = INT_MAX;

		if (order.find(handle) != order.end()) {
			posZ = order[handle];
		}

		appStates.push_back(AppState(handle, appName, appWidth, appHeight, pos.first, pos.second, posZ));
	}



	// working fine untill here
	//creting of vector goes wrong??
	desktopStates->push_back(DesktopState(appStates));
}

void DesktopStateManager::removeSnapshot(int index)
{
	DesktopStateManager::desktopStates->erase(DesktopStateManager::desktopStates->begin() + index);
}


bool DesktopStateManager::restoreLast()
{
	return false;
}

bool DesktopStateManager::restoreFirst()
{
	return false;
}

void DesktopStateManager::printStates()
{
	for (int i = 0; i < DesktopStateManager::desktopStates->size(); i++)
	{
		std::cout << DesktopStateManager::desktopStates->size();
		std::cout << DesktopStateManager::desktopStates->at(i).toString() << std::endl;
	}
}
