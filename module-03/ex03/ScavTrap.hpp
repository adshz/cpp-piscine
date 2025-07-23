#pragma once
#include "ClapTrap.hpp"

#define SCAVTRAP_DEFAULT_HIT_POINTS 100
#define SCAVTRAP_DEFAULT_ENERGY_POINTS 50
#define SCAVTRAP_DEFAULT_ATTACK_DAMAGE 20

class ScavTrap : virtual public ClapTrap {
public:
  ScavTrap(const std::string &name);
  ScavTrap(ScavTrap const &src);
  ~ScavTrap(void);

  ScavTrap &operator=(ScavTrap const &src);

  void attack(std::string &target);
  void guardGate(void);

protected:
  ScavTrap(void);
};