#pragma once

#include <TestUtils/HDLC/FramesFactories/FrameHexFactory.hpp>

class SRetFrameBodyHexFactory final : public FrameHexFactory
{
public:
   Hexes get_FrameI_Calibrate() override;
   Hexes get_FrameXID_DummyScan() override;
   Hexes get_FrameSNRM_LinkEstablishment() override;
   Hexes get_FrameXID_AddressAssignment() override;
   Hexes get_FrameXID_3GPPReleaseId() override;
   Hexes get_FrameXID_AISGProtocolVersion() override;
   virtual ~SRetFrameBodyHexFactory() = default;
};
