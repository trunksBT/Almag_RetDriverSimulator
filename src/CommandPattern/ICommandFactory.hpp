#pragma once

#include <vector>
#include <string>
#include <CommandPattern/ICommand.hpp>

class IHDLCFrameBodyFactory
{
public:
   virtual ICommandPtr interpretAndCreateCommand(std::vector<std::string> validatedUserInput) = 0;
   virtual ~IHDLCFrameBodyFactory() = default;
};
