#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	int i = 0;
	Zombie *zombieHorde;
	
	zombieHorde = new Zombie[N];
	while (i < N)
	{
		zombieHorde[i] = Zombie(name);
		i++;
	}
	return (zombieHorde);
}

