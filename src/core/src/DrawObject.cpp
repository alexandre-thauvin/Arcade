//
// DrawObject.cpp for  in /home/aneopsy/cpp_arcade/src/core/src/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Wed Mar 29 18:30:33 2017 Paul THEIS
// Last update Wed Mar 29 18:44:39 2017 Paul THEIS
//

#include "DrawObject.hpp"

arcade::DrawObject::DrawObject(void) {
  _rgba = arcade::Color();
  _position = arcade::Vector2i(0, 0);
  _size = arcade::Vector2u(0, 0);
}
arcade::DrawObject::~DrawObject(void) {}

void              arcade::DrawObject::draw(IGFX *&graphic, bool const bright) {
  (void)graphic;
  (void)bright;
}

void              arcade::DrawObject::setPosition(Vector2i const& pos) {
  _position = pos;
}

void              arcade::DrawObject::setSize(Vector2u const& size) {
  _size = size;
}

void              arcade::DrawObject::setCharacterSize(size_t const size) {
  _charactere_size = size;
}

void              arcade::DrawObject::setText(std::string const& text) {
  _text = text;
}

void              arcade::DrawObject::setColor(arcade::Color const& rgba) {
  _rgba = rgba;
}

arcade::Vector2i  arcade::DrawObject::getPosition(void) const {
    return (_position);
}

arcade::Vector2i  arcade::DrawObject::getRPosition(void) const {
    return (_r_position);
}

arcade::Vector2u  arcade::DrawObject::getSize(void) const {
    return (_size);
}

size_t            arcade::DrawObject::getCharacterSize(void) const {
    return (_charactere_size);
}
std::string       arcade::DrawObject::getText(void) const {
    return (_text);
}
arcade::Color     arcade::DrawObject::getColor(void) const {
    return (_rgba);
}

bool              arcade::DrawObject::isClickable(void) const {
    return (_is_clickable);
}

void              arcade::DrawObject::setClickable(bool const value) {
  _is_clickable = value;
}

bool              arcade::DrawObject::isSelectable(void) const {
  return (_is_selectable);
}

void              arcade::DrawObject::setSelectable(bool const value) {
  _is_selectable = value;
}
