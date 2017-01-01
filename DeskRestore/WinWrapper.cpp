#include "WinWrapper.h"

BOOL CALLBACK WinWrapper::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{

	std::vector<HWND> * const v = (std::vector<HWND>*)lParam;
	int textLength = GetWindowTextLengthA(hwnd);

	if (hwnd == GetShellWindow()) return TRUE;
	if (!IsWindowVisible(hwnd)) return TRUE;
	if (textLength == 0) return TRUE;
	v->push_back(hwnd);
	return TRUE;

}


std::string WinWrapper::GetWindowTextAsString(HWND hwnd)
{
	char title[256];
	if (!GetWindowTextA(hwnd, title, sizeof(title))) {
		std::cout << "error code : " << GetLastError() << std::endl;
		return std::string();
	}

	return std::string(title);
}

std::string WinWrapper::GetWindowClassAsString(HWND hwnd)
{
	char class_name[256];
	if (!GetClassNameA(hwnd, class_name, sizeof(class_name))) {
		std::cout << "error code : " << GetLastError() << std::endl;
		return std::string();
	}

	return std::string(class_name);
}


void WinWrapper::GetOpenWindows(std::vector<HWND> * const v)
{
	v->clear();
	EnumWindows(EnumWindowsProc, LPARAM(v));
}


int WinWrapper::GetDesktopWidth()
{
	if (!IsProcessDPIAware()) {
		if (!SetProcessDPIAware()) {
			std::cout << "error code : " << GetLastError() << std::endl;
			return -1;
		}
	}

	return GetSystemMetrics(SM_CXSCREEN);
}


int WinWrapper::GetDesktopHeight()
{

	if (!IsProcessDPIAware()) {
		if (!SetProcessDPIAware()) {
			std::cout << "error code : " << GetLastError() << std::endl;
			return -1;
		}
	}

	return GetSystemMetrics(SM_CYSCREEN);
}


//TODO fix
int WinWrapper::GetWindowHeight(HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return windowRect.bottom - windowRect.top;
}

//TODO fix
int WinWrapper::GetWindowWidth(HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return windowRect.right - windowRect.left;
}


//TODO fix
std::pair<int, int> WinWrapper::GetWindowPos(HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return std::pair<int, int>(windowRect.left, windowRect.top);
}

//TODO fix
std::unordered_map<HWND, int> WinWrapper::GetOpenWindowsZOrder()
{
	std::unordered_map<HWND, int> orderMAP;

	HWND next = GetTopWindow(NULL);
	int order = 0;

	while (next) {
		if (next != GetShellWindow() && IsWindowVisible(next) && GetWindowTextLengthA(next) > 0) {
			orderMAP[next] = order;
			order++;
		}
		next = GetNextWindow(next, GW_HWNDNEXT);
	}

	return orderMAP;
}



