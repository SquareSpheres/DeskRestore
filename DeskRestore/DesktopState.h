#pragma once
#include "AppState.h"
#include <string>
#include <vector>
#include <algorithm>
#include <queue>


class DesktopState
{

public:

	std::vector<AppState> * appStates;


	DesktopState(std::vector<AppState> * states) :
		appStates(new std::vector<AppState>(*states)) {

		std::sort(appStates->begin(), appStates->end());
	}

	DesktopState(std::vector<AppState> & states) :
		appStates(new std::vector<AppState>(states)) {

		std::sort(appStates->begin(), appStates->end());
	}

	
	~DesktopState();



	std::string toString();

	
};

