#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed(void) : _raw(0) {
  std::cerr << "Default constructor called." << std::endl;
  return;
}

Fixed::Fixed(Fixed const &src) {
  std::cerr << "Copy constructor called." << std::endl;
  *this = src;
  return;
}

Fixed::Fixed(int const n) : _raw(n << _fractionalBits) {
  std::cerr << "Int constructor called." << std::endl;
  return;
}

Fixed::Fixed(float const f) : _raw(roundf(f * (1 << _fractionalBits))) {
  std::cerr << "Float constructor called." << std::endl;
  return;
}

Fixed::~Fixed(void) {
  std::cerr << "Destructor called." << std::endl;
  ;
  return;
}
/*------------------------------------------------------*/
Fixed &Fixed::operator=(Fixed const &src) {
  std::cerr << "Copy assignment operator called." << std::endl;
  if (this != &src)
    this->_raw = src.getRawBits();
  return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const {
  if (this->_raw > rhs.getRawBits())
    return (true);
  return (false);
}

bool Fixed::operator<(Fixed const &rhs) const {
  if (this->_raw < rhs.getRawBits())
    return (true);
  return (false);
}

bool Fixed::operator>=(Fixed const &rhs) const {
  if (this->_raw >= rhs.getRawBits())
    return (true);
  return (false);
}

bool Fixed::operator<=(Fixed const &rhs) const {
  if (this->_raw <= rhs.getRawBits())
    return (true);
  return (false);
}

bool Fixed::operator==(Fixed const &rhs) const {
  if (this->_raw == rhs.getRawBits())
    return (true);
  return (false);
}

bool Fixed::operator!=(Fixed const &rhs) const {
  if (this->_raw != rhs.getRawBits())
    return (true);
  return (false);
}

Fixed Fixed::operator+(Fixed const &rhs) const {
  return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const &rhs) const {
  return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const &rhs) const {
  return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const &rhs) const {
  return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed &Fixed::operator++(void) {
  this->_raw += 1;
  return (*this);
}

Fixed Fixed::operator++(int) {
  Fixed tmp(*this);

  ++(*this);
  return (tmp);
}

Fixed &Fixed::operator--(void) {
  this->_raw -= 1;
  return (*this);
}

Fixed Fixed::operator--(int) {
  Fixed tmp(*this);

  --(*this);
  return (tmp);
}

/* GETTERS*/
int Fixed::getRawBits(void) const {
  std::cerr << "getRawBits member function called." << std::endl;
  return (this->_raw);
}

void Fixed::setRawBits(int const raw) {
  std::cerr << "setRawBits member function called." << std::endl;
  this->_raw = raw;
}

/* public functions*/
int Fixed::toInt(void) const { return (this->_raw >> Fixed::_fractionalBits); }

float Fixed::toFloat(void) const {
  return ((float)this->_raw / (1 << _fractionalBits));
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs) {
  if (lhs <= rhs)
    return (lhs);
  return (rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs) {
  if (lhs >= rhs)
    return (lhs);
  return (rhs);
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs) {
  if (lhs >= rhs)
    return (lhs);
  return (rhs);
}

std::ostream &operator<<(std::ostream &os, const Fixed &number) {
  os << number.toFloat();
  return (os);
}