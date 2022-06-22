//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

#include "../toy-robot-sim/boundary.h"
#include "../toy-robot-sim/cmd_parser.h"
#include "../toy-robot-sim/command_move.h"
#include "../toy-robot-sim/command_place.h"
#include "../toy-robot-sim/command_rotate.h"
#include "../toy-robot-sim/coordinates.h"
#include "../toy-robot-sim/direction.h"
#include "../toy-robot-sim/placement.h"

namespace robot
{
namespace test
{

const int TEST_X_VAL = 8;
const int TEST_Y_VAL = 9;

class BoundaryTest : public ::testing::Test {
protected:
  BoundaryTest() :
    boundary(std::make_unique<Boundary>(TEST_X_VAL, TEST_Y_VAL))
  {}

  ~BoundaryTest() override {}

  std::unique_ptr<Boundary> boundary;
};

class CommandParserTest : public ::testing::Test {
protected:
  CommandParserTest() :
    m_called(false) 
  {
    auto func = [&](std::shared_ptr<Command>& cmd) {
      Run(cmd);
    };

    parser = std::make_unique<CommandParser>(func);
  }

  ~CommandParserTest() override {}

  void Run(std::shared_ptr<Command> cmd) {
    m_called = true;
  }

  bool m_called;
  std::unique_ptr<CommandParser> parser;
};

class MoveCommandTest : public ::testing::Test {
protected:
  MoveCommandTest() : 
    placement(Coordinates(0,0), Direction(Direction::DirectionEnum::NORTH)),
    boundary(TEST_X_VAL, TEST_Y_VAL),
    cmd(std::make_unique<MoveCommand>())
  {}

  ~MoveCommandTest() override {};

  Placement placement;
  Boundary boundary;
  
  std::unique_ptr<MoveCommand> cmd;
};

class RotateCommandTest : public ::testing::Test {
protected:
  RotateCommandTest() :
    placement(Coordinates(0, 0), Direction("NORTH")),
    boundary(TEST_X_VAL, TEST_Y_VAL)
  {
    rotation.m_val = Rotation::RotationEnum::LEFT;
    cmd = std::make_unique<RotateCommand>(rotation);
  }

  ~RotateCommandTest() override {};

  Placement placement;
  Boundary boundary;
  Rotation rotation;

  std::unique_ptr<RotateCommand> cmd;
};

class CoordinatesTest : public ::testing::Test {
protected:
  CoordinatesTest() :
    coordinates(std::make_unique<Coordinates>())
  {}

  ~CoordinatesTest() override {}

  std::unique_ptr<Coordinates> coordinates;
};

class DirectionTest : public ::testing::Test {
protected:
  DirectionTest() :
    direction(std::make_unique<Direction>())
  {}

  ~DirectionTest() override {}

  std::unique_ptr<Direction> direction;
};

class PlacementTest : public ::testing::Test {
protected:
  PlacementTest() :
    placement(std::make_unique<Placement>())
  {}

  ~PlacementTest() override {}

  std::unique_ptr<Placement> placement;
};

} // end namespace test
} // end namespace robot
