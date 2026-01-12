  ex00 - ScalarConverter (static_cast)
  - Non-instantiable class with static convert() method
  - Converts string literals to char, int, float, double
  - Handles special cases: nan, inf, -inf, nanf, +inff, -inff

  ex01 - Serializer (reinterpret_cast)
  - Non-instantiable class with static serialize() and deserialize() methods
  - Converts pointer to uintptr_t and back
  - Data struct with id and name members

  ex02 - Identify real type (dynamic_cast)
  - Base class with virtual destructor
  - A, B, C classes inheriting from Base
  - generate() creates random instance
  - identify(Base*) uses pointer dynamic_cast
  - identify(Base&) uses reference dynamic_cast with try/catch

  Each exercise uses the appropriate C++ cast type as required by the subject:
  - ex00: static_cast for type conversions
  - ex01: reinterpret_cast for pointer/integer conversion
  - ex02: dynamic_cast for runtime type identification

