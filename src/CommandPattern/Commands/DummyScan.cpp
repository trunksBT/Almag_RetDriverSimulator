#include <CommandPattern/Commands/DummyScan.hpp>

#include <chrono>
#include <thread>

#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace std::chrono_literals;
using namespace command;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

DummyScan::DummyScan(
   IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput, uint8_t numberOfExecutions)
   : HDLCCommand(hdlcCommunicator, userInput)
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

HDLCFrameBodyPtr DummyScan::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_DummyScan();
}

void DummyScan::executeImpl()
{
   LOG(trace) << "BEGIN";
   
   for (int i = 0; i<numberOfExecutions_; i++)
   {
      hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                              getFrameBody());

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
