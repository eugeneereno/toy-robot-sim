#pragma once

#include "coordinates.h"
#include "direction.h"

namespace robot
{

class Placement {

public :
  Placement();
  Placement(const Coordinates& coordinates, const Direction& direction);
  ~Placement() {};

  const Coordinates GetCoordinates() const;
  const Direction GetDirection() const;

  void SetCoordinates(const Coordinates& coordinates);
  void SetDirection(const Direction& direction);

private:
  Coordinates m_coordinates;
  Direction m_direction;
};

} // end namespace robot

