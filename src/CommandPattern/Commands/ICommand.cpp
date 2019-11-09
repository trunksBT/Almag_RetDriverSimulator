#include <CommandPattern/Commands/ICommand.hpp>

#include <HDLC/IHDLCCommunicator.hpp>

ICommand::ICommand(IHDLCCommunicator& hdlcCommunicator)
   : hdlcCommunicator_(hdlcCommunicator)
{}

ICommand::ICommand(Strings userInput, IHDLCCommunicator& hdlcCommunicator)
   : validatedUserInput_(userInput)
   , hdlcCommunicator_(hdlcCommunicator)
{}

void ICommand::registerResponseHandler(std::function<void(void)> responseHandler)
{
    informControllerAboutResult_.connect(responseHandler);
}

