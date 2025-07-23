#pragma once

#include <string>

class AAnimal {
public:
  AAnimal(void);
  AAnimal(AAnimal const &src);
  virtual ~AAnimal(void);

  AAnimal &operator=(AAnimal const &src);

  virtual void makeSound(void) const;

protected:
  std::string _type;
};