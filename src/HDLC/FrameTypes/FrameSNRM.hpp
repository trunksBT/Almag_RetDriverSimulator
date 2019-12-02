#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameSNRM : public HDLCFrameBody
{
public:
   FrameSNRM();
   explicit FrameSNRM(const std::string& value);

   FrameSNRM& setAddressByte(Hex value);
   FrameSNRM& setControlByte(Hex value);

   Hexes build() const;
   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;
};

using FrameSNRMPtr = std::unique_ptr<FrameSNRM>;
