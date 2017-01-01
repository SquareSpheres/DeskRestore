#pragma once
#include "DesktopState.h"
class DesktopStateManager
{


private:
	std::vector<DesktopState> * const desktopStates;

public:
	DesktopStateManager() :
		desktopStates(new std::vector<DesktopState>()) {}

	~DesktopStateManager();

	void makeSnapshot();
	void removeSnapshot();
	bool restoreLast();
	bool restoreFirst();


};

