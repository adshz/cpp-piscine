#pragma once
#include "AMateria.hpp"
#include <string>

class AMateria;

class ICharacter {
public:
  virtual ~ICharacter(void) {}

  virtual std::string const &getName(void) const = 0;
  virtual void equip(AMateria *materia) = 0;
  virtual void unequip(int slotIndex) = 0;
  virtual void use(int slotIndex, ICharacter &target) = 0;
};