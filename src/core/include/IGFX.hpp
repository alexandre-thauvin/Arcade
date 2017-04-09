/* ************************************************************************** *
 *
 *                                                       :::      ::::::::    *
 *                                                     :+: :+:    :+:    :+:  *
 *                                                    +:+   +:+   +:+    +:+  *
 *   By: THEIS Paul                                  +#++:++#++:  +#++:++#+   *
 *                                                   +#+     +#+  +#+         *
 *   Created: 20/03/17                               #+#     #+#  #+#         *
 *   Updated: 20/03/17                               #+#     #+#  #+#         *
 *   Project: cpp_arcade
 * ************************************************************************** */

#ifndef _IGFX_HPP_
# define _IGFX_HPP_

# include <iostream>
# include <string>
# include <stdlib.h>

# include "Error.hpp"
# include "Input.hpp"
# include "Utils.hpp"
# include "DrawObject.hpp"

class DrawObject;
namespace                       arcade {
  class                         IGFX {
      public:
        virtual                 ~IGFX(void) {}

        virtual void            setTitleWindow(std::string const& title) = 0;
        virtual void            setWindowSize(Vector2u const &size) = 0;
        virtual bool            isOpen(void) const = 0;
        virtual void            close(void) = 0;

        virtual InputT          getInput(void) = 0;

        virtual void            clear(void) = 0;
         virtual void           draw(DrawObject const &drawObject) = 0;
        virtual void            display(void) = 0;
      };
}

#endif /* !_IGRAPHIC_HPP_ */
