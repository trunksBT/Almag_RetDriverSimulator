#include "RetDriverCommandFacade.hpp"
#include <CommandPattern/Commands/AISGProtocolVersion.hpp>
#include <CommandPattern/Commands/AddressAssignment.hpp>
#include <CommandPattern/Commands/Calibrate.hpp>
#include <CommandPattern/Commands/DummyScan.hpp>
#include <CommandPattern/Commands/LinkEstablishment.hpp>
#include <CommandPattern/Commands/StartPooling.hpp>
#include <CommandPattern/Commands/ThreeGPPReleaseID.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>

using namespace constraints::almag;

namespace
{
const std::string START_POOLING = "StartPooling";
constexpr int IDX_OF_COMMAND_OR_ACTION_NAME = 0;
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
constexpr uint8_t NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS = 6;
constexpr uint8_t NUMBER_OF_DUMMY_SCANS_FOR_SINGLE_COMMAND = 1;
}

RetDriverCommandFacade::RetDriverCommandFacade(std::vector<IHDLCCommunicatorPtr>& hdlcCommunicators)
   : ICommandFacade()
   , hdlcCommunicators_{hdlcCommunicators}
{}

ICommandPtr RetDriverCommandFacade::interpretAndCreateCommand(std::vector<std::string> validatedUserInput)
{
   const auto& commandName = validatedUserInput[IDX_OF_COMMAND_OR_ACTION_NAME];

   if (START_POOLING == commandName)
   {
      return std::make_shared<StartPooling>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR));
   }
   else if (L1::DUMMY_SCAN == commandName)
   {
      return std::make_shared<DummyScan>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR),
              validatedUserInput, NUMBER_OF_DUMMY_SCANS_FOR_SINGLE_COMMAND);
   }
   else if (L1::SET_LINK_SPEED == commandName)
   {
      return std::make_shared<DummyScan>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR),
              validatedUserInput, NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS);
   }
   else if (L2::ADDRESS_ASSIGNMENT == commandName)
   {
      return std::make_shared<AddressAssignment>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedUserInput);
   }
   else if (L2::LINK_ESTABLISHMENT == commandName)
   {
      return std::make_shared<LinkEstablishment>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedUserInput);
   }
   else if (L2::THREEGPP_RELEASE_ID == commandName)
   {
      return std::make_shared<ThreeGPPReleaseID>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedUserInput);
   }
   else if (L2::AISG_PROTOCOL_VERSION == commandName)
   {
      return std::make_shared<AISGProtocolVersion>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedUserInput);
   }
   else if (L7::CALIBRATE == commandName)
   {
      return std::make_shared<Calibrate>(
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedUserInput);
   }
   else
   {
      LOG(warning) << "Unknown command " << commandName;
      return {};
   }
}
