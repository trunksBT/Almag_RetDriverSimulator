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
           .setControlByte(frameU::BYTE_CONTROL::UA)
           .setAddressByte(0x03);
   return std::make_shared<FrameU>(retFrame);
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_DummyScan() const
{
   throw std::runtime_error("Not implemented yet");
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_AddressAssignment() const
{
   throw std::runtime_error("Not implemented yet");
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_3GPPReleaseId() const
{
   throw std::runtime_error("Not implemented yet");
}

HDLCFrameBodyPtr HDLCRespFrameBodyFactory::get_FrameXID_AISGProtocolVersion() const
{
   throw std::runtime_error("Not implemented yet");
}
