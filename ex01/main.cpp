#include "Zombie.hpp"
#define ZOMBIE_COUNT 5

int main()
{
    std::cout << "Creating a horde of " << ZOMBIE_COUNT << " zombies..." << std::endl;
    Zombie* horde = zombieHorde(ZOMBIE_COUNT, "CloneTrooper");
    std::cout << "\nAnnouncing..." << std::endl;
    int i = 0;
    while (i < ZOMBIE_COUNT)
    {
        horde[i].announce();
        i++;
    }
    std::cout << "\nDeleting the horde..." << std::endl;
    delete[] horde;
    return 0;
}