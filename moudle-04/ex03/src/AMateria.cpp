/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:01:28 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 11:01:29 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

AMateria::AMateria(void) : _type("unknown") {
  std::cout << CYAN "AMateria default constructor called." RESET << std::endl;
  return;
}

AMateria::AMateria(AMateria const &src) : _type(src._type) {
  std::cout << CYAN "AMateria copy constructor called." RESET << std::endl;
  return;
}

AMateria::AMateria(std::string const &type) : _type(type) {
  std::cout << CYAN "AMateria type constructor called." RESET << std::endl;
  return;
}

AMateria::~AMateria(void) {
  std::cout << CYAN "AMateria destructor called." RESET << std::endl;
  return;
}

AMateria &AMateria::operator=(AMateria const &src) {
  std::cout << GREEN "AMateria assignment operator overload called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

void AMateria::use(ICharacter &target) {
  std::cout << RED "* An unknown materia is being used against"
            << target.getName() << " *" RESET << std::endl;
  return;
}

std::string const &AMateria::getType(void) const { return (this->_type); }
