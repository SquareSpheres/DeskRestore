#pragma once
#include "DesktopState.h"
class DesktopStateManager
{


private:
	std::vector<DesktopState> * const desktopStates;
	bool restoreSnapshot(DesktopState & snapshoot);

public:
	DesktopStateManager() :
		desktopStates(new std::vector<DesktopState>()) {}

	~DesktopStateManager();

	void makeSnapshot();
	void removeSnapshot(int index);
	bool restoreLast();
	bool restoreFirst();

	void printStates();


};

