#include "pch.h"

#include <memory>

namespace robot 
{
namespace test
{
TEST_F(BoundaryTest, OnInitialize) {
  EXPECT_EQ(boundary->GetX(), 8);
  EXPECT_EQ(boundary->GetY(), 9);
}

TEST_F(BoundaryTest, OnLimitsSuccess) {
  EXPECT_TRUE(boundary->IsWithinLimits(TEST_X_VAL, TEST_Y_VAL));
  EXPECT_TRUE(boundary->IsWithinLimits(0, 0));
  EXPECT_TRUE(boundary->IsWithinLimits(TEST_X_VAL, 0));
  EXPECT_TRUE(boundary->IsWithinLimits(0, TEST_Y_VAL));
  EXPECT_TRUE(boundary->IsWithinLimits(4, 4));
}

TEST_F(BoundaryTest, OnLimitsFailure) {
  EXPECT_FALSE(boundary->IsWithinLimits(TEST_X_VAL + 1, TEST_Y_VAL + 1));
  EXPECT_FALSE(boundary->IsWithinLimits(TEST_X_VAL + 1, TEST_Y_VAL));
  EXPECT_FALSE(boundary->IsWithinLimits(-1, -1));
  EXPECT_FALSE(boundary->IsWithinLimits(-1, TEST_Y_VAL));
  EXPECT_FALSE(boundary->IsWithinLimits(TEST_X_VAL, -1));
  EXPECT_FALSE(boundary->IsWithinLimits(TEST_X_VAL + 1, 0));
  EXPECT_FALSE(boundary->IsWithinLimits(0, TEST_Y_VAL + 1));
}

const std::string INVALID_COMMAND = "invalid command";
const std::string NO_COMMAND = "";
const std::string PLACE_COMMAND = "PLACE 0,1,NORTH";
const std::string INVALID_PLACE_ARGS_OUT_OF_BOUNDS = "PLACE -1,-1,NORTH";
const std::string INVALID_PLACE_NON_DIGIT_ARGS = "PLACE a,b,NORTH";
const std::string INC_PLACE_COMMAND = "PLACE 1";
const std::string TOO_MANY_PLACE_ARGS = "PLACE 1,2,3,EAST";
const std::string MOVE_COMMAND = "MOVE";
const std::string LEFT_COMMAND = "LEFT";
const std::string RIGHT_COMMAND = "RIGHT";
const std::string REPORT_COMMAND = "REPORT";

const std::string PLACE_LOWER_COMMAND = "place 0,1, north";
const std::string MOVE_LOWER_COMMAND = "move";
const std::string LEFT_LOWER_COMMAND = "left";
const std::string RIGHT_LOWER_COMMAND = "right";
const std::string REPORT_LOWER_COMMAND = "report";

TEST_F(CommandParserTest, InvalidCommand) {
  parser->Parse(INVALID_COMMAND);
  EXPECT_FALSE(m_called);
}

TEST_F(CommandParserTest, NoCommand) {
  parser->Parse(NO_COMMAND);
  EXPECT_FALSE(m_called);
}

TEST_F(CommandParserTest, PlaceCommandSuccess) {
  parser->Parse(PLACE_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, InvalidPlaceArgsOutOfBounds) {
  parser->Parse(INVALID_PLACE_ARGS_OUT_OF_BOUNDS);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, InvalidPlaceNonDigitArgs) {
  parser->Parse(INVALID_PLACE_NON_DIGIT_ARGS);
  EXPECT_FALSE(m_called);
}

TEST_F(CommandParserTest, IncompletePlaceCommand) {
  parser->Parse(INC_PLACE_COMMAND);
  EXPECT_FALSE(m_called);
}

TEST_F(CommandParserTest, TooManyPlaceArgs) {
  parser->Parse(TOO_MANY_PLACE_ARGS);
  EXPECT_FALSE(m_called);
}

TEST_F(CommandParserTest, MoveCommandSuccess) {
  parser->Parse(MOVE_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, LeftCommandSuccess) {
  parser->Parse(LEFT_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, RightCommandSuccess) {
  parser->Parse(RIGHT_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, ReportCommandSuccess) {
  parser->Parse(REPORT_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, PlaceLowerCaseCommandSuccess) {
  parser->Parse(PLACE_LOWER_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, MoveLowerCaseCommandSuccess) {
  parser->Parse(MOVE_LOWER_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, LeftLowerCaseCommandSuccess) {
  parser->Parse(LEFT_LOWER_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, RightLowerCaseCommandSuccess) {
  parser->Parse(RIGHT_LOWER_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(CommandParserTest, ReportLowerCaseCommandSuccess) {
  parser->Parse(REPORT_LOWER_COMMAND);
  EXPECT_TRUE(m_called);
}

TEST_F(MoveCommandTest, MoveSuccess) {
  Coordinates expected_xy(0, 1);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::NORTH;

  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(MoveCommandTest, MoveSetInboundCoordinatesShouldIncrement) {
  placement.SetCoordinates(Coordinates(4, 4));

  Coordinates expected_xy(4, 5);
  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
}

TEST_F(MoveCommandTest, MoveGoingOutOfBoundsCoordinatesShouldStayTheSame) {
  placement.SetCoordinates(Coordinates(8, 9));

  Coordinates expected_xy(8, 9);
  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
}

TEST_F(MoveCommandTest, MoveSetValidDirectionShouldIncrement) {
  placement.SetDirection(Direction("EAST"));

  Coordinates expected_xy(1, 0);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::EAST;

  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(MoveCommandTest, MoveSetInvalidDirectionShouldStayTheSame) {
  placement.SetDirection(Direction("SOUTH"));

  Coordinates expected_xy(0, 0);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::SOUTH;

  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST(PlaceCommandTest, PlaceCommandValid) {
  Placement placement;
  placement.SetCoordinates(Coordinates(2, 4));
  placement.SetDirection(Direction("SOUTH"));

  Boundary boundary(TEST_X_VAL, TEST_Y_VAL);

  Coordinates expected_xy(2, 4);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::SOUTH;

  PlaceCommand cmd = PlaceCommand(placement);
  Placement new_placement = cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST(PlaceCommandTest, PlaceCommandInvalidDirection) {
  Placement placement;
  placement.SetCoordinates(Coordinates(2, 4));

  Boundary boundary(TEST_X_VAL, TEST_Y_VAL);

  Coordinates expected_xy(-1, -1);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::INVALID;

  PlaceCommand cmd = PlaceCommand(placement);
  Placement new_placement = cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST(PlaceCommandTest, PlaceCommandInvalidCoordinatesAboveBounds) {
  Placement placement;
  placement.SetCoordinates(Coordinates(12, 13));
  placement.SetDirection(Direction("SOUTH"));

  Boundary boundary(TEST_X_VAL, TEST_Y_VAL);

  Coordinates expected_xy(-1, -1);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::INVALID;

  PlaceCommand cmd = PlaceCommand(placement);
  Placement new_placement = cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST(PlaceCommandTest, PlaceCommandInvalidCoordinatesBelowBounds) {
  Placement placement;
  placement.SetCoordinates(Coordinates(-12, -13));
  placement.SetDirection(Direction("SOUTH"));

  Boundary boundary(TEST_X_VAL, TEST_Y_VAL);

  Coordinates expected_xy(-1, -1);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::INVALID;

  PlaceCommand cmd = PlaceCommand(placement);
  Placement new_placement = cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(RotateCommandTest, RotateLeft) {
  Coordinates expected_xy(0, 0);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::WEST;
  Placement new_placement = cmd->Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(RotateCommandTest, RotateRight) {
  Coordinates expected_xy(0, 0);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::EAST;

  rotation.m_val = Rotation::RotationEnum::RIGHT;
  RotateCommand rot_cmd = RotateCommand(rotation);
  Placement new_placement = rot_cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(RotateCommandTest, RotateInvalid) {
  Coordinates expected_xy(0, 0);
  Direction::DirectionEnum expected_dir = Direction::DirectionEnum::NORTH;

  rotation.m_val = Rotation::RotationEnum::INVALID;
  RotateCommand rot_cmd = RotateCommand(rotation);
  Placement new_placement = rot_cmd.Run(placement, boundary);

  EXPECT_EQ(expected_xy.X(), new_placement.GetCoordinates().X());
  EXPECT_EQ(expected_xy.Y(), new_placement.GetCoordinates().Y());
  EXPECT_EQ(expected_dir, new_placement.GetDirection().Value());
}

TEST_F(CoordinatesTest, DefaultInit) {
  EXPECT_EQ(-1, coordinates->X());
  EXPECT_EQ(-1, coordinates->Y());
}

TEST_F(CoordinatesTest, NonDefaultInit) {
  Coordinates xy = Coordinates(1, 2);
  EXPECT_EQ(1, xy.X());
  EXPECT_EQ(2, xy.Y());
}

TEST_F(CoordinatesTest, SetValueSingle) {
  coordinates->SetX(3);
  coordinates->SetY(1);

  EXPECT_EQ(3, coordinates->X());
  EXPECT_EQ(1, coordinates->Y());
}

TEST_F(CoordinatesTest, SetValuePair) {
  coordinates->Set(4, 2);

  EXPECT_EQ(4, coordinates->X());
  EXPECT_EQ(2, coordinates->Y());
}

TEST_F(DirectionTest, DefaultInit) {
  EXPECT_EQ(Direction::DirectionEnum::INVALID, direction->Value());
}

TEST_F(DirectionTest, NonDefaultInitEnum) {
  Direction dir(Direction::DirectionEnum::SOUTH);
  EXPECT_EQ(Direction::DirectionEnum::SOUTH, dir.Value());
}

TEST_F(DirectionTest, NonDefaultInitString) {
  Direction dir(std::string("WEST"));
  EXPECT_EQ(Direction::DirectionEnum::WEST, dir.Value());
}

TEST_F(DirectionTest, InvalidNonDefaultInitString) {
  Direction dir(std::string("SOUTHWEST"));
  EXPECT_EQ(Direction::DirectionEnum::INVALID, dir.Value());
}

TEST_F(DirectionTest, SetValue) {
  direction->Set(Direction::DirectionEnum::SOUTH);
  EXPECT_EQ(Direction::DirectionEnum::SOUTH, direction->Value());
}

TEST_F(DirectionTest, ToString) {
  EXPECT_EQ("INVALID", direction->ToString());

  direction->Set(Direction::DirectionEnum::NORTH);
  EXPECT_EQ("NORTH", direction->ToString());

  direction->Set(Direction::DirectionEnum::EAST);
  EXPECT_EQ("EAST", direction->ToString());

  direction->Set(Direction::DirectionEnum::WEST);
  EXPECT_EQ("WEST", direction->ToString());

  direction->Set(Direction::DirectionEnum::SOUTH);
  EXPECT_EQ("SOUTH", direction->ToString());
}

TEST_F(DirectionTest, TurnLeft) {
  direction->TurnLeft();
  EXPECT_EQ(Direction::DirectionEnum::INVALID, direction->Value());

  direction->Set(Direction::DirectionEnum::NORTH);
  direction->TurnLeft();
  EXPECT_EQ(Direction::DirectionEnum::WEST, direction->Value());

  direction->Set(Direction::DirectionEnum::EAST);
  direction->TurnLeft();
  EXPECT_EQ(Direction::DirectionEnum::NORTH, direction->Value());

  direction->Set(Direction::DirectionEnum::WEST);
  direction->TurnLeft();
  EXPECT_EQ(Direction::DirectionEnum::SOUTH, direction->Value());

  direction->Set(Direction::DirectionEnum::SOUTH);
  direction->TurnLeft();
  EXPECT_EQ(Direction::DirectionEnum::EAST, direction->Value());
}

TEST_F(DirectionTest, TurnRight) {
  direction->TurnRight();
  EXPECT_EQ(Direction::DirectionEnum::INVALID, direction->Value());

  direction->Set(Direction::DirectionEnum::NORTH);
  direction->TurnRight();
  EXPECT_EQ(Direction::DirectionEnum::EAST, direction->Value());

  direction->Set(Direction::DirectionEnum::EAST);
  direction->TurnRight();
  EXPECT_EQ(Direction::DirectionEnum::SOUTH, direction->Value());

  direction->Set(Direction::DirectionEnum::WEST);
  direction->TurnRight();
  EXPECT_EQ(Direction::DirectionEnum::NORTH, direction->Value());

  direction->Set(Direction::DirectionEnum::SOUTH);
  direction->TurnRight();
  EXPECT_EQ(Direction::DirectionEnum::WEST, direction->Value());
}

TEST_F(PlacementTest, DefaultInit) {
  EXPECT_EQ(Direction::DirectionEnum::INVALID, placement->GetDirection().Value());
  EXPECT_EQ(-1, placement->GetCoordinates().X());
  EXPECT_EQ(-1, placement->GetCoordinates().Y());
}

TEST_F(PlacementTest, NonDefaultInit) {
  Placement new_placement(Coordinates(1, 2), Direction("SOUTH"));

  EXPECT_EQ(Direction::DirectionEnum::SOUTH, new_placement.GetDirection().Value());
  EXPECT_EQ(1, new_placement.GetCoordinates().X());
  EXPECT_EQ(2, new_placement.GetCoordinates().Y());
}

TEST_F(PlacementTest, SetCoordinatesOnly) {
  placement->SetCoordinates(Coordinates(3, 4));
  EXPECT_EQ(Direction::DirectionEnum::INVALID, placement->GetDirection().Value());
  EXPECT_EQ(3, placement->GetCoordinates().X());
  EXPECT_EQ(4, placement->GetCoordinates().Y());
}

TEST_F(PlacementTest, SetDirectionOnly) {
  placement->SetDirection(Direction("SOUTH"));
  EXPECT_EQ(Direction::DirectionEnum::SOUTH, placement->GetDirection().Value());
  EXPECT_EQ(-1, placement->GetCoordinates().X());
  EXPECT_EQ(-1, placement->GetCoordinates().Y());
}

} // end namespace test
} // end namespace robot