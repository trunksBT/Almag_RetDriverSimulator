#pragma once

#include <vector>
#include <string>
#include <CommandPattern/ICommand.hpp>

class ICommandFacade
{
public:
   virtual ICommandPtr interpretAndCreateCommand(std::vector<std::string> validatedUserInput) = 0;
   virtual ~ICommandFacade() = default;
};
