/* ************************************************************************** *
 *   Core.cpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#include <unistd.h>

#include "Core.hpp"

arcade::Core::Core(void)
{
 _state = GameState::MenuState;
}

arcade::Core::~Core(void) {}

void arcade::Core::init(std::string const &lib, std::string const &conf)
{
  try {
    signal(SIGINT, arcade_ragequit);
  } catch (ArcadeError const &error) {
    throw (error);
  }
}

bool                    arcade::Core::play(void)
{
    while (true)
    {
        std::cout << std::endl << "LOOP_PLAY: " << _state << std::endl;
        usleep(1000000);
    }

}

void                    arcade_ragequit(int n)
{
  (void)n;
  std::cout << std::endl << "receiving signal SIGINT" << std::endl;
  std::cout << "exit" << std::endl;
  exit(1);
}
