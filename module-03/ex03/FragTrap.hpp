/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:58:47 by szhong            #+#    #+#             */
/*   Updated: 2025/07/23 15:58:49 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "ClapTrap.hpp"

#define FRAGTRAP_DEFAULT_HIT_POINTS 100
#define FRAGTRAP_DEFAULT_ENERGY_POINTS 100
#define FRAGTRAP_DEFAULT_ATTACK_DAMAGE 30

class FragTrap : virtual public ClapTrap {
public:
  FragTrap(const std::string &name);
  FragTrap(FragTrap const &src);
  ~FragTrap(void);

  FragTrap &operator=(FragTrap const &src);

  void highFivesGuys(void);

protected:
  FragTrap(void);
};
