/* ************************************************************************** *
 *   Error.cpp
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 28/03/17                               #+#     #+#  #+#         *
 *   Updated: 28/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#include "Error.hpp"

arcade::ArcadeError::ArcadeError(std::string const &msg) throw()
{
  this->_msg = msg;
}

arcade::ArcadeError::~ArcadeError(void) throw() {}

const char              *arcade::ArcadeError::error(void) const throw()
{
  std::string           msg;

  msg = this->_msg;
  return (msg.data());
}
