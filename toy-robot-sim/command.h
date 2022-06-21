#pragma once

namespace robot
{

class Boundary;
class Placement;

class Command {

public: 
  Command() {};
  virtual ~Command() {};

  virtual const Placement Run(const Placement& placement, const Boundary& table) = 0;
};

} // end namespace robot