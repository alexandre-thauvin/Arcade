#ifndef CENTI_HPP_
# define CENTI_HPP_

#include "Personnage.hpp"

namespace arcade {
  class Centi : public Personnage {
  private:
    Direction	centiDir;
    Direction	lastDir;
  public:
    Centi(std::vector<Vector2u> const&, Direction);
    ~Centi() {}
    void	removeLastPos();
    void	removeMidPos(std::vector<Vector2u>::const_iterator const&);
    void	addFirstPos(Vector2u );
    Direction const& getLastDir() const;
    void	setLastDir(Direction const&);
    Direction const& getCentiDir() const;
    void	setCentiDir(Direction const&);
  };
}

#endif /* !CENTI_HPP_ */
