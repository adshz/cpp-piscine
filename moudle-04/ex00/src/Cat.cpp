#include "Cat.hpp"
#include "Colors.h"
#include <iostream>
#include <string>

Cat::Cat(void) : Animal() {
  std::cout << CYAN "Cat default constructor called." RESET << std::endl;
  this->_type = "Cat";
  return;
}

Cat::Cat(Cat const &src) : Animal() {
  std::cout << CYAN "Cat copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

Cat::~Cat(void) {
  std::cout << CYAN "Cat destructor called." RESET << std::endl;
  return;
}

Cat &Cat::operator=(Cat const &src) {
  std::cout << GREEN "Cat assignment overload operator called." RESET
            << std::endl;
  if (this != &src)
    this->_type = src._type;
  return (*this);
}

void Cat::makeSound(void) const {
  std::cout << YELLOW << this->_type << ": * Meow...Meow...Meow *" RESET
            << std::endl;
  return;
}