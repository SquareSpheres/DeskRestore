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

	std::sort(appStates.begin(), appStates.end());

	DesktopState state(appStates);
	desktopStates->push_back(state);

}

void DesktopStateManager::removeSnapshot(int index)
{
	DesktopStateManager::desktopStates->erase(DesktopStateManager::desktopStates->begin() + index);
}


bool DesktopStateManager::restoreLast()
{
	DesktopStateManager::restoreSnapshot(desktopStates->at(desktopStates->size()-1));
	return false;
}

bool DesktopStateManager::restoreFirst()
{
	DesktopStateManager::restoreSnapshot(desktopStates->at(0));
	return false;
}

void DesktopStateManager::printStates()
{
	for (size_t i = 0; i < DesktopStateManager::desktopStates->size(); i++)
	{
		std::cout << "Number of DeskStates = " << DesktopStateManager::desktopStates->size() << std::endl;
		desktopStates->at(i).printState();
	}
}
