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
  Placement ret_val = placement;

  std::cout << placement.GetCoordinates().X() << ","
            << placement.GetCoordinates().Y() << ","
            << placement.GetDirection().ToString() << "\r\n";

  return ret_val;
}

} // end namespace robot