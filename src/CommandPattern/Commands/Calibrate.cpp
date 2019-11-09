#include <CommandPattern/Commands/Calibrate.hpp>
#include <filesystem>

#include <HDLC/FrameTypes/FrameI.hpp>
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

Calibrate::Calibrate(
   IHDLCCommunicator& hdlcCommunicator, Strings userInput)
   : ICommand(userInput, hdlcCommunicator)
{}

void Calibrate::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

void Calibrate::executeImpl()
{
   LOG(trace) << "BEGIN";
   const auto CalibratePrimFrame = FrameI()
      .setAddressByte(0x03)
      .setControlByte(BYTE_CONTROL::RETAP)
      .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   hdlcCommunicator_.send(validatedUserInput_[IDX_OF_ADDRESS], 
      std::make_shared<FrameI>(CalibratePrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string Calibrate::handleResponse()
{
   return L7::CALIBRATE + DELIMITER;
}

