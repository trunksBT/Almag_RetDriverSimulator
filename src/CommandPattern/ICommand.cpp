#include "CommandPattern/ICommand.hpp"

#include <HDLC/IHDLCCommunicator.hpp>

void ICommand::registerResponseHandler(std::function<void(void)> responseHandler)
{
    informControllerAboutResult_.connect(responseHandler);
}
