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
   frameType::BYTE_CTRL getType() const override;
   static frameType::BYTE_CTRL GET_TYPE;
};

using FrameUPtr = std::shared_ptr<FrameU>;
