#pragma once

#include <vector>
#include <string>
#include <CommandPattern/ICommand.hpp>

class ICommandFacade
{
   ICommand interprateAndCreateCommand(std::vector<std::string> validatedUserInput);
};
