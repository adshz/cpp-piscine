#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
  Dog(void);
  Dog(Dog const &src);
  ~Dog(void);

  Dog &operator=(Dog const &src);

  Brain *getBrain(void) const;
  void makeSound(void) const;

private:
  Brain *_brain;
};