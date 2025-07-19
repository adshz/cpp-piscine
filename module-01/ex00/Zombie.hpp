#pragma once
#ifndef ZOMBIE_CLASS_HPP
#define ZOMBIE_CLASS_HPP

#include <iostream>
#include <new>
#include <string>

class Zombie {
public:
  Zombie(std::string name);
  ~Zombie(void);
  void setName(std::string name);
  std::string getName(void);
  void announce(void);

private:
  std::string _name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);
#endif