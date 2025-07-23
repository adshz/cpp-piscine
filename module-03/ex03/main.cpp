#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main(void) {
  std::string diamondTrapName = "DT-XXY";
  std::string scavTrapName = "SCVT-2000";
  std::string clapTrapName = "CT-42";

  DiamondTrap diamondTrap(diamondTrapName);
  ScavTrap scavTrap(scavTrapName);
  ClapTrap clapTrap(clapTrapName);

  diamondTrap.whoAmI();
  clapTrap.attack(scavTrapName);
  scavTrap.takeDamage(clapTrap.getAttackDamage());
  scavTrap.attack(clapTrapName);
  clapTrap.takeDamage(scavTrap.getAttackDamage());
  diamondTrap.attack(scavTrapName);
  scavTrap.takeDamage(diamondTrap.getAttackDamage());
  diamondTrap.highFivesGuys();
  diamondTrap.guardGate();
  diamondTrap.takeDamage(5000);
  diamondTrap.beRepaired(5000);
  diamondTrap.whoAmI();
  return (0);
}