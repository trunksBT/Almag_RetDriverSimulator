#include "CommandPattern/Commands/ThreeGPPReleaseID.hpp"
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

ThreeGPPReleaseID::ThreeGPPReleaseID(
   std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput)
   : ICommand(userInput, hdlcCommunicator)
{}

void ThreeGPPReleaseID::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

void ThreeGPPReleaseID::executeImpl()
{
   LOG(trace) << "BEGIN";

   const auto ThreeGPPReleaseIDPrimFrame = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::THREEGPP_RELEASE_ID,
         0x01,
         Hexes({ PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE })
      ));

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameXID>(ThreeGPPReleaseIDPrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string ThreeGPPReleaseID::handleResponse()
{
   return constraints::almag::L2::THREEGPP_RELEASE_ID + DELIMITER;
}
