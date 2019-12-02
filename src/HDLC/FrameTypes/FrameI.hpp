#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameI : public HDLCFrameBody 
{
public:
   FrameI();
   explicit FrameI(const std::string& value);

   FrameI& setAddressByte(Hex value);
   FrameI& setControlByte(Hex value);
   FrameI& setProcedureCode(Hex value);

   Hexes build() const;
   FRAME_TYPE getType() const override;
   static FRAME_TYPE GET_TYPE;

private:
   boost::optional<Hex> procedureCode_;
};

using FrameIPtr = std::unique_ptr<FrameI>;
