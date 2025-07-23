/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:59:15 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:59:16 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
