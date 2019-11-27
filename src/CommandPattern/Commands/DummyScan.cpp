#include <CommandPattern/Commands/DummyScan.hpp>

#include <chrono>
#include <thread>

#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace std::chrono_literals;
using namespace command;
using namespace funs;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

DummyScan::DummyScan(
   std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput, uint8_t numberOfExecutions)
   : ICommand(userInput, hdlcCommunicator)
   , numberOfExecutions_(numberOfExecutions)
{
   responseMessage_.reserve( 
      (constraints::almag::L1::DUMMY_SCAN + DELIMITER).size() * numberOfExecutions_);
}

void DummyScan::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

void DummyScan::executeImpl()
{
   LOG(trace) << "BEGIN";
   
   for (int i = 0; i<numberOfExecutions_; i++)
   {
      const auto dummyScanPrimFrame = FrameXID()
         .setAddressByte(ADDR_ALLSTATIONS)
         .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
         .setGroupIdentifierByte(GI::ADDR_ASSIGNMENT)
         .setGroupLengthByte(0x08)
         .addParameters(HDLCParameters::build(
            XID_PARAMS_ID::UNIQUE_ID,
            0x02,
            Hexes({ 0x33, 0x33 })))
         .addParameters(HDLCParameters::build(
            XID_PARAMS_ID::BIT_MASK,
            0x02,
            Hexes({ 0xFF, 0xFF })));

      hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
         std::make_shared<FrameXID>(dummyScanPrimFrame));

      responseMessage_ += constraints::almag::L1::DUMMY_SCAN + DELIMITER;

      if (numberOfExecutions_ > 1)
      {
         std::this_thread::sleep_for(300ms);
      }
      LOG(trace) << "===============================================";
      // I know what cpprefference says but we will see and conditionally fix it lazy
   }

   LOG(trace) << "END";
}

std::string DummyScan::handleResponse()
{
   return responseMessage_;
}
