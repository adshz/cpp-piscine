#include "ClapTrap.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

int main(void) {
  std::string trapName21 = "CT-21";
  ClapTrap trapZero(trapName21);

  std::string trapName42 = "CT-42";
  ClapTrap trapOne(trapName42);

  std::cout << "=======HEALTH STATUS=======" << std::endl;
  std::cout << BRIGHT_GREEN << trapZero.getName()
            << "-Energy Point:" << trapZero.getEnergyPoints() << std::endl;
  std::cout << BRIGHT_GREEN << trapOne.getName()
            << "-Energy Point:" << trapOne.getEnergyPoints() << RESET
            << std::endl;
  std::cout << "======================" << std::endl;
  trapOne.beRepaired(0);
  std::cout << "=======BATTLE=======" << std::endl;
  for (int i = 0; i < 9; i++) {
    trapZero.attack(trapName21);
    trapOne.takeDamage(ClapTrap::defaultAttackDamage);
  }
  std::cout << "=======LOOP END=========" << std::endl;
  trapZero.attack(trapName21);
  trapOne.takeDamage(5);
  trapOne.beRepaired(4);
  trapOne.attack(trapName42);
  trapZero.takeDamage(5);
  trapZero.beRepaired(5000);
  trapOne.beRepaired(5000);
  trapOne.attack(trapName21);
  trapOne.takeDamage(5000);
  trapOne.beRepaired(5000);
  trapOne.takeDamage(1);
  return (0);
}