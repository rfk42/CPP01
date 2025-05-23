#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie :" << name << ", has been created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie :" << name << ", has been destroyed" << std::endl;
}
void Zombie::announce() 
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
