#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
  MateriaSource(void);
  MateriaSource(MateriaSource const &src);
  ~MateriaSource(void);

  MateriaSource &operator=(MateriaSource const &rhs);

  void learnMateria(AMateria *newMateria);
  AMateria *createMateria(std::string const &type);
  void displayKnownRecipes(void);

private:
  static int const MAX_RECIPES = 4;
  AMateria *_recipes[MAX_RECIPES];

  void _initializeEmptyRecipes(void);
  void _deleteRecipes(void);
};
