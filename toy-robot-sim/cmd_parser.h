#pragma once

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "command.h"

namespace robot
{

using CommandFunc = std::function<void(std::shared_ptr<Command>&)>;

class CommandParser {
public:
  CommandParser(const CommandFunc& func);

  void Parse(const std::string& cmd);

  static void Split(const std::string& in, 
                    std::vector<std::string>& out,
                    const std::string& delims = " ,");

private:
  CommandFunc m_cb;
};

} // end namespace robot

