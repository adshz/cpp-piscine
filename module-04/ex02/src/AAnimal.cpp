/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:58:28 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:58:53 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AAnimal.hpp"
#include "Colors.h"
#include <iostream>

AAnimal::AAnimal(void) : _type("Unknown") {
  std::cout << CYAN "Animal default constructor called." RESET << std::endl;
  return;
}

AAnimal::AAnimal(AAnimal const &src) {
  std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

AAnimal::~AAnimal(void) {
  std::cout << CYAN "Animal destructor called." RESET << std::endl;
  return;
}

AAnimal &AAnimal::operator=(AAnimal const &src) {
  std::cout << GREEN "Animal assignment overload operator called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

void AAnimal::makeSound(void) const {
  std::cout << RED << this->_type << ": * Unidentifiable screech *" RESET
            << std::endl;
  return;
}
