#include "CommandPattern/AlmagController.hpp"

#include <CommandPattern/ICommand.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;
using namespace constraints::almag;

AlmagController::AlmagController(Database& db, std::shared_ptr<ICommandFacade> commandFacade)
    : db_(db)
    , commandFacade_(commandFacade)
    , finalResultCode_("")
{
    LOG(debug);
}

AlmagController::~AlmagController()
{
    LOG(debug);
}

std::string AlmagController::getFinalResultCode()
{
   return finalResultCode_;
}

void AlmagController::addCommand(Strings validatedUserInput)
{
   LOG(debug);
   std::shared_ptr<ICommand> receivedCmd = commandFacade_->interpretAndCreateCommand(validatedUserInput);

   if (receivedCmd)
   {
      addCommands({receivedCmd});
   }
}

void AlmagController::addCommands(StringsMatrix validatedUserInputs)
{
   for (const auto& validatedUserInput : validatedUserInputs)
   {
      addCommand(validatedUserInput);
   }
}

void AlmagController::addCommands(std::vector<std::shared_ptr<ICommand>> inCommands)
{
    for (const auto& inCommand : inCommands)
    {
        inCommand->registerResponseHandler([&](){
            this->handleCommandsResult();
        });
        commands_.push_back(inCommand);
    }
}

bool AlmagController::executeCommand()
{
    LOG(debug);
    if (not commands_.empty())
    {
        commands_.front()->execute();
    }
    return true;
}

void AlmagController::executeNextCommand()
{
   if (not commands_.empty())
   {
      commands_.pop_front();
      LOG(debug) << "Number of commands on queue " << commands_.size();
      executeCommand();    
   }
}

void AlmagController::handleCommandsResult()
{
    if (not commands_.empty())
    {
        const std::shared_ptr<ICommand> currentCommand = commands_.front();
        finalResultCode_ += currentCommand->handleResponse();
        executeNextCommand();
    }
}
