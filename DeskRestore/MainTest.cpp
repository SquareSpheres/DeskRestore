#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "AppState.h"
#include "WinWrapper.h"



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





	std::unordered_map<HWND, int> order;
	order = WinWrapper::GetOpenWindowsZOrder();

	std::vector<HWND> openWidows;
	WinWrapper::GetOpenWindows(&openWidows);

	std::cout << openWidows.size() << std::endl;
	std::cout << order.size() << std::endl;

	
	for each (HWND handle in openWidows)
	{
	
		auto t = order.find(handle);


		if (t!=order.end()) {
			std::cout << WinWrapper::GetWindowTextAsString(handle) << " = " << order[handle] << std::endl;
		}

	}

	std::cout << order[nullptr];




	int wait;
	std::cin >> wait;
}



