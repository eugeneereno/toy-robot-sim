#pragma once

namespace robot {

class Boundary {

public: 
  Boundary(int x, int y);
  ~Boundary() {};

  const int GetX() const;
  const int GetY() const;

  const bool IsWithinLimits(const int& x, const int& y) const;

private:
  int m_x;
  int m_y;
};

} // end namespace robot
