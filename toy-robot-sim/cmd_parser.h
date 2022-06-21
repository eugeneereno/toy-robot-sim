#pragma once

#include <functional>
#include <memory>
#include <string>

#include "command.h"

namespace robot
{

using CommandFunc = std::function<void(std::shared_ptr<Command>&)>;

class CommandParser {
public:
  CommandParser(const CommandFunc& func);

  void Parse(const std::string& cmd);

private:
  CommandFunc m_func;

};

} // end namespace robot

