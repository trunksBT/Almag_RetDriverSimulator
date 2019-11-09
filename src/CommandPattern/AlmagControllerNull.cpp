#include "CommandPattern/AlmagControllerNull.hpp"

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

AlmagControllerNull::AlmagControllerNull()
{
   LOG(debug);
}

AlmagControllerNull::~AlmagControllerNull()
{
   LOG(debug);
}

void AlmagControllerNull::addCommands(StringsMatrix validatedUserInput)
{
   LOG(debug);
}

void AlmagControllerNull::executeCommand()
{
   LOG(debug);
}

void AlmagControllerNull::handleCommandsResult()
{
   LOG(debug);
}

std::string AlmagControllerNull::getFinalResultCode()
{
   return defaultVals::FOR_STRING;
}

