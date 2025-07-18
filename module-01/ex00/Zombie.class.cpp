
#include "Zombie.class.hpp"

Zombie::Zombie(std::string name) : _name(name) { return; }

// Zombie::~Zombie(void) { return; }

Zombie::~Zombie() {}

void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
  return;
}