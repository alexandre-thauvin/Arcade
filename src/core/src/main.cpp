#include <iostream>
#include "Core.hpp"

int main(int ac, char **av) {
  (void)av; //TODO: Gestion d'erreur.
  (void)ac;
  arcade::Core core;
  try {
    core.init("./lib/lib_arcade_sdl.so", "conf");
    std::cout << "GoodBye!" << std::endl;
  } catch (arcade::Error &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
