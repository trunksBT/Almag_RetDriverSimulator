#include "HDLCRespFrameBodyFactory.hpp"

#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameU.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameI_Calibrate() const
{
   throw std::runtime_error("Not implemented yet");
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameU_LinkEstablishment() const
{
   const auto retFrame = FrameU()
           .setAddressByte(0x03)
           .setControlByte(frameU::BYTE_CONTROL::UA);
   return std::make_shared<FrameU>(retFrame);
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_DummyScan() const
{
   throw std::runtime_error("Redundant interface feed");
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_AddressAssignment() const
{
   const auto retFrame = FrameXID()
           .setAddressByte(0x03)
           .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
           .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
           .setGroupLengthByte(0x12)
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::UNIQUE_ID,
                   0x09,
                   Hexes({0x4E, 0x4B, 0x34, 0x36, 0x35, 0x30, 0x30 ,0x30 ,0x30}))
                   )
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::DEVICE_TYPE,
                   0x01,
                   Hexes{{ DEVICE_TYPE::SRET }}
           ))
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::VENDOR_CODE,
                   0x02,
                   Hexes{{ 0x4E, 0x4B }}
           ));
   return std::make_shared<FrameXID>(retFrame);
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_3GPPReleaseId() const
{
   const auto retFrame = FrameXID()
           .setAddressByte(0x03)
           .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
           .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
           .setGroupLengthByte(0x03)
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::THREEGPP_RELEASE_ID,
                   0x01,
                   Hexes({ PV::THREEGPP_RELEASE_ID_VAL_8 })
           ));
   return std::make_shared<FrameXID>(retFrame);
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_AISGProtocolVersion() const
{
   const auto retFrame = FrameXID()
           .setAddressByte(0x03)
           .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
           .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
           .setGroupLengthByte(0x03)
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::AISG_PROTOCOL_VERSION,
                   0x01,
                   Hexes({ PV::AISG_2_0 })
           ));
   return std::make_shared<FrameXID>(retFrame);
}
