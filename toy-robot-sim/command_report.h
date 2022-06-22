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

private:
  bool IsValid(const Placement& placement, const Boundary& boundary) const;
};

} // end namespace robot
