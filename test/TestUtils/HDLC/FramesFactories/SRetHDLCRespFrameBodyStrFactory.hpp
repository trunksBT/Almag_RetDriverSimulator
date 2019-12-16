#pragma once

#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>

class SRetHDLCRespFrameBodyStrFactory final : public FrameStrFactory
{
public:
   std::string get_FrameI_Calibrate() const override;
   std::string get_FrameU_LinkEstablishment() const override;
   std::string get_FrameXID_DummyScan() const override;
   std::string get_FrameXID_DeviceScan() const override;
   std::string get_FrameXID_AddressAssignment() const override;
   std::string get_FrameXID_3GPPReleaseId() const override;
   std::string get_FrameXID_AISGProtocolVersion() const override;
   std::string get_FrameXID_HDLCParameters() const override;
   virtual ~SRetHDLCRespFrameBodyStrFactory() = default;
};
