#include <HDLC/FrameTypes/FrameU.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

frameType::BYTE_CTRL FrameU::GET_TYPE=frameType::BYTE_CTRL::U;

FrameU::FrameU()
   : HDLCFrameBody()
{
   LOG(trace);
}

FrameU& FrameU::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameU& FrameU::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

Hexes FrameU::build() const
{
   Hexes retVal;
   LOG(trace);

   if (not address_)
   {
      LOG(error) << "Empty address byte, returning empty frame";
      return {};
   }
   retVal.push_back(*address_);
   printHex("ADDR: ", *address_);

   retVal.push_back(*ctrl_);
   printHex("CTRL: ", *ctrl_);

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}

frameType::BYTE_CTRL FrameU::getType() const
{
   return frameType::BYTE_CTRL::U;
}
