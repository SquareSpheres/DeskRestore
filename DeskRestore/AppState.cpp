/*
* This is free and unencumbered software released into the public domain.
*
* Anyone is free to copy, modify, publish, use, compile, sell, or
* distribute this software, either in source code form or as a compiled
* binary, for any purpose, commercial or non-commercial, and by any
* means.
*
* In jurisdictions that recognize copyright laws, the author or authors
* of this software dedicate any and all copyright interest in the
* software to the public domain.We make this dedication for the benefit
* of the public at large and to the detriment of our heirs and
* successors.We intend this dedication to be an overt act of
* relinquishment in perpetuity of all present and future rights to this
* software under copyright law.
*
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* For more information, please refer to<http://unlicense.org>
*/

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
