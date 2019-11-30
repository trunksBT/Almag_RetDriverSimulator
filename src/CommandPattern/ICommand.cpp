#include "CommandPattern/ICommand.hpp"

#include <HDLC/IHDLCCommunicator.hpp>

ICommand::ICommand(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator)
   : hdlcCommunicator_(hdlcCommunicator)
{}

ICommand::ICommand(Strings userInput, std::shared_ptr<IHDLCCommunicator> hdlcCommunicator)
   : validatedUserInput_(userInput)
   , hdlcCommunicator_(hdlcCommunicator)
{}

void ICommand::registerResponseHandler(std::function<void(void)> responseHandler)
{
    informControllerAboutResult_.connect(responseHandler);
}

