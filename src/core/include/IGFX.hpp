#ifndef _IGRAPHIC_HPP_
# define _IGRAPHIC_HPP_

# include <iostream>
# include <string>

# include "Protocol.hpp"
# include "Error.hpp"
# include "Input.hpp"

namespace arcade
{
  class IGraphic
  {
  public:
    virtual ~IGraphic(void) {}

    virtual void setTitleWindow(std::string const& title) = 0;
    virtual void setWindowSize(Vector2u const& size) = 0;
    virtual bool isOpen(void) const = 0;
    virtual void close(void) = 0;

    virtual InputT checkInput(void) = 0;

    virtual void clear(void) = 0;
    virtual void draw(Drawable const& drawable) = 0;
    virtual void display(void) = 0;
  };
}

#endif /* !_IGRAPHIC_HPP_ */
