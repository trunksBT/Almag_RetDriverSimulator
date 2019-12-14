#include "PluginSpecifics/HDLCReqFrameBodyFactory.hpp"

#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameU.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameI_Calibrate() const
{
   const auto retFrame = FrameI()
           .setAddressByte(0x03)
           .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);
   return std::make_shared<FrameI>(retFrame);
}

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameU_LinkEstablishment() const
{
   const auto retFrame = FrameU()
           .setControlByte(frameU::BYTE_CONTROL::SNRM)
           .setAddressByte(0x03);
   return std::make_shared<FrameU>(retFrame);
}

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameXID_DummyScan() const
{
   auto retFrame = FrameXID()
           .setAddressByte(ADDR_ALLSTATIONS)
           .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
           .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
           .setGroupLengthByte(0x08)
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::UNIQUE_ID,
                   0x02,
                   Hexes({ 0x33, 0x33 })))
           .addParameters(HDLCParameters::build(
                   XID_PARAMS_ID::BIT_MASK,
                   0x02,
                   Hexes{{ 0xFF, 0xFF }}));
   return std::make_shared<FrameXID>(retFrame);
}

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameXID_AddressAssignment() const
{
   const auto retFrame = FrameXID()
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
   return std::make_shared<FrameXID>(retFrame);
}

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameXID_3GPPReleaseId() const
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

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameXID_AISGProtocolVersion() const
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
