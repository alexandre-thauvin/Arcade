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

arcade::Core::Core(void) {
  _state = GameState::MenuState;
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None), std::bind(&arcade::Core::goQuit, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::ENTER, InputT::None), std::bind(&arcade::Core::goEnter, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::UP, InputT::None), std::bind(&arcade::Core::goUp, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::DOWN, InputT::None), std::bind(&arcade::Core::goDown, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::LEFT, InputT::None), std::bind(&arcade::Core::goLeft, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::RIGHT, InputT::None), std::bind(&arcade::Core::goRight, this)));
  _input.insert(std::make_pair(InputT(InputT::KeyPressed, Input::SPACE, InputT::None), std::bind(&arcade::Core::goShoot, this)));
}

arcade::Core::~Core(void) {}

void arcade::Core::init(std::string const &lib, std::string const &conf)
{
  (void) lib;
  (void) conf;
  try {
    signal(SIGINT, arcade_ragequit);
  } catch (ArcadeError const &error) {
    throw (error);
  }
}

bool                    arcade::Core::play(void)
{
    arcade::GFX         gfx;
    arcade::InputT       input;

    (void)input;
    while (true)
    {
        input = gfx.getInput();
        if(_input.find(input) != _input.end()) {
            _input[input]();
        }
        usleep(MAIN_SLEEP);
    }

}

void                    arcade::Core::goUp(void)
{
    std::cout << "Up!" << std::endl;
}

void                    arcade::Core::goDown(void)
{
    std::cout << "Down!" << std::endl;
}

void                    arcade::Core::goLeft(void)
{
    std::cout << "Left!" << std::endl;
}

void                    arcade::Core::goRight(void)
{
    std::cout << "Right!" << std::endl;
}

void                    arcade::Core::goQuit(void)
{
    std::cout << "Quit!" << std::endl;
}

void                    arcade::Core::goEnter(void)
{
    std::cout << "Enter!" << std::endl;
}

void                    arcade::Core::goShoot(void)
{
    std::cout << "Shoot!" << std::endl;
}

void                    arcade_ragequit(int x)
{
  (void)x;
  std::cout << std::endl << "OMFG! Don't ragequit!" << std::endl;
  std::cout << "exit" << std::endl;
  exit(1);
}
