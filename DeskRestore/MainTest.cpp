#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include "DesktopStateManager.h"
#include <conio.h>



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

	DesktopStateManager manager;
	
	while (TRUE) {
		char c;
		std::cout << "input : ";
		c = _getch();


		switch (c)
		{
		case '1':
			manager.makeSnapshot();
			manager.printStates();
			break;
		case '2':
			break;
		case '3':
			break;
		default:
			break;
		}
	}


	
	




	int wait;
	std::cin >> wait;
}



