#include "command_move.h"

#include "boundary.h"
#include "direction.h"
#include "placement.h"

namespace robot
{

MoveCommand::MoveCommand() :
  Command()
{}

const Placement MoveCommand::Run(const Placement& placement, const Boundary& boundary) {
  Coordinates new_coordinates = placement.GetCoordinates();

  switch (placement.GetDirection().Value()) {
    case Direction::DirectionEnum::NORTH: {
      new_coordinates.SetY(new_coordinates.Y() + 1);
      break;
    }
    case Direction::DirectionEnum::SOUTH: {
      new_coordinates.SetY(new_coordinates.Y() - 1);
      break;
    }
    case Direction::DirectionEnum::EAST: {
      new_coordinates.SetX(new_coordinates.X() + 1);
      break;
    }
    case Direction::DirectionEnum::WEST: {
      new_coordinates.SetX(new_coordinates.X() - 1);
      break;
    }
    default: {/*do nothing*/}                          
  }
  
  Placement ret_val = placement;

  if (boundary.IsWithinLimits(new_coordinates.X(), new_coordinates.Y()))
    ret_val.SetCoordinates(new_coordinates);

  return ret_val;
}

} // end namespace robot
