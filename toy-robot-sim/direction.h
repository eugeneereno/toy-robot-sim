#pragma once

#include <string>

namespace robot
{

class Direction {

public:
  enum class DirectionEnum {
    NORTH,
    EAST,
    WEST,
    SOUTH,
    INVALID
  };

  Direction();
  Direction(const std::string& val);
  Direction(const DirectionEnum& val);
  ~Direction() {};

  void TurnLeft();
  void TurnRight();
  void Set(const DirectionEnum& val);
  const DirectionEnum Value() const;

  const std::string ToString() const;

  static const std::string ToString(const DirectionEnum& val);

private:
  DirectionEnum m_val;
};
  
} // end namespace robot
