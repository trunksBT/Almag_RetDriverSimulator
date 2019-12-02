#pragma once

#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>

class SRetFrameBodyStrFactory final : public FrameStrFactory
{
public:
   std::string_view get_FrameI_Calibrate() override;
   std::string_view get_FrameXID_DummyScan() override;
   std::string_view get_FrameSNRM_LinkEstablishment() override;
   std::string_view get_FrameXID_AddressAssignment() override;
   std::string_view get_FrameXID_3GPPReleaseId() override;
   std::string_view get_FrameXID_AISGProtocolVersion() override;
   virtual ~SRetFrameBodyStrFactory() = default;
};
