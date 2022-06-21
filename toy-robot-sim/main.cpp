#include <iostream>
#include <string>

#include "boundary.h"
#include "cmd_parser.h" 
#include "command.h"
#include "robot.h"

const int DEFAULT_WIDTH = 5;
const int DEFAULT_HEIGHT = 5;

int main(int argc, char* argv[]) {
  robot::Boundary boundary = robot::Boundary(DEFAULT_WIDTH - 1, DEFAULT_HEIGHT - 1);
  robot::Robot robot = robot::Robot(boundary);

  auto func = [&](std::shared_ptr<robot::Command>& cmd) {
    robot.Run(cmd);
  };

  robot::CommandParser parser = robot::CommandParser(func);

  while (true) {
    std::string cmd;
    std::getline(std::cin, cmd);

    if (cmd.empty()) break;

    parser.Parse(cmd);
  }

  return 0;
}
