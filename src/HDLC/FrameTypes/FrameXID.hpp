#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameXID : public HDLCFrameBody 
{
public:
   FrameXID();
   explicit FrameXID(const std::string& value);

   FrameXID& setAddressByte(Hex value);
   FrameXID& setControlByte(Hex value);
   FrameXID& setFormatIdentifierByte(Hex value);
   FrameXID& setGroupIdentifierByte(Hex value);
   FrameXID& setGroupLengthByte(Hex value);
   FrameXID& addParameters(HDLCParameters value);

   Hexes build() const;
   frameType::BYTE_CTRL getType() const override;
   static frameType::BYTE_CTRL GET_TYPE;
};

using FrameXIDPtr = std::shared_ptr<FrameXID>;
