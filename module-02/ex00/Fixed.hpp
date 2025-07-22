#pragma once

class Fixed {
public:
  Fixed(void);
  Fixed(Fixed const &src);
  ~Fixed(void);

  Fixed &operator=(Fixed const &src);

  int getRawBits(void) const;
  void setRawBits(int const raw);

private:
  int _raw;
  static const int _fractionalBits = 8;
};