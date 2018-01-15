#include "AppState.h"

deskrestore::AppState::AppState(const HWND handle, const bool isIconic, std::string name, const int width, const int height, const int positionX,
	const int positionY, const int zOrder) : hwnd(handle), isIconic(isIconic), appName(std::move(name)), appHeight(height),
	appWidth(width), posX(positionX), posY(positionY), posZ(zOrder) {}


deskrestore::AppState::~AppState() = default;

bool deskrestore::AppState::operator<(const AppState& other) const
{
	return posZ < other.posZ;
}

bool deskrestore::AppState::operator>(const AppState& other) const
{
	return posZ > other.posZ;
}

bool deskrestore::AppState::operator==(const AppState& other) const
{
	return
		((hwnd == other.hwnd) &&
		(isIconic == other.isIconic) &&
			(appName == other.appName) &&
			(appHeight == other.appHeight) &&
			(appWidth == other.appWidth) &&
			(posX == other.posX) &&
			(posY == other.posY) &&
			(posZ == other.posZ));
}

std::ostream & deskrestore::operator<<(std::ostream & os, const AppState & appState)
{
	return os << "Handle : " << appState.hwnd << " Iconic : " << appState.isIconic << " AppName : " << appState.appName << "  AppHeight : " << appState.appHeight << " AppWidth : " <<
		appState.appWidth << " AppPosX : " << appState.posX << "  AppPosY : " << appState.posY << " Z-order : " << appState.posZ;
}
