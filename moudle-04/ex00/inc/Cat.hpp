#pragma once

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat(void);
  Cat(Cat const &src);
  ~Cat(void);

  Cat &operator=(Cat const &src);

  void makeSound(void) const;
};