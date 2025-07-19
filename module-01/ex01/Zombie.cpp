#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
  this->_name = name;
  return;
}

Zombie::Zombie() {}

Zombie::~Zombie(void) {
  std::cout << "[Zombie object]" << this->_name << "destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
  _name = name;
  return;
}

void Zombie::announce(void) {
  std::cout << _name << std::endl;
  return;
}