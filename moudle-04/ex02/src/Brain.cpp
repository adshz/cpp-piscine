#include "Brain.hpp"
#include "Colors.h"
#include <iostream>

Brain::Brain(void) {
  std::cout << CYAN "Brain default constructor called." RESET << std::endl;
  return;
}

Brain::Brain(Brain const &src) {
  std::cout << CYAN "Brain copy constructor called." RESET << std::endl;
  *this = src;
  return;
}

Brain::~Brain(void) {
  std::cout << CYAN "Brain destructor called." RESET << std::endl;
  return;
}

Brain &Brain::operator=(Brain const &src) {
  std::cout << GREEN "Brain assignment overload operator called." RESET
            << std::endl;
  for (int i = 0; i < this->nb_ideas; i++)
    this->_ideas[i] = src._ideas[i];
  return (*this);
}

std::string const &Brain::getIdea(int index) const {
  if (index < 0)
    index = 0;
  return (this->_ideas[index % (nb_ideas - 1)]);
}

void Brain::setIdea(int index, std::string const &idea) {
  if (index < 0)
    return;
  this->_ideas[index % (nb_ideas - 1)] = idea;
  return;
}