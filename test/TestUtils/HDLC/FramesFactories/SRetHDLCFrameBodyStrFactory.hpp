#pragma once

#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>

class SRetHDLCFrameBodyStrFactory final : public FrameStrFactory
{
public:
   std::string get_FrameI_Calibrate() override;
   std::string get_FrameU_SNRM_LinkEstablishment() override;
   std::string get_FrameXID_DummyScan() override;
   std::string get_FrameXID_AddressAssignment() override;
   std::string get_FrameXID_3GPPReleaseId() override;
   std::string get_FrameXID_AISGProtocolVersion() override;
   virtual ~SRetHDLCFrameBodyStrFactory() = default;
};
