#include "direction.h"

namespace robot
{

Direction::Direction() :
  m_val(DirectionEnum::INVALID)
{}

Direction::Direction(const DirectionEnum& val) :
  m_val(val)
{}

Direction::Direction(const std::string& str) {
  if (ToString(DirectionEnum::NORTH) == str)
    m_val = DirectionEnum::NORTH;
  else if (ToString(DirectionEnum::EAST) == str)
    m_val = DirectionEnum::EAST;
  else if (ToString(DirectionEnum::WEST) == str)
    m_val = DirectionEnum::WEST;
  else if (ToString(DirectionEnum::SOUTH) == str)
    m_val = DirectionEnum::SOUTH;
  else m_val = DirectionEnum::INVALID;
}

void Direction::TurnLeft() {
  switch (m_val) {
    case DirectionEnum::NORTH: {
      m_val = DirectionEnum::WEST;
      break;
    }
    case DirectionEnum::EAST: {
      m_val = DirectionEnum::NORTH;
      break;
    }
    case DirectionEnum::WEST: {
      m_val = DirectionEnum::SOUTH;
      break;
    }
    case DirectionEnum::SOUTH: {
      m_val = DirectionEnum::EAST;
      break;
    }
    default: { /*do nothing*/ }
  }
}

void Direction::TurnRight() {
  switch (m_val) {
    case DirectionEnum::NORTH: {
      m_val = DirectionEnum::EAST;
      break;
    }
    case DirectionEnum::EAST: {
      m_val = DirectionEnum::SOUTH;
      break;
    }
    case DirectionEnum::WEST: {
      m_val = DirectionEnum::NORTH;
      break;
    }
    case DirectionEnum::SOUTH: {
      m_val = DirectionEnum::WEST;
      break;
    }
    default: { /*do nothing*/ }
  }
}

const Direction::DirectionEnum Direction::Value() const {
  return m_val;
}

void Direction::Set(const DirectionEnum& val) {
  m_val = val;
}

const std::string Direction::ToString() const {
  return ToString(m_val);
}

const std::string Direction::ToString(const DirectionEnum& val) {
  switch (val) {
    case DirectionEnum::NORTH:
      return "NORTH";
    case DirectionEnum::EAST:
      return "EAST";
    case DirectionEnum::WEST:
      return "WEST";
    case DirectionEnum::SOUTH:
      return "SOUTH";
    default:
      return "INVALID";
  }
}

} // end namespace robot