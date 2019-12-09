#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameU : public HDLCFrameBody
{
public:
   FrameU();
   explicit FrameU(const std::string& value);

   FrameU& setAddressByte(Hex value);
   FrameU& setControlByte(Hex value);

   Hexes build() const;
   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;
};

using FrameUPtr = std::unique_ptr<FrameU>;
