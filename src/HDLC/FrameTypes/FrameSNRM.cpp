#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

frameType::BYTE_CTRL FrameSNRM::GET_TYPE=frameType::BYTE_CTRL::SNRM;

FrameSNRM::FrameSNRM()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::SNRM);
}

FrameSNRM::FrameSNRM(const std::string& value)
   : HDLCFrameBody(value)
{
   setControlByte(BYTE_CONTROL::SNRM);
}

FrameSNRM& FrameSNRM::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameSNRM& FrameSNRM::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

Hexes FrameSNRM::build() const
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

frameType::BYTE_CTRL FrameSNRM::getType() const
{
   return frameType::BYTE_CTRL::SNRM;
}
