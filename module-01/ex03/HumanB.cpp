#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon) {
  this->_weapon = &weapon;
  return;
}

void HumanB::attack(void) const {
  std::cout << this->_name << " attacks with their ";
  if (this->_weapon != NULL) {
    std::cout << this->_weapon->getType();
  } else {
    std::cout << "bare fists";
  }
  std::cout << std::endl;
  return;
}