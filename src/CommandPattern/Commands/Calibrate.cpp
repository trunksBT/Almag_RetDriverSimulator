#include <CommandPattern/Commands/Calibrate.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/IHDLCCommunicator.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace command;
using namespace funs;

namespace
{
constexpr int IDX_OF_ADDRESS = 1;
}

Calibrate::Calibrate(
        std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput)
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
      .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameI>(CalibratePrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string Calibrate::handleResponse()
{
   return constraints::almag::L7::CALIBRATE + DELIMITER;
}

