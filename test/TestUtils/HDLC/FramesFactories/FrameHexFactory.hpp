#pragma once

#include <memory>
#include <Utils/TypeAliases.hpp>

class FrameHexFactory
{
public:
   virtual Hexes get_FrameI_Calibrate() = 0;
   virtual Hexes get_FrameSNRM_LinkEstablishment() = 0;
   virtual Hexes get_FrameXID_DummyScan() = 0;
   virtual Hexes get_FrameXID_AddressAssignment() = 0;
   virtual Hexes get_FrameXID_3GPPReleaseId() = 0;
   virtual Hexes get_FrameXID_AISGProtocolVersion() = 0;
   virtual ~FrameHexFactory() = default;
};

using FrameHexFactoryPtr = std::shared_ptr<FrameHexFactory>;