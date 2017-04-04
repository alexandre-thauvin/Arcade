#ifndef PERSONNAGE_HPP_
# define PERSONNAGE_HPP_

# include "IGame.hpp"

namespace	arcade {
  enum	Direction {
    D_UP,
    D_DOWN,
    D_LEFT,
    D_RIGHT
  };
  class Personnage {
    Direction			_dir;
    std::vector<Vector2u>	_pos;
  public:
    Personnage();
    ~Personnage(){};
    void	goUp();
    void	goDown();
    void	goLeft();
    void	goRight();
    void	setPos(std::vector<Vector2u> const&);
    std::vector<Vector2u> const&	getPos() const;
  };
}

#endif /* !PERSONNAGE_HPP_ */
