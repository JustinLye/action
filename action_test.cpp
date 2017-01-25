#include<iostream>
#include"action.h"

int main(int argc, char* argv[]) {
	jl::base_action a;
	a.issue();
	std::cout << a.id() << std::endl;
	jl::base_action b;
	b.issue();
	std::cout << b.id() << std::endl;
	return EXIT_SUCCESS;
}