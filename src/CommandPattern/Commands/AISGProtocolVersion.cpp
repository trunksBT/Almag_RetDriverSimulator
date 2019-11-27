#include <CommandPattern/Commands/AISGProtocolVersion.hpp>
#include <filesystem>

#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace funs;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

AISGProtocolVersion::AISGProtocolVersion(
        std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput)
   : ICommand(userInput, hdlcCommunicator)
{}

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
      .setGroupIdentifierByte(GI::ADDR_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::AISG_PROTOCOL_VERSION,
         0x01,
         Hexes({ static_cast<Hex>(PV::AISG_2_0) })
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

