#include "Dog.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

Dog::Dog(void) : Animal("Dog") {
  std::cout << CYAN "Dog default constructor called." RESET << std::endl;
  this->_type = "Dog";
  return;
}

Dog::Dog(Dog const &src) : Animal(src._type) {
  std::cout << CYAN "Dog copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

Dog::~Dog(void) {
  std::cout << CYAN "Dog destructor called." RESET << std::endl;
  return;
}

Dog &Dog::operator=(Dog const &src) {
  std::cout << GREEN "Dog assignment overload operator called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

void Dog::makeSound(void) const {
  std::cout << YELLOW << this->_type << ": * Woof! Woof! Woof! Woof! *" RESET
            << std::endl;
  return;
}
