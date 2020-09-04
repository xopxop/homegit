#ifndef ZOMBIE_AREA_H
# define ZOMBIE_AREA_H
#include "Zombie.h"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);
Zombie* createHorde(int numZombies, IntRect arena);
#endif