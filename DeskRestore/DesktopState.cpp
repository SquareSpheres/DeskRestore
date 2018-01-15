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


