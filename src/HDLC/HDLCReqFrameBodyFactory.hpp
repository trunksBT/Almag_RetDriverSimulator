#pragma once

#include <CommandPattern/IHDLCFrameBodyFactory.hpp>

class HDLCReqFrameBodyFactory : public IHDLCFrameBodyFactory
{
public:
   HDLCFrameBodyPtr get_FrameI_Calibrate() const override;
   HDLCFrameBodyPtr get_FrameSNRM_LinkEstablishment() const override;
   HDLCFrameBodyPtr get_FrameXID_DummyScan() const override;
   HDLCFrameBodyPtr get_FrameXID_AddressAssignment() const override;
   HDLCFrameBodyPtr get_FrameXID_3GPPReleaseId() const override;
   HDLCFrameBodyPtr get_FrameXID_AISGProtocolVersion() const override;
   virtual ~HDLCReqFrameBodyFactory() = default;
};
using HDLCReqFrameBodyFactoryPtr = std::shared_ptr<HDLCReqFrameBodyFactory>;