#pragma once

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
public:
  virtual ~IMateriaSource(void) {}

  virtual void learnMateria(AMateria *newMateria) = 0;
  virtual AMateria *createMateria(std::string const &type) = 0;
};