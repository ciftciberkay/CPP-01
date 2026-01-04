#include "Zombie.hpp"

int main()
{
    std::cout << "----- Stack Allocation Test -----" << std::endl;
    randomChump("Foo");
    std::cout << std::endl;
    std::cout << "----- Heap Allocation Test -----" << std::endl;
    Zombie* heapZombie = newZombie("Bar");
    if (heapZombie)
    {
        heapZombie->announce();
        delete heapZombie; 
    }
    return 0;
}