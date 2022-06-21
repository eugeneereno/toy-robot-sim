#pragma once

namespace robot
{

class Coordinates {

public: 
  Coordinates();
  Coordinates(int x, int y);
  ~Coordinates() {};

  void Set(int x, int y);
  void SetX(int x);
  void SetY(int y);

  const int X() const;
  const int Y() const;

private:
  int m_x;
  int m_y;
};

} // end namespace robot

