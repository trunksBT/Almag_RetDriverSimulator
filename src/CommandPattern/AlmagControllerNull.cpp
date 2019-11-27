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

bool AlmagControllerNull::executeCommand()
{
   LOG(debug);
   return true;
}

void AlmagControllerNull::handleCommandsResult()
{
   LOG(debug);
}

std::string AlmagControllerNull::getFinalResultCode()
{
   return defaultVals::FOR_STRING;
}
