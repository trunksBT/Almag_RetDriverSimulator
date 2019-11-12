#include <CommandPattern/Commands/ThreeGPPReleaseID.hpp>
#include <filesystem>

#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace funs;

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
      .setGroupIdentifierByte(GI::ADDR_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::THREEGPP_RELEASE_ID,
         0x01,
         Hexes({ static_cast<Hex>(PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE) })
      ));

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameXID>(ThreeGPPReleaseIDPrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string ThreeGPPReleaseID::handleResponse()
{
   return L2::THREEGPP_RELEASE_ID + DELIMITER;
}

