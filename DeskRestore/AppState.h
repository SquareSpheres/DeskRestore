#pragma once
#include <string>

class AppState
{

public:
	AppState(std::string name, int width, int height, int position_x, int position_y, int z_order)
		:appName(name), appHeight(height), appWidth(width), posX(position_x), posY(position_y), posZ(z_order) {}

	~AppState();

	const	std::string appName;
	const	int appHeight;
	const	int appWidth;
	const	int posX;
	const	int posY;
	const	int posZ;
};



