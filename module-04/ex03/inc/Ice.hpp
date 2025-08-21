/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:52 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:00:53 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice(void);
  Ice(Ice const &src);
  ~Ice(void);

  Ice &operator=(Ice const &src);

  AMateria *clone(void) const;
  void use(ICharacter &target);
};
