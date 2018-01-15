#pragma once
#include "DesktopState.h"

namespace deskrestore
{

	/**
	 * \brief Restore desktop to a given DesktopState
	 * \param deskState Desktop state to restore
	 * \note use GetLastError to check last error
	 * \return true if state was successfully restored, false otherwise
	 */
	bool RestoreDesktopState(DesktopState &deskState);

}