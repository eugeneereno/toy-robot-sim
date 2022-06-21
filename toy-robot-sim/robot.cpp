#include "robot.h"

#include <iostream>

#include "command.h"

namespace robot
{

Robot::Robot(const Boundary& boundary) :
  m_boundary(boundary),
  m_placement()
{}

void Robot::Run(std::shared_ptr<Command>& command) {
  m_placement = command->Run(m_placement, m_boundary);
}

} // end namespace robot