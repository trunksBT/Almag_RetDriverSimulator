#pragma once

#include <memory>
#include <string>

class FrameStrFactory
{
public:
   virtual std::string get_FrameI_Calibrate() const = 0;
   virtual std::string get_FrameU_LinkEstablishment() const = 0;
   virtual std::string get_FrameXID_DummyScan() const = 0;
   virtual std::string get_FrameXID_DeviceScan() const = 0;
   virtual std::string get_FrameXID_AddressAssignment() const = 0;
   virtual std::string get_FrameXID_3GPPReleaseId() const = 0;
   virtual std::string get_FrameXID_AISGProtocolVersion() const = 0;
   virtual std::string get_FrameXID_HDLCParameters() const = 0;
   virtual ~FrameStrFactory() = default;
};
using FrameStrFactoryPtr = std::shared_ptr<FrameStrFactory>;
