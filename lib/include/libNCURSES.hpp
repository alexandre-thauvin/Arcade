//
// libNCURSES.hpp for  in /home/cedric/workTek2/cpp_arcade/lib/src/NCURSES
// 
// Made by Cedric
// Login   <cedric.clemenceau@epitech.eu>
// 
// Started on  Thu Mar 30 18:29:04 2017 Cedric
// Last update Fri Mar 31 13:03:27 2017 Cedric
//

#ifndef LIBCURSE_HPP_
# define LIBCURSE_HPP_

# include <vector>
# include <map>
# include <ncurses.h>
# include <iostream>
# include "IGFX.hpp"

namespace                       arcade
{
  class                         GfxNCURSES : public IGFX {
    public:
                                GfxNCURSES(void);
      virtual                   ~GfxNCURSES(void);
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
      bool			_isOpen;
      WINDOW*			_mainWindow;
      int			_mainSizeX;
      int			_mainSizeY;
    };
}

#endif /* !LIBCURSE_HPP_ */
