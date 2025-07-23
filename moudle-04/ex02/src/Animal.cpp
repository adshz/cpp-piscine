

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