#pragma once
#include <iostream>
#include <string>

class Harl {
private:
  void _debug(void);
  void _info(void);
  void _warning(void);
  void _error(void);

public:
  Harl(void);
  ~Harl(void);
  void complain(std::string level);
};