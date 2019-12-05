#pragma once

#include <CommandPattern/IHDLCFrameBodyFactory.hpp>

class HDLCReqFrameBodyFactory : public IHDLCFrameBodyFactory
{
public:
//   virtual Hexes get_FrameI_Calibrate() = 0;
//   virtual Hexes get_FrameSNRM_LinkEstablishment() = 0;
   HDLCFrameBodyPtr get_FrameXID_DummyScan() const override;
//   virtual Hexes get_FrameXID_AddressAssignment() = 0;
//   virtual Hexes get_FrameXID_3GPPReleaseId() = 0;
//   virtual Hexes get_FrameXID_AISGProtocolVersion() = 0;

   virtual ~HDLCReqFrameBodyFactory() = default;
};
using HDLCReqFrameBodyFactoryPtr = std::shared_ptr<HDLCReqFrameBodyFactory>;