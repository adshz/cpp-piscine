/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:42 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:57:43 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ScavTrap.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(void) : ClapTrap() {
  std::cout << CYAN "ScavTrap default constructor called." RESET << std::endl;
  this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
  this->_maxHitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
  this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
  this->_maxEnergyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
  this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
  this->_maxAttackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
  return;
}

ScavTrap::ScavTrap(std::string &name) : ClapTrap(name) {
  std::cout << CYAN "A ScavTrap named \"" << name << "\" was constructed." RESET
            << std::endl;
  this->_hitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
  this->_maxHitPoints = SCAVTRAP_DEFAULT_HIT_POINTS;
  this->_energyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
  this->_maxEnergyPoints = SCAVTRAP_DEFAULT_ENERGY_POINTS;
  this->_attackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
  this->_maxAttackDamage = SCAVTRAP_DEFAULT_ATTACK_DAMAGE;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap() {
  std::cout << CYAN "ScavTrap copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

ScavTrap::~ScavTrap(void) {
  std::cout << CYAN "The ScavTrap named \"" << this->_name
            << "\" was destroyed." RESET << std::endl;
  return;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &src) {
  if (this != &src) {
    this->_name = src.getName();
    this->_hitPoints = src.getHitPoints();
    this->_energyPoints = src.getEnergyPoints();
    this->_attackDamage = src.getAttackDamage();
  }
  return (*this);
}

void ScavTrap::attack(std::string &target) {
  if (this->_hitPoints == 0) {
    std::cout << YELLOW "ScavTrap " << this->_name
              << " can't attack: it is destroyed." RESET << std::endl;
    return;
  }
  if (this->_energyPoints == 0) {
    std::cout << YELLOW "ScavTrap " << this->_name
              << " can't attack: its battery is depleted." RESET << std::endl;
    return;
  }
  if (target == this->_name)
    target = "itself";
  _energyPoints--;
  std::cout << YELLOW "ScavTrap " << this->_name << " leaps on " << target
            << " and crushes it for " << this->_attackDamage << " damage!" RESET
            << std::endl;
}

void ScavTrap::guardGate(void) {
  if (this->_hitPoints == 0)
    std::cout << PURPLE << this->_name
              << "can't guard the gate in its broken state." RESET << std::endl;
  else
    std::cout << PURPLE << this->_name
              << " switches to Gate guarding mode." RESET << std::endl;
  return;
}
