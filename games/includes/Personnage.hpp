#ifndef PERSONNAGE_HPP_
# define PERSONNAGE_HPP_

# include "IGames.hpp"

namespace	arcade {
  enum	Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
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
