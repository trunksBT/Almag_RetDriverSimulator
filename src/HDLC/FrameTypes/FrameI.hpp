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
   frameType::BYTE_CTRL getType() const override;
   static frameType::BYTE_CTRL GET_TYPE;

private:
   boost::optional<Hex> procedureCode_;
};

using FrameIPtr = std::shared_ptr<FrameI>;
