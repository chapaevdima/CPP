#include "Zombie.hpp"
#define N 5

int main (void)
{
    Zombie *zombies = zombieHorde(N, "zombie");

    for (int i = 0; i < N; i++)
        zombies[i].announce();
    
    delete [] zombies;
}