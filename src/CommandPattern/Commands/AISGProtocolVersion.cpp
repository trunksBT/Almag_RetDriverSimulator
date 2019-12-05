#include <CommandPattern/Commands/AISGProtocolVersion.hpp>
#include <filesystem>

#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/HDLCFrameBody.hpp>
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

void AISGProtocolVersion::executeImpl()
{
   LOG(trace) << "BEGIN";

   const auto AISGProtocolVersionPrimFrame = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::AISG_PROTOCOL_VERSION,
         0x01,
         Hexes({ PV::AISG_2_0 })
      ));

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameXID>(AISGProtocolVersionPrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string AISGProtocolVersion::handleResponse()
{
   return constraints::almag::L2::AISG_PROTOCOL_VERSION + DELIMITER;
}

