#include "HDLC/FrameTypes/FrameU.hpp"
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace convert;
using namespace printUtils;

int FrameU::GET_TYPE=FRAME_TYPE::U;

FrameU::FrameU()
   : HDLCFrameBody()
{
   LOG(trace);
}

FrameU::FrameU(const std::string& value)
   : HDLCFrameBody(value)
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
   LOG(trace) << "START";

   if (not address_)
   {
      LOG(error) << "Empty address byte, returning empty frame";
      return {};
   }
   retVal.push_back(*address_);
   printHex("ADDR: ", *address_);

   if (not ctrl_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(*ctrl_);
   printHex("CTRL: ", *ctrl_);

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}

FRAME_TYPE FrameU::getType() const
{
   return FRAME_TYPE::I;
}
