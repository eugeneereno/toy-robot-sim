#include "command_place.h"

#include "boundary.h"

namespace robot
{

PlaceCommand::PlaceCommand(const Placement& placement) :
  Command(),
  m_placement(placement)
{}

const Placement PlaceCommand::Run(const Placement& placement, const Boundary& boundary) {  
  if (IsValid(boundary))
    return m_placement;

  return Placement();
}

bool PlaceCommand::IsValid(const Boundary& boundary) const {
  return boundary.IsWithinLimits(m_placement.GetCoordinates().X(), m_placement.GetCoordinates().Y()) &&
         Direction::DirectionEnum::INVALID != m_placement.GetDirection().Value();
}

} // end namespace robot