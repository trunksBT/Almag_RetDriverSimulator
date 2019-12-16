#pragma once

#include <HDLC/HDLCFrameBody.hpp>

class FrameI : public HDLCFrameBody 
{
public:
   FrameI();

   FrameI& setAddressByte(Hex value);
   FrameI& setControlByte(Hex value);
   FrameI& setProcedureCode(Hex value);
   FrameI& setParameterLength(Hexes values);
   FrameI& setParameterValues(Hexes values);

   Hexes build() const;
   frameType::BYTE_CTRL getType() const override;
   static frameType::BYTE_CTRL GET_TYPE;

private:
   boost::optional<Hex> procedureCode_;
   Hexes parLength_;
   Hexes parValues_;
};

using FrameIPtr = std::shared_ptr<FrameI>;
