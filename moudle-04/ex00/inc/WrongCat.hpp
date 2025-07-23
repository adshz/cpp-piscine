#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat(void);
  WrongCat(WrongCat const &src);
  ~WrongCat(void);

  WrongCat &operator=(WrongCat const &src);

  void makeSound(void) const;
};