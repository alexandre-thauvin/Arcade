//
// GFX.hpp for  in /home/aneopsy/cpp_arcade/src/core/include/
//
// Made by Paul THEIS
// Login   <theis_p@epitech.eu>
//
// Started on  Tue Mar 28 18:16:53 2017 Paul THEIS
// Last update Tue Mar 28 18:53:12 2017 Paul THEIS
//

#ifndef _GFX_HPP
# define _GFX_HPP

# include "IGFX.hpp"
# include <vector>

namespace                       arcade
{
  class                         GFX : public IGFX {
    public:
                                GFX(void);
      virtual                   ~GFX(void);
      virtual InputT            getInput(void);
      virtual void              setTitleWindow(std::string const &title);
      virtual void              setWindowSize(Vector2u const &size);
      virtual bool              isOpen(void) const;
      virtual void              close(void);
      virtual void              clear(void);
      // virtual void           draw(DrawObject const& drawObject);
      virtual void              display(void);
    private:
      std::map<int, InputT>     _input;
    };
}

#endif
