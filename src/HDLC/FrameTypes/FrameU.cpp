#include <HDLC/FrameTypes/FrameU.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

FRAME_TYPE FrameU::GET_TYPE=FRAME_TYPE::SNRM;

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

FRAME_TYPE FrameU::getType() const
{
   return FRAME_TYPE::U;
}
