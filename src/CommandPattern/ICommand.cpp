#include "CommandPattern/ICommand.hpp"

#include <HDLC/IHDLCCommunicator.hpp>

namespace
{
constexpr unsigned IDX_OF_ADDRESS=1;
}

ICommand::ICommand(std::shared_ptr<IHDLCCommunicator> hdlcCommunicator)
   : hdlcCommunicator_(hdlcCommunicator)
{}

ICommand::ICommand(Strings userInput, std::shared_ptr<IHDLCCommunicator> hdlcCommunicator)
   : validatedUserInput_(userInput)
   , hdlcCommunicator_(hdlcCommunicator)
{
   hdlcCommunicator_->setupReceive(validatedUserInput_[IDX_OF_ADDRESS]);
   hdlcCommunicator_->setupSend(validatedUserInput_[IDX_OF_ADDRESS]);
}

void ICommand::registerResponseHandler(std::function<void(void)> responseHandler)
{
    informControllerAboutResult_.connect(responseHandler);
}

