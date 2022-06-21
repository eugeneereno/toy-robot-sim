#pragma once

#include <string>

namespace robot
{

struct Rotation {
  enum class RotationEnum {
    LEFT,
    RIGHT,
    INVALID
  };

  const std::string ToString() const {
    return ToString(m_val);
  };

  static const std::string ToString(const RotationEnum& val) {
    switch (val) {
      case RotationEnum::LEFT:
        return "LEFT";
      case RotationEnum::RIGHT:
        return "RIGHT";
      default:
        return "INVALID";
    }
  }

  RotationEnum m_val{RotationEnum::INVALID};
};

} // end namespace robot