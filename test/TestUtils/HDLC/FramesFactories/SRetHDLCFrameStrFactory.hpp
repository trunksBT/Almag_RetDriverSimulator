#pragma once

#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>

class SRetHDLCFrameStrFactory final : public FrameStrFactory
{
public:
   SRetHDLCFrameStrFactory();
   std::string get_FrameI_Calibrate() override;
   std::string get_FrameXID_DummyScan() override;
   std::string get_FrameSNRM_LinkEstablishment() override;
   std::string get_FrameXID_AddressAssignment() override;
   std::string get_FrameXID_3GPPReleaseId() override;
   std::string get_FrameXID_AISGProtocolVersion() override;
   virtual ~SRetHDLCFrameStrFactory() = default;
private:
   FrameStrFactoryPtr sRetHdlcFrameBodyStrFactory_;
};
