#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

/* Private member functions */
void Harl::_debug(void) {
  std::cout << "[ Debug ]" << std::endl
            << "I love having extra bacon for my "
            << "7XL-double-cheese-triple-pickle-specialketchup burger. "
               "I really do!\n"
            << std::endl;

  return;
}

void Harl::_info(void) {
  std::cout << "[ INFO ]" << std::endl
            << "I cannot believe adding extra bacon costs more money. "
               "You didn't put enough bacon in my burger! If you did, "
               "I wouldn't be asking for more!\n"
            << std::endl;
  return;
}

void Harl::_warning(void) {
  std::cout << "[ WARNING ]" << std::endl
            << "I think I deserve to have some extra bacon for free. "
               "I've been coming for years whereas you started working here "
               "since last month.\n"
            << std::endl;
  return;
}

void Harl::_error(void) {
  std::cout << "[ ERROR ]" << std::endl
            << "This is unacceptable! I want to speak to the manager now.\n"
            << std::endl;
  return;
}

/* Public member functions */
void Harl::complain(std::string level) {
  typedef void (Harl::*fptr)(void);
  std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
  fptr complaints[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning,
                        &Harl::_error};

  for (int i = 0; i < 4; i++) {
    if (levels[i] == level) {
      (this->*complaints[i])();
      return;
    }
  }
  std::cout << "Oops! There is no level \"" << level << "\"." << std::endl;
  return;
}