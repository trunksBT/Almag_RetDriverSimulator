#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <Utils/PrintUtils.hpp>

using namespace printUtils;

FRAME_TYPE FrameSNRM::GET_TYPE=FRAME_TYPE::SNRM;

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

   retVal.push_back(static_cast<Hex>(*ctrl_));
   printHex("CTRL: ", static_cast<Hex>(*ctrl_));

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}

FRAME_TYPE FrameSNRM::getType() const
{
   return FRAME_TYPE::SNRM;
}
