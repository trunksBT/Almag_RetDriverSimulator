#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameXID : public HDLCFrameBody 
{
public:
   FrameXID();
   explicit FrameXID(const std::string& value);

   FrameXID& setAddressByte(Hex value);
   FrameXID& setControlByte(BYTE_CONTROL value);
   FrameXID& setFormatIdentifierByte(FI value);
   FrameXID& setGroupIdentifierByte(GI value);
   FrameXID& setGroupLengthByte(Hex value);
   FrameXID& addParameters(HDLCParameters value);

   Hexes build() const;
   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;
};

