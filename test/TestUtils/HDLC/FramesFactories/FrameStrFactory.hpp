#pragma once

#include <memory>
#include <string>

class FrameStrFactory
{
public:
   virtual std::string get_FrameI_Calibrate() = 0;
   virtual std::string get_FrameU_SNRM_LinkEstablishment() = 0;
   virtual std::string get_FrameXID_DummyScan() = 0;
   virtual std::string get_FrameXID_AddressAssignment() = 0;
   virtual std::string get_FrameXID_3GPPReleaseId() = 0;
   virtual std::string get_FrameXID_AISGProtocolVersion() = 0;
   virtual ~FrameStrFactory() = default;
};
using FrameStrFactoryPtr = std::shared_ptr<FrameStrFactory>;
