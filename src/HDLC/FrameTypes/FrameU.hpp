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
   int getType() const override;
   static FRAME_TYPE GET_TYPE;

private:
   boost::optional<Hex> procedureCode_;
};

using FrameUPtr = std::unique_ptr<FrameU>;
