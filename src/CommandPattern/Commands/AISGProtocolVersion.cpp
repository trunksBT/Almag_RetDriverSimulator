#include <CommandPattern/Commands/AISGProtocolVersion.hpp>
#include <filesystem>

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

AISGProtocolVersion::AISGProtocolVersion(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(hdlcCommunicator, userInput)
{
   LOG(trace);
}

void AISGProtocolVersion::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr AISGProtocolVersion::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_AISGProtocolVersion();
}

void AISGProtocolVersion::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string AISGProtocolVersion::handleResponse()
{
   return constraints::almag::L2::AISG_PROTOCOL_VERSION + DELIMITER;
}

