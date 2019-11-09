#pragma once

#include <memory>
#include <Utils/TypeAliases.hpp>

class IAlmagController
{
public:
   virtual ~IAlmagController() = default;

   virtual void addCommands(StringsMatrix validatedUserInput) = 0;
   virtual void executeCommand() = 0;
   virtual void handleCommandsResult() = 0;
   virtual std::string getFinalResultCode() = 0;
};

using IAlmagControllerPtr = std::shared_ptr<IAlmagController>;

