#pragma once

#include "command.h"
#include "rotation.h"

namespace robot
{

class Boundary;
class Placement;

class RotateCommand : public Command {
public:
  RotateCommand(const Rotation& rotation);
  virtual ~RotateCommand() {};

  virtual const Placement Run(const Placement& placement, const Boundary& boundary);

private:
  Rotation m_rotation;
};

} // end namespace robot
