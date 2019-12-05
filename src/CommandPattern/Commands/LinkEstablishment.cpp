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

HDLCFrameBodyPtr LinkEstablishment::getFrameBody() const
{
   return hdlcFrameBodyFactory_->get_FrameSNRM_LinkEstablishment();
}

void LinkEstablishment::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string LinkEstablishment::handleResponse()
{
   return constraints::almag::L2::LINK_ESTABLISHMENT + DELIMITER;
}

