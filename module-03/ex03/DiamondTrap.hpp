#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public FragTrap, public ScavTrap {
public:
  DiamondTrap(DiamondTrap const &src);
  DiamondTrap(std::string name);
  ~DiamondTrap(void);

  DiamondTrap &operator=(DiamondTrap const &src);

  using ScavTrap::attack;

  void whoAmI(void);

protected:
  DiamondTrap(void);

private:
  std::string _name;
};