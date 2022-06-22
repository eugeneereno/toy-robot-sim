#include "cmd_parser.h"

#include <iostream>
#include <string>

#include "command_move.h"
#include "command_place.h"
#include "command_report.h"
#include "command_rotate.h"

#include "utils.h"

namespace robot
{

const int MAX_ARGS_SIZE = 4;

CommandParser::CommandParser(const CommandFunc& func) :
  m_cb(func)
{}

void CommandParser::Parse(const std::string& cmd) {
  std::vector<std::string> args;
  Split(cmd, args);

  if (args.empty() || args.size() > MAX_ARGS_SIZE || !m_cb) return;

  std::string token = utils::ToUpper(args.front());

  if ("PLACE" == token && MAX_ARGS_SIZE == args.size()) {
    try {
      Placement placement;
      placement.SetCoordinates(Coordinates(std::stoi(args.at(1)), std::stoi(args.at(2))));
      placement.SetDirection(Direction(utils::ToUpper(args.at(3))));

      std::shared_ptr<Command> place{ new PlaceCommand(placement) };
      m_cb(place);
    }
    catch (std::invalid_argument& ex) {
      std::cout << " --- INVALID ARGS : " << ex.what() << std::endl;
    }
  }
  else if ("MOVE" == token) {
    std::shared_ptr<Command> move{ new MoveCommand() };
    m_cb(move);
  }
  else if ("LEFT" == token) {
    Rotation rotation;
    rotation.m_val = Rotation::RotationEnum::LEFT;

    std::shared_ptr<Command> rotate{ new RotateCommand(rotation) };
    m_cb(rotate);
  }
  else if ("RIGHT" == token) {
    Rotation rotation;
    rotation.m_val = Rotation::RotationEnum::RIGHT;

    std::shared_ptr<Command> rotate{ new RotateCommand(rotation) };
    m_cb(rotate);
  }
  else if ("REPORT" == token) {
    std::shared_ptr<Command> report{ new ReportCommand() };
    m_cb(report);
  }
  else { 
    std::cout << " --- INVALID COMMAND : " << cmd << std::endl;
  }
}

void CommandParser::Split(
  const std::string& in, 
  std::vector<std::string>& out,
  const std::string& delims) {

  size_t begin, pos = 0;
  while (std::string::npos != (begin = in.find_first_not_of(delims, pos))) {
    pos = in.find_first_of(delims, begin + 1);
    out.push_back(in.substr(begin, pos - begin));
  }
}

} // end namespace robot