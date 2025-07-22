#include "Fixed.hpp"
#include <iostream>

/* Default constructor */
Fixed::Fixed(void) : _raw(0) {
  std::cerr << "Default constructor called." << std::endl;
  return;
}

/* Copy constructor */
Fixed::Fixed(Fixed const &src) {
  std::cerr << "Copy constructor called." << std::endl;
  *this = src;
  return;
}

/* Desctructor */
Fixed::~Fixed(void) {
  std::cerr << "Destructor called." << std::endl;
  return;
}

/******************************************************************************/
/*								OPERATORS
 */
/******************************************************************************/
Fixed &Fixed::operator=(Fixed const &src) {
  std::cerr << "Copy assignment operator called" << std::endl;
  if (this != &src)
    this->_raw = src.getRawBits();
  return (*this);
}

/* Getter */
int Fixed::getRawBits(void) const {
  std::cerr << "getRawBits member function called." << std::endl;
  return (this->_raw);
}

/* Setter */
void Fixed::setRawBits(int const raw) {
  std::cerr << "setRawBits member function called." << std::endl;
  this->_raw = raw;
  return;
}