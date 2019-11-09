#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameSNRM : public HDLCFrameBody
{
public:
   FrameSNRM();
   explicit FrameSNRM(const std::string& value);

   FrameSNRM& setAddressByte(Hex value);
   FrameSNRM& setControlByte(BYTE_CONTROL value);

   Hexes build() const;
};

