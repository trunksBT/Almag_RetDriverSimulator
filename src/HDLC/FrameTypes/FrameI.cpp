#include <HDLC/FrameTypes/FrameI.hpp>

using namespace funs;

FRAME_TYPE FrameI::GET_TYPE=FRAME_TYPE::I;

FrameI::FrameI()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::RETAP);
}

FrameI::FrameI(const std::string& value)
   : HDLCFrameBody(value)
{}

FrameI& FrameI::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameI& FrameI::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

FrameI& FrameI::setProcedureCode(Hex value)
{
   procedureCode_ = value;
   return *this;
}

Hexes FrameI::build() const
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

   if (not procedureCode_)
   {
      LOG(error) << "Empty procedureCode byte, returning empty frame";
      return {};
   }
   retVal.push_back(*procedureCode_);
   printHex("PROC: ", *procedureCode_);

   LOG(info) << "HDLC': " << funs::toString(retVal);
   return retVal;
}

FRAME_TYPE FrameI::getType() const
{
   return FRAME_TYPE::I;
}
