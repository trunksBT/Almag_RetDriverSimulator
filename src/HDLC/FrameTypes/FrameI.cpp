#include <HDLC/FrameTypes/FrameI.hpp>

using namespace funs;

FrameI::FrameI()
   : HDLCFrameBody()
{}

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

FrameI& FrameI::setProcedureCode(PROCEDURE_CODE value)
{
   procedureCode_ = value;
   return *this;
}

Hexes FrameI::build() const
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

   if (not ctrl_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(static_cast<Hex>(*ctrl_));
   printHex("CTRL: ", static_cast<Hex>(*ctrl_));

   if (not procedureCode_)
   {
      LOG(error) << "Empty control byte, returning empty frame";
      return {};
   }
   retVal.push_back(static_cast<Hex>(*procedureCode_));
   printHex("PROC: ", static_cast<Hex>(*procedureCode_));

   LOG(info) << "HDLC': " << funs::toString(retVal);
   return retVal;
}

