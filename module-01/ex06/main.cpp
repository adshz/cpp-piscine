#include "Harl.hpp"

int main(int argc, char **argv) {
  Harl angryHarl;

  if (argc != 2) {
    std::cout << "Usage: ./harlFilter <level> " << std::endl
              << "Levels are: \n"
              << "\tDEBUG\n"
              << "\tINFO\n"
              << "\tWARNING\n"
              << "\tERROR\n"
              << std::endl;
    return (0);
  }
  angryHarl.complain(argv[1]);
  return (0);
}