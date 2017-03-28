#ifndef _IBOX_HPP_
# define _IBOX_HPP_

# include <string>
# include <vector>

# include "IGFX.hpp"

namespace arcade
{
  class IBox
  {
  public:
    virtual ~IBox(void) {}
    virtual void draw(IGraphic *&graphic, bool const bright) = 0;
    virtual void setPosition(Vector2u const& pos) = 0;
    virtual void setSize(Vector2u const& size) = 0;
    virtual void setCharacterSize(size_t const size) = 0;
    virtual void setText(std::string const& text) = 0;
    virtual void setColor(RGBA const& rgba) = 0;

    virtual Vector2u getPosition(void) const = 0;
    virtual Vector2u getRPosition(void) const = 0;
    virtual Vector2u getSize(void) const = 0;
    virtual size_t getCharacterSize(void) const = 0;
    virtual std::string getText(void) const = 0;
    virtual RGBA getColor(void) const = 0;

    virtual bool isClickable(void) const = 0;
    virtual void setClickable(bool const value) = 0;
    virtual bool isSelectable(void) const = 0;
    virtual void setSelectable(bool const value) = 0;
  };
}

#endif /* !_IBOX_HPP_ */
