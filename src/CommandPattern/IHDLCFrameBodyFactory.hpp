#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class IHDLCFrameBodyFactory
{
//   virtual Hexes get_FrameI_Calibrate() = 0;
//   virtual Hexes get_FrameSNRM_LinkEstablishment() = 0;
   virtual HDLCFrameBodyPtr get_FrameXID_DummyScan() = 0;
//   virtual Hexes get_FrameXID_AddressAssignment() = 0;
//   virtual Hexes get_FrameXID_3GPPReleaseId() = 0;
//   virtual Hexes get_FrameXID_AISGProtocolVersion() = 0;

   virtual ~IHDLCFrameBodyFactory() = default;
};
using IHDLCFrameBodyFactoryPtr = std::shared_ptr<IHDLCFrameBodyFactory>;