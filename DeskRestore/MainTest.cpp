#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include "DesktopStateManager.h"



void foo(std::string * strings, int length) {
	for (int i = 0; i < length; i++)
	{
		std::cout << strings[i] << std::endl;
	}
}


void printVector(std::vector<std::string> &v) {
	for (size_t i = 0; i < v.size(); i++)
	{
		std::cout << v[i] << std::endl;
	}

}

int main(int argc, char *argv[]) {


	AppState state(NULL, "kalle", 0, 0, 0, 0, 0);
	std::cout << state.toString() << std::endl;


	DesktopStateManager manager;
	manager.makeSnapshot();
	manager.printStates();




	int wait;
	std::cin >> wait;
}



