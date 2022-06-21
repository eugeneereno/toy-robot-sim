#include "command_rotate.h"

#include "boundary.h"
#include "placement.h"

namespace robot
{

RotateCommand::RotateCommand(const Rotation& rotation) :
  Command(),
  m_rotation(rotation)
{}

const Placement RotateCommand::Run(const Placement& placement, const Boundary& boundary) {
  Direction new_direction(placement.GetDirection());

  switch (m_rotation.m_val) {
    case Rotation::RotationEnum::LEFT: {
      new_direction.TurnLeft();
      break;
    }
    case Rotation::RotationEnum::RIGHT: {
      new_direction.TurnRight();
      break;
    }
    default: {/*do nothing*/}
  };

  Placement ret_val = placement;
  ret_val.SetDirection(new_direction);

  return ret_val;
}

} // end namespace robot
