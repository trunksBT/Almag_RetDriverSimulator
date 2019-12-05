#include <CommandPattern/Commands/AddressAssignment.hpp>

#include <filesystem>

#include <HDLC/FrameTypes/FrameXID.hpp>
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

AddressAssignment::AddressAssignment(IHDLCCommunicatorPtr hdlcCommunicator, Strings userInput)
   : HDLCCommand(hdlcCommunicator, userInput)
{
   LOG(trace);
}

void AddressAssignment::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

HDLCFrameBodyPtr AddressAssignment::getFrameBody()
{
   const auto addressAssignmentFrameBody = FrameXID()
       .setAddressByte(ADDR_ALLSTATIONS)
       .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
       .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
       .setGroupLengthByte(0x11)
       .addParameters(HDLCParameters::build(
               XID_PARAMS_ID::UNIQUE_ID,
               0x09,
               Hexes{{
                             0x4E, 0x4B, 0x34, 0x36, 0x35,
                             0x30, 0x30, 0x30, 0x30
                     }}))
       .addParameters(HDLCParameters::build(
               XID_PARAMS_ID::ASSIGNED_ADDRESS,
               0x01,
               Hexes{{ 0x03 }}))
       .addParameters(HDLCParameters::build(
               XID_PARAMS_ID::DEVICE_TYPE,
               0x01,
               Hexes{{ DEVICE_TYPE::SRET }}
       ));
   return std::make_shared<FrameXID>(addressAssignmentFrameBody);
}

void AddressAssignment::executeImpl()
{
   LOG(trace) << "BEGIN";

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
                           getFrameBody());

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string AddressAssignment::handleResponse()
{
   return constraints::almag::L2::ADDRESS_ASSIGNMENT + DELIMITER;
}

