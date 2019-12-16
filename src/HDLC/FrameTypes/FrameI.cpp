#include <HDLC/FrameTypes/FrameI.hpp>
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace convert;
using namespace printUtils;

frameType::BYTE_CTRL FrameI::GET_TYPE=frameType::BYTE_CTRL::I;

FrameI::FrameI()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::RETAP);
}

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

FrameI& FrameI::setParameterLength(Hexes values)
{
   parLength_ = values;
   return *this;
}

FrameI& FrameI::setParameterValues(Hexes values)
{
   parValues_ = values;
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

   for (const auto& it : parLength_)
   {
      retVal.push_back(it);
   }
   printFrame("PAR LENGTH: ", parLength_);

   if (not parValues_.empty())
   {
      for (const auto &it : parValues_)
      {
         retVal.push_back(it);
      }

      printFrame("PAR VALUES: ", parValues_);
   }

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}

frameType::BYTE_CTRL FrameI::getType() const
{
   return frameType::BYTE_CTRL::I;
}
