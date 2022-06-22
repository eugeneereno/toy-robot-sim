#include "command_report.h"

#include <iostream>

#include "boundary.h"
#include "placement.h"

namespace robot
{

ReportCommand::ReportCommand() :
  Command()
{}

const Placement ReportCommand::Run(const Placement& placement, const Boundary& boundary) {
  if (IsValid(placement, boundary)) {
    std::cout << placement.GetCoordinates().X() << ","
      << placement.GetCoordinates().Y() << ","
      << placement.GetDirection().ToString() << "\r\n";
  }

  Placement ret_val = placement;
  return ret_val;
}

bool ReportCommand::IsValid(const Placement& placement, const Boundary& boundary) const {
  return boundary.IsWithinLimits(placement.GetCoordinates().X(), placement.GetCoordinates().Y()) &&
         Direction::DirectionEnum::INVALID != placement.GetDirection().Value();;
}

} // end namespace robot
