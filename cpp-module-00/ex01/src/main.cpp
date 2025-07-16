#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"

void  display_menu(void) {
  std::cout << "\033[1;33m";
  std::cout << "================== MENU =====================" << std::endl;
  std::cout << "  Please enter one of the following commands: " << std::endl;
  std::cout << "---------------------------------------------\033[0m" << std::endl;
  
  std::cout << "- ADD:\tAdd a new contact to your phonebook" << std::endl;
  std::cout << "- SEARCH:\tSearch for a contact in your phonebook" << std::endl;
  std::cout << "- EXIT:\tExit the program" << std::endl << std::endl;
  
  std::cout << "\033[1;33m---------------------------------------------\033[0m" << std::endl;
  std::cout << "\033[3mEnter your command:\033[0m " << std::endl << std::endl;
  std::cout << ">> ";
}

std::string getInput(PhoneBook *book) {
  std::string input;

  if (!std::getline(std::cin, input) || std::cin.eof()) {
    std::cout << "EXIT" << std::endl;
    return ("EXIT");
  }
  input = book->trim(input);
  for (std::string::iterator itr = input.begin(); itr != input.end(); itr++) {
    *itr = std::toupper(*itr);
  }
  return (input);

}

int main(void) {
  PhoneBook   Book;
  std::string input;

  std::cout << "\033[1;36m";
  std::cout << "=============================================" << std::endl;
  std::cout << "          WELCOME TO PHONEBOOK PROGRAM       " << std::endl;
  std::cout << "=============================================\033[0m" << std::endl << std::endl;
  while (1) {
    display_menu();
    input = getInput(&Book);
    if (input == "EXIT")
      break ;
    else if (input == "ADD") {
      if (!Book.add())
        break ;
    }
    else if (input == "SEARCH") {
      if (!Book.search())
        break ;
    }
    else
      display_menu();
  }
  std::cout << "Thank you for using PhoneBook progran! See you soon!:)" <<std::endl;
  return (0);
}
