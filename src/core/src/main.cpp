#include <string>
#include <unistd.h>
#include <algorithm>
#include <iostream>
#include "Core.hpp"

int check_error(char *av) {
  std::string to_check = av;

  if (to_check.find(".so") == std::string::npos)
    return 1;
  if (access(av, X_OK) == -1)
    return 1;
  return 0;
}

void usage(void) {
  std::cout
          << "# -Arcade- #\n"
          << "Usage: ./arcade [path_lib] \n"
          << "###########################################\n"
          << "Z or UP:\tup\nS or DOWN:\tdown\nQ or LEFT:\tleft\nD or RIGHT:\tright\n"
          << "SPACE:\t\tshoot\n"
          << "ESCAPE:\t\tquitter\nENTER:\t\tselect/play/pause\n"
          << "I <> P:\t\tPrev & Next library\n"
          << "K <> M:\t\tPrev & Next Game\n"
          << "###########################################\n"
          << std::endl;
}

int main(int ac, char **av) {
  arcade::Core core;
  try {
    usage();
    if (ac == 1)
      core.init("", "conf");
    else {
      if (check_error(av[1]) == 1) {
        std::cerr << "Fichier non trouvé ou invalide : " << av[1] << std::endl;
        return 1;
      }
      core.init(av[1], "conf");
    }
    core.play();
    std::cout << "GoodBye!" << std::endl;
  } catch (arcade::Error &e) {
    std::cerr << e.what() << std::endl;
  }
  return (0);
}
