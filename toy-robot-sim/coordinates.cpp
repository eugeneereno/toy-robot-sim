#include "coordinates.h"

namespace robot
{

const int DEFAULT_VALUE = -1;

Coordinates::Coordinates() :
  m_x(DEFAULT_VALUE),
  m_y(DEFAULT_VALUE)
{}

Coordinates::Coordinates(int x, int y) :
  m_x(x),
  m_y(y)
{}

void Coordinates::Set(int x, int y) {
  m_x = x;
  m_y = y;
}

void Coordinates::SetX(int x) {
  m_x = x;
}

void Coordinates::SetY(int y) {
  m_y = y;
}

const int Coordinates::X() const {
  return m_x;
}

const int Coordinates::Y() const {
  return m_y;
}

} // end namespace robot