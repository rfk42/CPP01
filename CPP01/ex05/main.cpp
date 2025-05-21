#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

int main()
{
	Harl harl;

	std::cout << "DEBUG :" << std::endl;
	harl.complain("DEBUG");
	std::cout << "INFO :" << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING :" << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR :" << std::endl;
	harl.complain("ERROR");
	std::cout << "VOID :" << std::endl;
	harl.complain("VOID");
}