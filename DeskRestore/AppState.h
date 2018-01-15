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

#pragma once
#include <string>
#include <utility>
#include <Windows.h>


namespace deskrestore
{

	/**
	 * \brief AppState struct represents a state of an application. The struct is immutable.
	 */
	struct AppState
	{
		AppState(HWND handle, bool isIconic, std::string name, const int width, const int height, const int positionX, const int positionY,
			const int zOrder);

		AppState(const AppState &other) = default;
		AppState& operator =(const AppState &other) = delete;

		AppState(const AppState &&other) = delete;
		AppState& operator =(const AppState &&other) = delete;

		~AppState();


		bool operator <(const AppState& other) const;

		bool operator >(const AppState& other) const;

		bool operator ==(const AppState& other) const;

		friend std::ostream& operator<<(std::ostream& os, const AppState& appState);

		const HWND hwnd;
		const bool isIconic;
		const	std::string appName;
		const	int appHeight;
		const	int appWidth;
		const	int posX;
		const	int posY;
		const	int posZ;
	};
}

