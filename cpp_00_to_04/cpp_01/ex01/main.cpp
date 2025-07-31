#include "Zombie.hpp"

int main()
{
    Zombie *horde;

    int n;

    n = 8;
    horde = zombieHorde(n, "sergio");
    horde->announce();

    while (--n >= 0)
    {
        std::cout << "Zombie num: " << n << " ";
        horde[n].announce();
    }
    delete[] horde;
    return (0);
}