#include "Zombie.hpp"

int main()
{
  Zombie sergio("sergio");
  Zombie zFoo("Foo");
  Zombie zFoo2("Foo");
  Zombie *zzz;
  sergio.announce();
  zFoo.announce();
  zFoo2.announce();

  zzz = newZombie("cacca");
  zzz->announce();
  randomChump("hiihihiihi");
  delete zzz;

  return (0);
}