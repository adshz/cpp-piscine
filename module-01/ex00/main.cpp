#include "Zombie.hpp"

int main(void) {
  std::cout << "CREATE ZOMBIE USING STACK ALLOCATION" << std::endl;
  Zombie walkingDead("Foo");
  walkingDead.announce();
  std::cout << "=================================" << std::endl;
  std::cout << "" << std::endl;

  std::cout << "CREATE ZOMBIE USING randomChump" << std::endl;
  randomChump("stackZombie");
  std::cout << "=================================" << std::endl;
  std::cout << "" << std::endl;

  std::cout << "CREATE ZOMBIE USING HEAP ALLOCATION" << std::endl;
  Zombie *theLastOfUs = newZombie("TLOU");
  (*theLastOfUs).announce();

  delete theLastOfUs;
  std::cout << "==================END================" << std::endl;
  return (0);
}
