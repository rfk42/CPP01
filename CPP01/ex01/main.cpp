#include "Zombie.hpp"

int	main()
{
	Zombie *HordeOfHalf;
	int N = 9;
	int i = 0;

	HordeOfHalf = zombieHorde(N, "Horde Of Half Zombie");
	while (i < N)
	{
		std::cout << "Number " << i + 1 << " of ";
		HordeOfHalf[i].announce();
		i++;
	}
	delete[] HordeOfHalf;
	return (0);
}