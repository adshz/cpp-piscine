/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:01:00 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:01:02 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter(void) {}

  virtual std::string const &getName(void) const = 0;
  virtual void equip(AMateria *materia) = 0;
  virtual void unequip(int slotIndex) = 0;
  virtual void use(int slotIndex, ICharacter &target) = 0;
};
