#include "Zombie.hpp"

#define NUM_ZOMBIES 5

int main()
{
    Zombie* horde = zombieHorde(NUM_ZOMBIES, "HordeMember");

    for (int i = 0; i < NUM_ZOMBIES; i++)
    {
        horde[i].announce();
    }
    delete [] horde;
    return 0;
}