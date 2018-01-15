#include "DesktopStateManager.h"
#include "DesktopState.h"
#include "winutils.h"


bool deskrestore::RestoreDesktopState(DesktopState& deskState)
{
	HWND next = HWND_TOPMOST;
	bool operationSuccess = true;

	for (const auto& state : deskState.appStates)
	{
		if (!IsIconic(state.hwnd) && state.isIconic)
		{
			ShowWindow(state.hwnd, SW_SHOWMINIMIZED);
		}
		else if (!state.isIconic)
		{
			ShowWindow(state.hwnd, SW_RESTORE);

			if (SetWindowPos(
				state.hwnd,
				next,
				state.posX,
				state.posY,
				state.appWidth,
				state.appHeight,
				SWP_NOACTIVATE
			))operationSuccess = false;
		}

		next = state.hwnd;
	}

	return operationSuccess;
}

