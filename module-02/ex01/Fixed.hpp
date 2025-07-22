#pragma once

#include <iostream>

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  Fixed(int const n);
  Fixed(float const f);
  ~Fixed(void);

  Fixed &operator=(Fixed const &src);

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

private:
  int _raw;
  static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &number);
s