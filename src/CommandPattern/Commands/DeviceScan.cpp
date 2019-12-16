#include <CommandPattern/Commands/DeviceScan.hpp>

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

DeviceScan::DeviceScan(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
        : HDLCCommand(hdlcCommunicator, userInput)
{
   LOG(trace);
}

void DeviceScan::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr DeviceScan::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameXID_DeviceScan();
}

void DeviceScan::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string DeviceScan::handleResponse()
{
   return constraints::almag::L2::DEVICE_SCAN + DELIMITER;
}

