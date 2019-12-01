#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameI : public HDLCFrameBody 
{
public:
   FrameI();
   explicit FrameI(const std::string& value);

   FrameI& setAddressByte(Hex value);
   FrameI& setControlByte(BYTE_CONTROL value);
   FrameI& setProcedureCode(PROCEDURE_CODE value);

   Hexes build() const;
   FRAME_TYPE getType() const override;

private:
   boost::optional<PROCEDURE_CODE> procedureCode_;
};

/*
1A 00 // WAT1
06  // GL
00 4B // WAT2
03  // ADDR
31  // CMD
00 00  // padding
*/

