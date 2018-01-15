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
