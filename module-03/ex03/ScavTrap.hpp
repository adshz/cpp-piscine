/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:59:31 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:59:32 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
