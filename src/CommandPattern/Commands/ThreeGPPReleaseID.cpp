#include "CommandPattern/Commands/ThreeGPPReleaseID.hpp"
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

ThreeGPPReleaseID::ThreeGPPReleaseID(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(hdlcCommunicator, userInput)
{
   LOG(trace);
}

void ThreeGPPReleaseID::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr ThreeGPPReleaseID::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_3GPPReleaseId();
}

void ThreeGPPReleaseID::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string ThreeGPPReleaseID::handleResponse()
{
   return constraints::almag::L2::THREEGPP_RELEASE_ID + DELIMITER;
}
