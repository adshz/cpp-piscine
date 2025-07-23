/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:53:41 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:53:44 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include <string>

class ClapTrap {
public:
  static unsigned int const defaultHitPoints = 10;
  static unsigned int const defaultEnergyPoints = 10;
  static unsigned int const defaultAttackDamage = 0;

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

private:
  ClapTrap(void);
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;
};
