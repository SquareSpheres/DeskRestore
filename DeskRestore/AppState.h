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

