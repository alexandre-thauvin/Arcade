//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Mon Apr  3 12:03:27 2017 Cedric
//

#include "libNCURSES.hpp"

arcade::GfxNCURSES::GfxNCURSES(Vector2u const& dim) {
  _mainSize = dim;
  initscr();
  cbreak();
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
  refresh();
  _mainWindow = newwin(dim.y, dim.x, 0, 0);
  _isOpen = true;
}

arcade::GfxNCURSES::~GfxNCURSES() {
  endwin();
  system("clear");
}

void	arcade::GfxNCURSES::setTitleWindow(std::string const &title) {
}

bool	arcade::GfxNCURSES::isOpen() const {
  return (_isOpen);
}

void	arcade::GfxNCURSES::clear() {
  wclear(_mainWindow);
}

void              close() {
  endwin();
  system("clear");
}

void              setWindowSize(Vector2u const &size){
  wresize(_mainWindow, size.y, size.x);
}

void           draw(DrawObject const& drawObject){
  drawObject.getPosition();
}

arcade::InputT	arcade::GfxNCURSES::getInput() {
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
  refresh();
  wrefresh(_mainWindow);
}
