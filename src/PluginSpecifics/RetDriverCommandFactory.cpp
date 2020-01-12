#include "RetDriverCommandFactory.hpp"
#include <Controller/Commands/AddressAssignment.hpp>
#include <Controller/Commands/AISGProtocolVersion.hpp>
#include <Controller/Commands/Calibrate.hpp>
#include <Controller/Commands/DeviceScan.hpp>
#include <Controller/Commands/DummyScan.hpp>
#include <Controller/Commands/HDLCParameters.hpp>
#include <Controller/Commands/LinkEstablishment.hpp>
#include <Controller/Commands/ThreeGPPReleaseID.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>
#include <Utils/Logger.hpp>

using namespace constraints::almag;

namespace
{
constexpr int DIRTY_HACK_FOR_NOT_FULLY_KNOWN_ZMQ = 1;
constexpr int IDX_OF_COMMAND_OR_ACTION_NAME = 0;
constexpr int IDX_OF_PUBLISH_SUBSCRIBE_COMMUNICATOR = 1;
constexpr int IDX_OF_REQUEST_RESPONSE_COMMUNICATOR = 0;
constexpr int NUMBER_FOR_SINGLE_DUMMY_SCAN = 1;
constexpr int NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS = 6;
}

RetDriverCommandFactory::RetDriverCommandFactory(std::vector<IHDLCCommunicatorPtr>& hdlcCommunicators)
   : ICommandFactory()
   , hdlcCommunicators_{hdlcCommunicators}
{
   LOG(trace);
}

RetDriverCommandFactory::~RetDriverCommandFactory()
{
   LOG(trace);
}

ICommandPtr RetDriverCommandFactory::interpretAndCreateCommand(std::vector<std::string> validatedInput)
{
   const auto& commandName = validatedInput[IDX_OF_COMMAND_OR_ACTION_NAME];

   if (L1::DUMMY_SCAN == commandName)
   {
      return std::make_shared<DummyScan>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR),
              validatedInput, (NUMBER_FOR_SINGLE_DUMMY_SCAN + DIRTY_HACK_FOR_NOT_FULLY_KNOWN_ZMQ));
   }
   else if (L1::SET_LINK_SPEED == commandName)
   {
      return std::make_shared<DummyScan>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_PUBLISH_SUBSCRIBE_COMMUNICATOR),
              validatedInput, NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS + DIRTY_HACK_FOR_NOT_FULLY_KNOWN_ZMQ);
   }
   else if (L2::DEVICE_SCAN == commandName)
   {
      return std::make_shared<DeviceScan>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L2::ADDRESS_ASSIGNMENT == commandName)
   {
      return std::make_shared<AddressAssignment>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L2::LINK_ESTABLISHMENT == commandName)
   {
      return std::make_shared<LinkEstablishment>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L2::HDLC_PARAMETERS == commandName)
   {
      return std::make_shared<HDLCParameters>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L2::THREEGPP_RELEASE_ID == commandName)
   {
      return std::make_shared<ThreeGPPReleaseID>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L2::AISG_PROTOCOL_VERSION == commandName)
   {
      return std::make_shared<AISGProtocolVersion>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else if (L7::CALIBRATE == commandName)
   {
      return std::make_shared<Calibrate>(std::make_shared<HDLCReqFrameBodyFactory>(),
              hdlcCommunicators_.at(IDX_OF_REQUEST_RESPONSE_COMMUNICATOR), validatedInput);
   }
   else
   {
      LOG(warning) << "Unknown command " << commandName;
      return {};
   }
}
