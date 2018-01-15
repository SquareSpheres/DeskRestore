#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

namespace winutils
{

	BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
	std::string GetWindowTextAsString(HWND hwnd);
	std::string GetWindowClassAsString(HWND hwnd);
	std::string GetLastError();
	int GetDesktopWidth();
	int GetDesktopHeight();
	int GetWindowHeight(HWND hwnd);
	int GetWindowWidth(HWND hwnd);
	std::pair<int,int> GetWindowPos(HWND hwnd);
	std::unordered_map<HWND, int> GetOpenWindowsZOrder();
	void GetOpenWindows(std::vector<HWND> * const v);

}