#include "cmd_parser.h"

#include <iostream>
#include <string>
#include <vector>

#include "command_report.h"

namespace robot
{

CommandParser::CommandParser(const CommandFunc& func) :
  m_func(func)
{}

void CommandParser::Parse(const std::string& cmd) {
  std::shared_ptr<Command> report{ new ReportCommand() };
  m_func(report);
}

} // end namespace robot