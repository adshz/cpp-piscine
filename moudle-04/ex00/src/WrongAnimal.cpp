/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szhong <szhong@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:55:15 by szhong            #+#    #+#             */
/*   Updated: 2025/07/24 10:55:18 by szhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "WrongAnimal.hpp"
#include "Colors.h"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("Unknown Beast") {
  std::cout << CYAN "WrongAnimal default constructor called." RESET
            << std::endl;
  return;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {
  std::cout << CYAN "WrongAnimal copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

WrongAnimal::WrongAnimal(std::string const &type) : _type(type) {
  std::cout << CYAN "WrongAnimal type constructor called." RESET << std::endl;
  return;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << CYAN "WrongAnimal destructor called." RESET << std::endl;
  return;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &src) {
  std::cout << GREEN "WrongAnimal assignment overload operator called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

std::string const &WrongAnimal::getType(void) const { return (this->_type); }

void WrongAnimal::makeSound(void) const {
  std::cout << RED << this->_type << ": * Unidentifiable *" RESET << std::endl;
  return;
}
