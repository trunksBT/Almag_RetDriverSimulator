#pragma once

#include <algorithm>
#include <Utils/TypeAliases.hpp>

namespace funs
{
inline bool anyOf(const Strings& supportedCommands, const std::string& zeroArgOfUserInput)
{
   return std::any_of(supportedCommands.begin(), supportedCommands.end(),
   [&zeroArgOfUserInput](auto command){ return command == zeroArgOfUserInput; });
}
}
