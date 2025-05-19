#include <iostream>
#include <string>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPRT = &string;
	std::string &stringREF = string;

	std::cout << "The memory address of the string variable is : "<< &string << std::endl;
	std::cout << "The memory address held by stringPTR is : " << stringPRT << std::endl;
	std::cout << "The memory address held by stringREF is : " << &stringREF << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "The value of the string variable is : " << string << std::endl;
	std::cout << "The value pointed to by stringPTR is : "<< *stringPRT << std::endl;
	std::cout << "The value pointed to by stringREF is : " << stringREF << std::endl;

	return (0);
}