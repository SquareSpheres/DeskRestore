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

#include "winutils.h"

BOOL CALLBACK winutils::EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
	const auto v = reinterpret_cast<std::vector<HWND>*>(lParam);
	const auto textLength = GetWindowTextLengthA(hwnd);

	if (hwnd == GetShellWindow()) return TRUE;
	if (!IsWindowVisible(hwnd)) return TRUE;
	if (textLength == 0) return TRUE;
	v->push_back(hwnd);
	return TRUE;
}


std::string winutils::GetWindowTextAsString(const HWND hwnd)
{
	char title[256];
	if (!GetWindowTextA(hwnd, title, sizeof(title))) {
		std::cout << "error code : " << GetLastError() << std::endl;
		return std::string();
	}

	return std::string(title);
}

std::string winutils::GetWindowClassAsString(const HWND hwnd)
{
	char class_name[256];
	if (!GetClassNameA(hwnd, class_name, sizeof(class_name))) {
		std::cout << "error code : " << GetLastError() << std::endl;
		return std::string();
	}

	return std::string(class_name);
}

std::string winutils::GetLastError()
{
	/**
	 *
	 * CODE COPIED FROM STACK OVERFLOW
	 *
	 * Jamin Grey
	 *
	 * https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror
	 */

	const DWORD errorMessageID = ::GetLastError();
	if (errorMessageID == 0)
		return std::string();

	LPSTR messageBuffer = nullptr;
	const size_t size = FormatMessageA(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
	                             nullptr, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, nullptr);

	std::string message(messageBuffer, size);

	LocalFree(messageBuffer);

	return message;
}


void winutils::GetOpenWindows(std::vector<HWND> * const v)
{
	v->clear();
	EnumWindows(EnumWindowsProc, LPARAM(v));
}


int winutils::GetDesktopWidth()
{
	if (!IsProcessDPIAware()) {
		if (!SetProcessDPIAware()) {
			std::cout << "error code : " << GetLastError() << std::endl;
			return -1;
		}
	}

	return GetSystemMetrics(SM_CXSCREEN);
}


int winutils::GetDesktopHeight()
{

	if (!IsProcessDPIAware()) {
		if (!SetProcessDPIAware()) {
			std::cout << "error code : " << GetLastError() << std::endl;
			return -1;
		}
	}

	return GetSystemMetrics(SM_CYSCREEN);
}


int winutils::GetWindowHeight(const HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return windowRect.bottom - windowRect.top;
}

int winutils::GetWindowWidth(const HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return windowRect.right - windowRect.left;
}

std::pair<int, int> winutils::GetWindowPos(const HWND hwnd)
{
	RECT windowRect;
	GetWindowRect(hwnd, &windowRect);
	return { windowRect.left, windowRect.top };
}

std::unordered_map<HWND, int> winutils::GetOpenWindowsZOrder()
{
	std::unordered_map<HWND, int> orderMap;
	HWND next = GetTopWindow(nullptr);
	int order = 0;

	while (next) {
		orderMap[next] = order++;
		next = GetNextWindow(next, GW_HWNDNEXT);
	}

	return orderMap;
}



