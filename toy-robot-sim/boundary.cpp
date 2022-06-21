#include "boundary.h"

namespace robot
{

const int VALID_MIN_VALUE = 0;

Boundary::Boundary(int x, int y) :
  m_x(x < VALID_MIN_VALUE ? VALID_MIN_VALUE : x),
  m_y(y < VALID_MIN_VALUE ? VALID_MIN_VALUE : y) 
{}

const int Boundary::GetX() const {
  return m_x;
}

const int Boundary::GetY() const {
  return m_y;
}

const bool Boundary::IsWithinLimits(const int& x, const int& y) const {
  return (VALID_MIN_VALUE <= x) &&
         (x <= m_x) &&
         (VALID_MIN_VALUE <= y) &&
         (y <= m_y);
}

} // end namespace robot
