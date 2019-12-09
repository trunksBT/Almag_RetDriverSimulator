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
   frameType::BYTE_CTRL getType() const override;
   static frameType::BYTE_CTRL GET_TYPE;
};

using FrameSNRMPtr = std::shared_ptr<FrameSNRM>;
