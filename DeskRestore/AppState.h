#pragma once
#include <string>
#include <Windows.h>

class AppState
{

public:
	AppState(HWND handle,std::string name, int width, int height, int position_x, int position_y, int z_order)
		:hwnd(handle),appName(name), appHeight(height), appWidth(width), posX(position_x), posY(position_y), posZ(z_order) {}

	~AppState();

	bool operator < (const AppState &other) const {
		return posZ < other.posZ;
	}

	bool operator = (const AppState &other) const {
		return posZ == other.posZ;
	}



	std::string toString();

	const HWND hwnd;
	const	std::string appName;
	const	int appHeight;
	const	int appWidth;
	const	int posX;
	const	int posY;
	const	int posZ;
};



