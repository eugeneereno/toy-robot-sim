#pragma once

#include "command.h"

namespace robot
{

class Boundary;
class Placement;

class ReportCommand : public Command {
public:
  ReportCommand();
  virtual ~ReportCommand() {};

  virtual const Placement Run(const Placement& placement, const Boundary& boundary);
};

} // end namespace robot
