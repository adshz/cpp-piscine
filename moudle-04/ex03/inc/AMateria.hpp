#pragma once

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria {
public:
  AMateria(void);
  AMateria(AMateria const &src);
  AMateria(std::string const &type);
  virtual ~AMateria(void);

  AMateria &operator=(AMateria const &rhs);

  std::string const &getType(void) const;
  virtual AMateria *clone(void) const = 0;
  virtual void use(ICharacter &target);

protected:
  std::string _type;
};