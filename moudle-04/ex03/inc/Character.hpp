#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character : public ICharacter {
public:
  Character(void);
  Character(Character const &src);
  Character(std::string const &name);
  ~Character(void);

  Character &operator=(Character const &rhs);

  std::string const &getName(void) const;
  void setName(std::string const &newName);
  void equip(AMateria *materia);
  void unequip(int slotIndex);
  void use(int slotIndex, ICharacter &target);
  void displayInventory(void) const;

private:
  static int const INVENTORY_SIZE = 4;
  std::string _name;
  AMateria *_inventory[INVENTORY_SIZE];

  void _initializeEmptyInventory(void);
  void _deleteInventory(void);
};