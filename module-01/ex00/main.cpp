#include "main.hpp"

#define LOG(x) std::cout << x << std::endl

int main(void) {
  LOG("CREATE ZOMBIE USING STACK ALLOCATION");
  Zombie walkingDead("Foo");
  walkingDead.announce();
  LOG("=================================");
  LOG("");

  LOG("CREATE ZOMBIE USING randomChump");
  randomChump("stackZombie");
  LOG("=================================");
  LOG("");

  LOG("CREATE ZOMBIE USING HEAP ALLOCATION");
  Zombie *theLastOfUs = newZombie("TLOU");
  (*theLastOfUs).announce();

  delete theLastOfUs;
  LOG("==================END================");
  return (0);
}
