#pragma once
#include "AppState.h"
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>


class DesktopState
{

public:

	const std::vector<AppState> appStates;

	DesktopState(const std::vector<AppState> & appStates) :
		appStates(appStates) {}


	// WHY DO I NEED THIS??
	bool operator = (const DesktopState & otherState) const {
		return 0;
	}

	~DesktopState();

	void printState();

};

