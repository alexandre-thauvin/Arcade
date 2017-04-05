//
// lib.cpp for  in /home/cedric/workTek2/cpp_arcade/lib
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Mon Mar 27 23:28:07 2017 Cedric
// Last update Wed Apr  5 02:29:25 2017 Cedric
//

#include "libNCURSES.hpp"
#include <termios.h>
#include <unistd.h>

arcade::GfxNCURSES::GfxNCURSES(Vector2u const& dim) {
  _mainSize = dim;
  initscr();
  nodelay(stdscr, true);
  keypad(stdscr, true);
  noecho();
  curs_set(0);
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
  _isOpen = true;
}

arcade::GfxNCURSES::~GfxNCURSES() {
  close();
}

void	arcade::GfxNCURSES::setTitleWindow(std::string const &title) {
  (void)title;
}

bool	arcade::GfxNCURSES::isOpen() const {
  return (_isOpen);
}

void	arcade::GfxNCURSES::clear() {
  wclear(stdscr);
}

void              arcade::GfxNCURSES::close() {
  curs_set(1);
  nodelay(stdscr, false);
  endwin();
  system("clear");
}

void              arcade::GfxNCURSES::setWindowSize(Vector2u const& size) {
  wresize(stdscr, size.y, size.x);
}

void           arcade::GfxNCURSES::draw(DrawObject const& obj) {
  Vector2u    pos = obj.getPosition();
  Vector2u    size = obj.getSize();
  unsigned int	      i;
  unsigned int	      j;

  i = pos.y;
  while (i < (size.y + pos.y))
    {
      j = pos.x;
      while (j < (size.x + pos.x))
	{
	  if (i == (pos.y) || j == (pos.x) ||
	      j == (size.x - 1 + pos.x) || i == (size.y - 1 + pos.y))
	    mvaddch(i, j, '#');
	  j++;
	}
      i++;
    }
  // SDL_SetRenderDrawColor(_renderer, 40, 44, 52, 255 );
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
}

extern "C" {
  arcade::IGFX *createLib(arcade::Vector2u dim) {
    return (new arcade::GfxNCURSES(dim));
  }
}
