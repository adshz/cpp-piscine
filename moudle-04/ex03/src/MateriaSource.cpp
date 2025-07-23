#include "MateriaSource.hpp"
#include "Colors.h"
#include <iostream>

MateriaSource::MateriaSource(void) {
  std::cout << CYAN "MateriaSource default constructor called." RESET
            << std::endl;
  this->_initializeEmptyRecipes();
  return;
}

MateriaSource::MateriaSource(MateriaSource const &src) {
  std::cout << CYAN "MateriaSource copy constructor called." RESET << std::endl;
  this->_initializeEmptyRecipes();
  *this = src;
  return;
}

MateriaSource::~MateriaSource(void) {
  std::cout << CYAN "MateriaSource destructor called." RESET << std::endl;
  this->_deleteRecipes();
  return;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &src) {
  std::cout << CYAN "MateriaSource assignment operator overload called." RESET
            << std::endl;
  this->_deleteRecipes();
  for (int i = 0; i < this->MAX_RECIPES; i++) {
    if (src._recipes[i] != NULL)
      this->_recipes[i] = src._recipes[i]->clone();
  }
  return (*this);
}

void MateriaSource::learnMateria(AMateria *materia) {
  if (!materia) {
    std::cout << RED
        "MateriaSource was not provided with a materia to learn." RESET
              << std::endl;
    return;
  }
  for (int i = 0; i < this->MAX_RECIPES; i++) {
    if (this->_recipes[i] == NULL) {
      this->_recipes[i] = materia;
      std::cout << GREEN "MateriaSource learned the " << materia->getType()
                << " materia recipe." RESET << std::endl;
      return;
    }
  }
  std::cout << RED "MateriaSource can't learn any more materia." RESET
            << std::endl;
  delete materia;
  return;
}

AMateria *MateriaSource::createMateria(std::string const &type) {
  for (int i = 0; i < this->MAX_RECIPES; i++) {
    if (this->_recipes[i] && this->_recipes[i]->getType() == type) {
      std::cout << GREEN "MateriaSource creating " << type << " materia." RESET
                << std::endl;
      return (this->_recipes[i]->clone());
    }
  }
  std::cout << RED "MateriaSource does not know the type \"" << type
            << "\"." RESET << std::endl;
  return (NULL);
}

void MateriaSource::_initializeEmptyRecipes(void) {
  for (int i = 0; i < this->MAX_RECIPES; i++)
    this->_recipes[i] = NULL;
  return;
}

void MateriaSource::_deleteRecipes(void) {
  for (int i = 0; i < this->MAX_RECIPES; i++) {
    if (this->_recipes[i] != NULL) {
      delete this->_recipes[i];
      this->_recipes[i] = NULL;
    }
  }
  return;
}

void MateriaSource::displayKnownRecipes(void) {
  std::cout << "MateriaSource knows the following recipes:" << std::endl;
  for (int i = 0; i < this->MAX_RECIPES; i++) {
    std::cout << "\t[" << i << "] ";
    if (this->_recipes[i] == NULL)
      std::cout << "Empty slot.";
    else
      std::cout << this->_recipes[i]->getType() << " materia.";
    std::cout << std::endl;
  }
  return;
}