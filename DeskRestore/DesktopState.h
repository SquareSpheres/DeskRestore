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
#include "AppState.h"
#include <string>
#include <vector>
#include <chrono>

namespace deskrestore {

	/**
	 * \brief Creates a list of AppStates of currently open and active applications
	 * \return vector of AppStates
	 */
	std::vector<AppState> CreateAppStates();

	/**
	 *
	 * \brief Gets a timestamp as string
	 * \param timeStamp The time stamp
	 * \return String representation of timestamp
	 */
	std::string GetTimeStampAsString(const std::chrono::system_clock::time_point timeStamp);


	/**
	 * \brief DesktopState struct represents a state of the desktop at a specific time. The struct is immutable.
	 */
	struct DesktopState
	{
		DesktopState();

		DesktopState(const DesktopState& desktopState) = default;
		DesktopState& operator =(const DesktopState &other) = delete;

		DesktopState(const DesktopState &&other) = delete;
		DesktopState& operator =(const DesktopState &&other) = delete;

		DesktopState(std::vector<AppState> appStates);
		~DesktopState();

		const std::chrono::system_clock::time_point timeStamp;
		const std::vector<AppState> appStates;

	};
}
