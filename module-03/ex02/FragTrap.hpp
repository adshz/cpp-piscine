/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:57:33 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:57:34 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "ClapTrap.hpp"

#define FRAGTRAP_DEFAULT_HIT_POINTS 100
#define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
#define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : public ClapTrap {
public:
  FragTrap(std::string &name);
  FragTrap(FragTrap const &src);
  ~FragTrap(void);

  FragTrap &operator=(FragTrap const &src);

  void highFivesGuys(void);

private:
  FragTrap(void);
};
