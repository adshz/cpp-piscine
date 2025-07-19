#include <iostream>
#include <string>

int main(void) {
  std::string greeting = "HI THIS IS BRAIN";

  std::string *stringPTR = &greeting;
  std::string &stringREF = greeting;

  std::cout << "Memory address: string variable [greeting]: " << &greeting
            << std::endl;
  std::cout << "Memory address: pointer variable [stringPTR]: " << &stringPTR
            << std::endl;
  std::cout << "Memroy address held by the pointer variable [stringPTR]: "
            << stringPTR << std::endl;
  std::cout << "Memory address: reference variable [stringREF]: " << &stringREF
            << std::endl;

  std::cout << "The value of the string variable: " << greeting << std::endl;
  std::cout << "The value pointed by stringPTR: " << *stringPTR << std::endl;
  std::cout << "The value referenced by stringREF: " << stringREF << std::endl;

  return (0);
}