#include "Zombie.hpp"

int main()
{
    std::cout << "----- Stack Test (randomChump) -----" << std::endl;
    randomChump("StackZombie");
    std::cout << std::endl;
    std::cout << "----- Heap Test (newZombie) -----" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    return 0;
}