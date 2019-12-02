#include <HDLC/FrameTypes/FrameI.hpp>

using namespace funs;

FRAME_TYPE FrameI::GET_TYPE=FRAME_TYPE::I;

FrameI::FrameI()
   : HDLCFrameBody()
{
   setControlByte(static_cast<Hex>(BYTE_CONTROL::RETAP));
}

FrameI::FrameI(const std::string& value)
   : HDLCFrameBody(value)
{}

FrameI& FrameI::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameI& FrameI::setControlByte(BYTE_CONTROL value)
{
   ctrl_ = value;
   return *this;
}

FrameI& FrameI::setControlByte(Hex value)
{
   ctrlHex_ = value;
   return *this;
}

FrameI& FrameI::setProcedureCode(Hex value)
{
   procedureCodeHex_ = value;
   return *this;
}

FrameI& FrameI::setProcedureCode(PROCEDURE_CODE value)
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

   if (not ctrlHex_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(*ctrlHex_);
   printHex("CTRL: ", *ctrlHex_);

   if (not procedureCodeHex_)
   {
      LOG(error) << "Empty procedureCode byte, returning empty frame";
      return {};
   }
   retVal.push_back(*procedureCodeHex_);
   printHex("PROC: ", *procedureCodeHex_);

   LOG(info) << "HDLC': " << funs::toString(retVal);
   return retVal;
}

FRAME_TYPE FrameI::getType() const
{
   return FRAME_TYPE::I;
}
