#include "HDLCReqFrameBodyFactory.hpp"
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>

HDLCFrameBodyPtr HDLCReqFrameBodyFactory::get_FrameXID_DummyScan() const
{
   auto dummyScanFrameBody = FrameXID()
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
                   Hexes({ 0xFF, 0xFF })));
   return std::make_shared<FrameXID>(dummyScanFrameBody);
}
