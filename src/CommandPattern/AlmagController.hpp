#pragma once

#include <list>
#include <memory>
#include <vector>
#include <boost/optional.hpp>

#include <Database/Database.hpp>
#include <CommandPattern/IAlmagController.hpp>
#include <CommandPattern/ICommand.hpp>
#include <CommandPattern/ICommandFacade.hpp>

#include <Utils/TypeAliases.hpp>

/*
 * This class by design accepts only validated userInput
 */

class IHDLCCommunicator;

class AlmagController final: public IAlmagController
{
public:
   AlmagController(Database& db, std::shared_ptr<ICommandFacade> commandFacade);
   virtual ~AlmagController();

   void addCommands(StringsMatrix validatedUserInput) final override;
   bool executeCommand() final override;
   void handleCommandsResult() final override;
   std::string getFinalResultCode() final override;

private:
   void addCommands(std::vector<std::shared_ptr<ICommand>> inCommand);
   void addCommand(Strings validatedUserInput);

   void executeNextCommand();

   Database& db_;
   std::shared_ptr<ICommandFacade> commandFacade_;
   std::list<std::shared_ptr<ICommand>> commands_;
   std::string finalResultCode_;
};

using AlmagControllerPtr = std::shared_ptr<AlmagController>;
