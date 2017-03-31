//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Fri Mar 31 13:03:30 2017 Cedric
//

#include "libNCURSES.hpp"

arcade::GfxNCURSES::GfxNCURSES() {
  keypad(stdscr, TRUE);
  _input[10] = InputT(InputT::KeyPressed, Input::ENTER, InputT::None);
  _input[27] = InputT(InputT::KeyPressed, Input::ESCAPE, InputT::None);
  _input[122] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _input[115] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[100] = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[113] = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[65] = InputT(InputT::KeyPressed, Input::UP, InputT::None);
  _input[66] = InputT(InputT::KeyPressed, Input::DOWN, InputT::None);
  _input[67] = InputT(InputT::KeyPressed, Input::RIGHT, InputT::None);
  _input[68] = InputT(InputT::KeyPressed, Input::LEFT, InputT::None);
  _input[32] = InputT(InputT::KeyPressed, Input::SPACE, InputT::None);
  _input[105] = InputT(InputT::KeyPressed, Input::PREV_LIB, InputT::None);
  _input[112] = InputT(InputT::KeyPressed, Input::NEXT_LIB, InputT::None);
  _input[107] = InputT(InputT::KeyPressed, Input::PREV_GAME, InputT::None);
  _input[109] = InputT(InputT::KeyPressed, Input::NEXT_GAME, InputT::None);
}

arcade::GfxNCURSES::~GfxNCURSES() {
}

void	arcade::GfxNCURSES::setTitleWindow(std::string const &title) {
}

bool	arcade::GfxNCURSES::isOpen() const {
  return (_isOpen);
}

void	arcade::GfxNCURSES::clear() {
  wclear(_mainWindow);
}

arcade::InputT	arcade::GfxNCURSES() {
  int input = getch();
  if (_input.find(input) != _input.end())
    {
      InputT in = _input[input];
      in.type = InputT::TextEntered;
      in.unicode = input;
      return (_input[input]);
    }
  return (InputT(InputT::TextEntered, input, input));
}

void	arcade::GfxNCURSES::display() {
  _mainSizeX = 600;
  _mainSizeY = 600;
  _isOpen = true;
  _mainWindow = SDL_CreateWindow("Main Window", 0, 0, _mainSizeX, _mainSizeY, 0);
  _renderer = SDL_CreateRenderer(_mainWindow, -1, 0);
  std::cin.ignore();
}
