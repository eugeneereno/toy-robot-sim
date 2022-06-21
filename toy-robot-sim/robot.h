#pragma once

#include <memory>

#include "placement.h"
#include "boundary.h"

namespace robot
{

class Command;

class Robot {

public:
  Robot(const Boundary& boundary);
  ~Robot() {};

  void Run(std::shared_ptr<Command>& command);

private:
  Boundary m_boundary;
  Placement m_placement;
};

} // end namespace robot


