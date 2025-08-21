/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:42 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:00:44 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {
public:
  Cure(void);
  Cure(Cure const &src);
  ~Cure(void);

  Cure &operator=(Cure const &rhs);

  AMateria *clone(void) const;
  void use(ICharacter &target);
};
