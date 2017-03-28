#include <iostream>
#include "Core.hpp"

int main(int ac, char **av) {
  (void)av; //TODO: Gestion d'erreur.
  (void)ac;
  arcade::Core core;
  try {
    core.init("first av", "conf");
    core.play();
    std::cout << "Hello World!" << std::endl;
    arcade::Vector2i a(10, 10);
    arcade::Vector2i b(24, 20);
    a = b;
    std::cout << a << std::endl;
  } catch (arcade::ArcadeError const &err) {
    std::cerr << err.what() << std::endl;
  }
  return (0);
}
