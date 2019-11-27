#include "CommandPattern/AlmagController.hpp"

#include <CommandPattern/Commands/AISGProtocolVersion.hpp>
#include <CommandPattern/Commands/AddressAssignment.hpp>
#include <CommandPattern/Commands/Calibrate.hpp>
#include <CommandPattern/Commands/DummyScan.hpp>
#include <CommandPattern/Commands/LinkEstablishment.hpp>
#include <CommandPattern/Commands/StartPooling.hpp>
#include <CommandPattern/Commands/ThreeGPPReleaseID.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <HDLC/IHDLCCommunicator.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace defaultVals;
using namespace constraints::almag;

AlmagController::AlmagController(Database& db, std::shared_ptr<IHDLCCommunicator> hdlcCommunicator)
    : db_(db)
    , hdlcCommunicator_(hdlcCommunicator)
    , finalResultCode_("")
{
    LOG(debug);
}

AlmagController::~AlmagController()
{
    LOG(debug);
}

std::string AlmagController::getFinalResultCode()
{
   return finalResultCode_;
}

void AlmagController::addCommand(Strings validatedUserInput)
{
   LOG(debug);
   std::shared_ptr<ICommand> receivedFromUserCommand;
   const auto& commandName = validatedUserInput[idx::COMMAND_OR_ACTION_NAME];

   if (START_POOLING == commandName)
   {
      receivedFromUserCommand = std::make_shared<StartPooling>(hdlcCommunicator_);
   }
   else if (L1::DUMMY_SCAN == commandName)
   {
      receivedFromUserCommand =
         std::make_shared<DummyScan>(hdlcCommunicator_, validatedUserInput, ONE);
   }
   else if (L1::SET_LINK_SPEED == commandName)
   {
      receivedFromUserCommand =
         std::make_shared<DummyScan>(
            hdlcCommunicator_, validatedUserInput, NUMBER_OF_DUMMY_SCANS_FOR_9_6_KBPS);
   }
   else if (L2::ADDRESS_ASSIGNMENT == commandName)
   {
      receivedFromUserCommand =
         std::make_shared<AddressAssignment>(hdlcCommunicator_, validatedUserInput);
   }
   else if (L2::LINK_ESTABLISHMENT == commandName)
   {
      receivedFromUserCommand = 
         std::make_shared<LinkEstablishment>(hdlcCommunicator_, validatedUserInput);
   }
   else if (L2::THREEGPP_RELEASE_ID == commandName)
   {
      receivedFromUserCommand = 
         std::make_shared<ThreeGPPReleaseID>(hdlcCommunicator_, validatedUserInput);
   }
   else if (L2::AISG_PROTOCOL_VERSION == commandName)
   {
      receivedFromUserCommand = 
         std::make_shared<AISGProtocolVersion>(hdlcCommunicator_, validatedUserInput);
   }
   else if (L7::CALIBRATE == commandName)
   {
      receivedFromUserCommand =
         std::make_shared<Calibrate>(hdlcCommunicator_, validatedUserInput);
   }
   else
   {
      LOG(warning) << "Unknown command " << commandName;
   }

   if (receivedFromUserCommand)
   {
      addCommands({ receivedFromUserCommand });
   }
}

void AlmagController::addCommands(StringsMatrix validatedUserInputs)
{
   for (const auto& validatedUserInput : validatedUserInputs)
   {
      addCommand(validatedUserInput);
   }
}

void AlmagController::addCommands(std::vector<std::shared_ptr<ICommand>> inCommands)
{
    for (const auto& inCommand : inCommands)
    {
        inCommand->registerResponseHandler([&](){
            this->handleCommandsResult();
        });
        commands_.push_back(inCommand);
    }
}

bool AlmagController::executeCommand()
{
    LOG(debug);
    if (not commands_.empty())
    {
        commands_.front()->execute();
    }
    return true;
}

void AlmagController::executeNextCommand()
{
   if (not commands_.empty())
   {
      commands_.pop_front();
      LOG(debug) << "Number of commands on queue " << commands_.size();
      executeCommand();    
   }
}

void AlmagController::handleCommandsResult()
{
    if (not commands_.empty())
    {
        const std::shared_ptr<ICommand> currentCommand = commands_.front();
        finalResultCode_ += currentCommand->handleResponse();

        executeNextCommand();
    }
}
