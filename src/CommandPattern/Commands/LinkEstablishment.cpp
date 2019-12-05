#include "CommandPattern/Commands/LinkEstablishment.hpp"
#include <HDLC/FrameTypes/FrameSNRM.hpp>
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

LinkEstablishment::LinkEstablishment(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(hdlcCommunicator, userInput)
{}

void LinkEstablishment::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

void LinkEstablishment::executeImpl()
{
   LOG(trace) << "BEGIN";

   const auto LINK_ESTABLISHMENT_PRIM_FRAME = FrameSNRM()
      .setAddressByte(0x03);

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameSNRM>(LINK_ESTABLISHMENT_PRIM_FRAME));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string LinkEstablishment::handleResponse()
{
   return constraints::almag::L2::LINK_ESTABLISHMENT + DELIMITER;
}

