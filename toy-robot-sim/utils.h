#pragma once

#include <algorithm>
#include <string>

namespace utils
{

std::string ToUpper(std::string str) {
  std::transform(str.cbegin(), str.cend(), str.begin(),
    [](unsigned char c) {
      return std::toupper(c);
    });

  return str;
}

} // end namespace utils