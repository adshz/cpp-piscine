#pragma once
#include <string>

#define CLAPTRAP_DEFAULT_HIT_POINTS 10
#define CLAPTRAP_DEFAULT_ENERGY_POINTS 10
#define CLAPTRAP_DEFAULT_ATTACK_DAMAGE 0

class ClapTrap {
public:
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &src);
  ~ClapTrap(void);

  ClapTrap &operator=(ClapTrap const &src);

  std::string getName(void) const;
  unsigned int getHitPoints(void) const;
  unsigned int getEnergyPoints(void) const;
  unsigned int getAttackDamage(void) const;

  void attack(std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

protected:
  ClapTrap(void);

  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
  unsigned int _maxHitPoints;
  unsigned int _maxEnergyPoints;
  unsigned int _maxAttackDamage;
};