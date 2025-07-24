/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:56:49 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:56:51 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Animal.hpp"
#include "Colors.h"
#include <iostream>

Animal::Animal(void) : _type("Unknown") {
  std::cout << CYAN "Animal default constructor called." RESET << std::endl;
  return;
}

Animal::Animal(Animal const &src) {
  std::cout << CYAN "Animal copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

Animal::Animal(std::string const &type) : _type(type) {
  std::cout << CYAN "Animal type constructor called." RESET << std::endl;
  return;
}

Animal::~Animal(void) {
  std::cout << CYAN "Animal destructor called." RESET << std::endl;
  return;
}

Animal &Animal::operator=(Animal const &src) {
  std::cout << GREEN "Animal assignment overload operator called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

std::string const &Animal::getType(void) const { return (this->_type); }

void Animal::makeSound(void) const {
  std::cout << RED << this->_type << ": * Unidentifiable screech *" RESET
            << std::endl;
  return;
}
