#include "placement.h"

namespace robot
{

Placement::Placement() :
  m_coordinates(),
  m_direction()
{}

Placement::Placement(const Coordinates& coordinates, const Direction& direction) :
  m_coordinates(coordinates),
  m_direction(direction)
{}

const Coordinates Placement::GetCoordinates() const {
  return m_coordinates;
}

const Direction Placement::GetDirection() const {
  return m_direction;
}

void Placement::SetCoordinates(const Coordinates& coordinates) {
  m_coordinates = coordinates;
}

void Placement::SetDirection(const Direction& direction) {
  m_direction = direction;
}


} // end namespace robot