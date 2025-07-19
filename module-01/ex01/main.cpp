#include "Zombie.hpp"

int main(void) {
  int const number = 42;
  Zombie *horde = zombieHorde(number, "42LondonZombie");

  for (int i = 0; i < number; i++) {
    horde[i].announce();
  }
  delete[] horde;
  return (0);
}