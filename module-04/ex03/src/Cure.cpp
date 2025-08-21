/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:01:43 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:01:45 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Cure.hpp"
#include "Colors.h"
#include <iostream>

Cure::Cure(void) : AMateria("cure") {
  std::cout << CYAN "Cure default constructor called." RESET << std::endl;
  return;
}

Cure::Cure(Cure const &src) : AMateria("cure") {
  std::cout << CYAN "Cure copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

Cure::~Cure(void) {
  std::cout << CYAN "Cure destructor called." RESET << std::endl;
  return;
}

Cure &Cure::operator=(Cure const &src) {
  std::cout << CYAN "Cure assignment operator called." RESET << std::endl;
  this->_type = src._type;
  return (*this);
}

AMateria *Cure::clone(void) const {
  AMateria *cureClone = new Cure();
  return (cureClone);
}

void Cure::use(ICharacter &target) {
  std::cout << GREEN "* heals " << target.getName() << "'s wounds *" RESET
            << std::endl;
}
