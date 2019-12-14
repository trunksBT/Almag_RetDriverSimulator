#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class IHDLCFrameBodyFactory
{
public:
   virtual HDLCFrameBodyPtr get_FrameI_Calibrate() const = 0;
   virtual HDLCFrameBodyPtr get_FrameU_LinkEstablishment() const = 0;
   virtual HDLCFrameBodyPtr get_FrameXID_DummyScan() const = 0;
   virtual HDLCFrameBodyPtr get_FrameXID_AddressAssignment() const = 0;
   virtual HDLCFrameBodyPtr get_FrameXID_3GPPReleaseId() const = 0;
   virtual HDLCFrameBodyPtr get_FrameXID_AISGProtocolVersion() const = 0;

   virtual ~IHDLCFrameBodyFactory() = default;
};
using IHDLCFrameBodyFactoryPtr = std::shared_ptr<IHDLCFrameBodyFactory>;
