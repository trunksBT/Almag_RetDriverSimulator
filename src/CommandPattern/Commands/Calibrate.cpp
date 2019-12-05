#include <CommandPattern/Commands/Calibrate.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
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

Calibrate::Calibrate(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(hdlcCommunicator, userInput)
{
   LOG(trace);
}

void Calibrate::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr Calibrate::getFrameBody()
{
   const auto calibrateFrameBody = FrameI()
           .setAddressByte(0x03)
           .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);
   return std::make_shared<FrameI>(calibrateFrameBody);
}

void Calibrate::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string Calibrate::handleResponse()
{
   return constraints::almag::L7::CALIBRATE + DELIMITER;
}

