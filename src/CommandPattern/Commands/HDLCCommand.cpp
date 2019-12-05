#include "HDLCCommand.hpp"
#include <Utils/Logger.hpp>
#include <HDLC/HDLCReqFrameBodyFactory.hpp>

namespace
{
constexpr unsigned IDX_OF_ADDRESS=1;
}

HDLCCommand::HDLCCommand(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
: hdlcCommunicator_(hdlcCommunicator)
, validatedUserInput_(userInput)
, hdlcFrameBodyFactory_(std::make_shared<HDLCReqFrameBodyFactory>())
{
   LOG(trace);
   hdlcCommunicator_->setupReceive(validatedUserInput_[IDX_OF_ADDRESS]);
   hdlcCommunicator_->setupSend(validatedUserInput_[IDX_OF_ADDRESS]);
}

HDLCCommand::~HDLCCommand()
{
   LOG(trace);
}
