#pragma once

#include "command.h"

namespace robot
{

class Boundary;
class Placement;

class MoveCommand : public Command {
public:
  MoveCommand();
  virtual ~MoveCommand() {};

  virtual const Placement Run(const Placement& placement, const Boundary& boundary);
};

} // end namespace robot
