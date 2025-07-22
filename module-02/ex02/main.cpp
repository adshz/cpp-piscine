#include "Fixed.hpp"
#include <climits>
#include <iostream>

#define RESET "\e[0m"
#define GREEN "\e[32m"
#define RED "\e[31m"

enum e_compare {
  GREATER,
  LESS,
  GREATER_EQUAL,
  LESS_EQUAL,
  EQUAL,
  NOT_EQUAL,
  MIN,
  MAX
};

enum e_binary { ADD, SUBTRACT, MULTIPLY, DIVIDE };

enum e_unary { PRE_INCREMENT, PRE_DECREMENT, POST_INCREMENT, POST_DECREMENT };

void testCompare(Fixed &a, Fixed &b, int comparator) {
  bool result;
  bool expected;

  switch (comparator) {
  case GREATER:
    expected = a.getRawBits() > b.getRawBits();
    result = a > b;
    break;
  case LESS:
    expected = a.getRawBits() < b.getRawBits();
    result = a < b;
    break;
  case GREATER_EQUAL:
    expected = a.getRawBits() >= b.getRawBits();
    result = a >= b;
    break;
  case LESS_EQUAL:
    expected = a.getRawBits() <= b.getRawBits();
    result = a <= b;
    break;
  case EQUAL:
    expected = a.getRawBits() == b.getRawBits();
    result = a == b;
    break;
  case NOT_EQUAL:
    expected = a.getRawBits() != b.getRawBits();
    result = a != b;
    break;
  }
  if (result == expected)
    std::cout << GREEN << "[OK]\t";
  else
    std::cout << RED << "[KO]\t";
}

void testBinary(Fixed &a, Fixed &b, int operation) {
  Fixed result;
  float expected = 0;

  switch (operation) {
  case ADD:
    result = a + b;
    expected = a.toFloat() + b.toFloat();
    break;
  case SUBTRACT:
    result = a - b;
    expected = a.toFloat() - b.toFloat();
    break;
  case MULTIPLY:
    result = a * b;
    expected = a.toFloat() * b.toFloat();
    break;
  case DIVIDE:
    result = a / b;
    expected = a.toFloat() / b.toFloat();
    break;
  }
  if (result == expected)
    std::cout << GREEN << "[OK]\t";
  else
    std::cout << RED << "[KO]\t" << "expected: " << expected
              << ", got: " << result.getRawBits() << std::endl
              << "\t";
}

void testUnary(Fixed a, int operation) {
  Fixed result;
  int expected = 0;
  int original = a.getRawBits();

  switch (operation) {
  case PRE_INCREMENT:
    expected = original + 1;
    result = ++a;
    break;
  case PRE_DECREMENT:
    expected = original - 1;
    result = --a;
    break;
  case POST_INCREMENT:
    expected = original;
    result = a++;
    if (a.getRawBits() != original + 1)
      std::cout << RED << "[POST-INCREMENT KO] Object not incremented\t"
                << std::endl;
    break;
  case POST_DECREMENT:
    expected = original;
    result = a--;
    if (a.getRawBits() != original - 1)
      std::cout << RED << "[POST-DECREMENT KO] Objectt not decrementted\t"
                << std::endl;
    break;
  }
  if (result.getRawBits() == expected)
    std::cout << GREEN << "[OK]\t";
  else
    std::cout << RED << "[KO]\t" << "expected: " << expected
              << ", got: " << result.getRawBits() << std::endl
              << "\t";
}

void testMinMax(Fixed &a, Fixed &b, int operation) {
  Fixed expected;
  Fixed result;

  switch (operation) {
  case MIN:
    expected = (a.getRawBits() < b.getRawBits()) ? a : b;
    result = Fixed::min(a, b);
    break;
  case MAX:
    expected = (a.getRawBits() > b.getRawBits()) ? a : b;
    result = Fixed::max(a, b);
    break;
  }
  if (expected == result)
    std::cout << GREEN << "[OK]\t";
  else
    std::cout << RED << "[KO]\t" << "expected: " << expected
              << ", got: " << result.getRawBits() << std::endl
              << "\t";
}

void compareTest(Fixed &a, Fixed &b) {
  std::cout << std::endl << "a: " << a << std::endl << "b: " << b << std::endl;
  testCompare(a, b, GREATER);
  std::cout << "a > b\t: " << std::boolalpha << (a > b) << RESET << std::endl;
  testCompare(b, a, GREATER);
  std::cout << "b > a\t: " << std::boolalpha << (b > a) << RESET << std::endl;
  testCompare(a, b, LESS);
  std::cout << "a < b\t: " << std::boolalpha << (a < b) << RESET << std::endl;
  testCompare(b, a, LESS);
  std::cout << "b < a\t: " << std::boolalpha << (b < a) << RESET << std::endl;
  testCompare(a, b, GREATER_EQUAL);
  std::cout << "a >= b\t: " << std::boolalpha << (a >= b) << RESET << std::endl;
  testCompare(b, a, GREATER_EQUAL);
  std::cout << "b >= a\t: " << std::boolalpha << (b >= a) << RESET << std::endl;
  testCompare(a, b, LESS_EQUAL);
  std::cout << "a <= b\t: " << std::boolalpha << (a <= b) << RESET << std::endl;
  testCompare(b, a, LESS_EQUAL);
  std::cout << "b <= a\t: " << std::boolalpha << (b <= a) << RESET << std::endl;
  testCompare(a, b, EQUAL);
  std::cout << "a == b\t: " << std::boolalpha << (a == b) << RESET << std::endl;
  testCompare(b, a, EQUAL);
  std::cout << "b == a\t: " << std::boolalpha << (b == a) << RESET << std::endl;
  testCompare(a, b, NOT_EQUAL);
  std::cout << "a != b\t: " << std::boolalpha << (a != b) << RESET << std::endl;
  testCompare(b, a, NOT_EQUAL);
  std::cout << "b != a\t: " << std::boolalpha << (b != a) << RESET << std::endl;
}

void binaryTest(Fixed &a, Fixed &b) {
  std::cout << std::endl << "a: " << a << std::endl << "b: " << b << std::endl;
  testBinary(a, b, ADD);
  std::cout << "a + b = " << a << " + " << b << " = " << (a + b) << RESET
            << std::endl;
  testBinary(a, b, SUBTRACT);
  std::cout << "a - b = " << a << " - " << b << " = " << (a - b) << RESET
            << std::endl;
  testBinary(a, b, MULTIPLY);
  std::cout << "a * b = " << a << " * " << b << " = " << (a * b) << RESET
            << std::endl;
  testBinary(a, b, DIVIDE);
  std::cout << "a / b = " << a << " / " << b << " = " << (a / b) << RESET
            << std::endl;
}

void unaryTest(Fixed &a) {
  std::cout << std::endl << "a: " << a << std::endl;
  testUnary(a, PRE_INCREMENT);
  std::cout << "++a = " << ++a << RESET << std::endl;
  testUnary(a, PRE_DECREMENT);
  std::cout << "--a = " << --a << RESET << std::endl;
  testUnary(a, POST_INCREMENT);
  std::cout << "a++ = " << a++ << " -> " << a << RESET << std::endl;
  testUnary(a, POST_DECREMENT);
  std::cout << "a-- = " << a-- << " -> " << a << RESET << std::endl;
}

void minMaxTest(Fixed &a, Fixed &b) {
  std::cout << std::endl << "a: " << a << std::endl << "b: " << b << std::endl;
  testMinMax(a, b, MIN);
  std::cout << "min( a, b ) = " << Fixed::min(a, b) << RESET << std::endl;
  testMinMax(b, a, MIN);
  std::cout << "min( b, a ) = " << Fixed::min(b, a) << RESET << std::endl;
  testMinMax(a, b, MAX);
  std::cout << "max( a, b ) = " << Fixed::max(a, b) << RESET << std::endl;
  testMinMax(b, a, MAX);
  std::cout << "max( b, a ) = " << Fixed::max(b, a) << RESET << std::endl;
}

void subjectTests(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
}

int main(void) {
  Fixed a(42.5f);
  Fixed b;

  std::cout << std::endl << "---- Subject tests" << std::endl;
  subjectTests();

  std::cout << std::endl << "---- Comparison operator tests" << std::endl;
  compareTest(a, b);
  b = a;
  compareTest(a, b);

  std::cout << std::endl << "---- Binary operator tests" << std::endl;
  binaryTest(a, b);
  a = a + b + 0.25f;
  b = 1700;
  binaryTest(a, b);
  a = 8;
  b = -35;
  binaryTest(a, b);
  a = INT_MIN;
  b = INT_MAX;
  binaryTest(a, b);

  std::cout << std::endl << "---- Unary operator tests" << std::endl;
  unaryTest(a);
  a = 20;
  unaryTest(a);

  std::cout << std::endl << "---- Min Max function tests" << std::endl;
  b = -35;
  minMaxTest(a, b);

  return (0);
}