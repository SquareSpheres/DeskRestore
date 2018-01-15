#include <iostream>
#include <string>
#include <iostream>
#include "DesktopStateManager.h"
#include <unordered_map>


int main(int argc, char *argv[]) {


	using namespace deskrestore;

	int input = 1;
	DesktopState * desktop = nullptr;

	while(input!=0)
	{
		std::cin >> input;

		switch (input)
		{
		case 1:
			delete desktop;
			desktop = new DesktopState;
			break;
		case 2:
			RestoreDesktopState(*desktop);
			break;
		default:
			break;
		}
	}
}



