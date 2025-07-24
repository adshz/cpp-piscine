/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:00:19 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:00:21 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
public:
  AMateria(void);
  AMateria(AMateria const &src);
  AMateria(std::string const &type);
  virtual ~AMateria(void);

  AMateria &operator=(AMateria const &rhs);

  std::string const &getType(void) const;
  virtual AMateria *clone(void) const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string _type;
};
