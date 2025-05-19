#include "Zombie.hpp"

int	main()
{
	Zombie *weirdZombie;

	weirdZombie = newZombie("Weird Zombie");
	weirdZombie->announce();
	randomChump("Classic Zombie");
	delete weirdZombie;
	return (0);
}