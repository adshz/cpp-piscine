#include "Zombie.hpp"

void randomChump(std::string name) {
  Zombie walkingDead(name);
  walkingDead.announce();
}