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

#include "DesktopState.h"
#include <utility>
#include "winutils.h"


std::vector<deskrestore::AppState> deskrestore::CreateAppStates()
{
	std::vector<deskrestore::AppState> appStates;
	std::vector<HWND> handles;
	std::unordered_map<HWND, int> zOrderHandles = winutils::GetOpenWindowsZOrder();
	winutils::GetOpenWindows(&handles);


	for (auto hwnd : handles)
	{
		const auto isIconic = IsIconic(hwnd);
		const auto appName = winutils::GetWindowTextAsString(hwnd);
		const auto appHeight = winutils::GetWindowHeight(hwnd);
		const auto appWidth = winutils::GetWindowWidth(hwnd);

		const auto appPos = winutils::GetWindowPos(hwnd);

		const auto posX = appPos.first;
		const auto posY = appPos.second;
		const auto posZ = zOrderHandles[hwnd];

		const AppState appState(hwnd, isIconic, appName, appWidth, appHeight, posX, posY, posZ);

		appStates.push_back(appState);
	}

	return appStates;
}

std::string deskrestore::GetTimeStampAsString(const std::chrono::system_clock::time_point timeStamp)
{
	auto tt = std::chrono::system_clock::to_time_t(timeStamp);
	char str[26];
	ctime_s(str, sizeof str, &tt);
	return std::string(str);
}

deskrestore::DesktopState::DesktopState() : timeStamp(std::chrono::system_clock::now()), appStates(CreateAppStates()) {}

deskrestore::DesktopState::DesktopState(std::vector<AppState> appStates) : timeStamp(std::chrono::system_clock::now()), appStates(std::move(appStates)) {}

deskrestore::DesktopState::~DesktopState() = default;


