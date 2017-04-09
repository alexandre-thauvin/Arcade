
#ifndef LIBLAPIN_HPP_
# define LIBLAPIN_HPP_

# include <vector>
# include <map>
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <lapin.h>
# include "IGFX.hpp"

namespace                       arcade
{
    class                         GfxLAPIN : public IGFX {
    public:
                                GfxLAPIN(Vector2u const& dim);
      virtual                   ~GfxLAPIN(void);
      virtual InputT            getInput(void);
      virtual void              setTitleWindow(std::string const &title);
      virtual void              setWindowSize(Vector2u const &dim);
      virtual bool              isOpen(void) const;
      virtual void              close(void);
      virtual void              clear(void);
      virtual void              draw(DrawObject const &drawObject);
      virtual void              display(void);
        void	setLastKey(char c);
    private:
      std::map<int, InputT>     _input;
      bool			            _isOpen;
        t_bunny_window		*_window;
        t_bunny_pixelarray		*_screen;
        char	_lastKey;
      Vector2u                  _mainSize;
    };
}

#endif /* !LIBSDL_HPP_ */
