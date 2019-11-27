#pragma once

#include <CommandPattern/IAlmagController.hpp>

class AlmagControllerNull : public IAlmagController
{
public:
   AlmagControllerNull();
   virtual ~AlmagControllerNull();

   void addCommands(StringsMatrix validatedUserInput) final override;
   bool executeCommand() final override;
   void handleCommandsResult() final override;
   std::string getFinalResultCode() final override;
};

