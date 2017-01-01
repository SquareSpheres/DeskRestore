#pragma once
#include "AppState.h"
#include <string>
#include <vector>

class DesktopState
{

private:
	const std::vector<AppState> * const appStates;

public:
	DesktopState(std::vector<AppState> * states) :
		appStates(new std::vector<AppState>(*states)) {}

	DesktopState(std::vector<AppState> states) :
		appStates(new std::vector<AppState>(states)) {}

	DesktopState(std::vector<AppState> & states) :
		appStates(new std::vector<AppState>(states)) {}


	~DesktopState();
};

