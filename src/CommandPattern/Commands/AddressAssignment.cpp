#include <CommandPattern/Commands/AddressAssignment.hpp>

#include <filesystem>

#include <HDLC/FrameTypes/FrameXID.hpp>
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

AddressAssignment::AddressAssignment(
        std::shared_ptr<IHDLCCommunicator> hdlcCommunicator, Strings userInput)
   : ICommand(userInput, hdlcCommunicator)
{}

void AddressAssignment::execute()
{
   LOG(info);
   executeImpl();
   informControllerAboutResult_();
}

void AddressAssignment::executeImpl()
{
   LOG(trace) << "BEGIN";
   
   const auto AddressAssignmentPrimFrame = FrameXID()
      .setAddressByte(0xFF)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDR_ASSIGNMENT)
      .setGroupLengthByte(0x1B)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::UNIQUE_ID,
         0x13,
         Hexes({ 0x41, 0x4E, 0x30, 0x30, 0x30, 0x30, 0x43, 0x4E, 0x31, 0x30,
                 0x31, 0x32, 0x33, 0x33, 0x32, 0x32, 0x34, 0x36, 0x31 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::ASSIGNED_ADDRESS,
         0x01,
         Hexes({ 0x03 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::DEVICE_TYPE,
         0x01,
         Hexes({ static_cast<Hex>(DEVICE_TYPE::SRET) })
      ));

   hdlcCommunicator_->send(validatedUserInput_[IDX_OF_ADDRESS],
      std::make_shared<FrameXID>(AddressAssignmentPrimFrame));

   LOG(trace) << "===============================================";
   LOG(trace) << "END";
}

std::string AddressAssignment::handleResponse()
{
   return L2::ADDRESS_ASSIGNMENT + DELIMITER;
}

