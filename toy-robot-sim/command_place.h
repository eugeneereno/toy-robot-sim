#pragma once

#include "command.h"
#include "placement.h"

namespace robot
{

class Boundary;
class Placement;

class PlaceCommand : public Command {
public:
  PlaceCommand(const Placement& placement);
  virtual ~PlaceCommand() {};

  virtual const Placement Run(const Placement& placement, const Boundary& boundary);

private: 
  bool IsValid(const Boundary& boundary) const;
  Placement m_placement;
};

} // end namespace robot



