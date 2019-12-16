#include <HDLC/FrameTypes/FrameXID.hpp>
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace convert;
using namespace printUtils;

frameType::BYTE_CTRL FrameXID::GET_TYPE=frameType::BYTE_CTRL::XID;

FrameXID::FrameXID()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::XID);
}

FrameXID& FrameXID::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameXID& FrameXID::setControlByte(Hex value)
{
   ctrl_ = value;
   return *this;
}

FrameXID& FrameXID::setFormatIdentifierByte(Hex value)
{
   formatIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupIdentifierByte(Hex value)
{
   groupIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupLengthByte(Hex value)
{
   groupLength_ = value;
   return *this;
}

FrameXID& FrameXID::addParameters(HDLCParametersValues value)
{
   parameters_.emplace_back(value);
   return *this;
}

Hexes FrameXID::build() const
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
   retVal.push_back(*ctrl_);
   printHex("CTRL: ", *ctrl_);

   if (not formatIdentifier_)
   {
      LOG(error) << "Empty format identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(*formatIdentifier_);
   printHex("FI: ", *formatIdentifier_);

   if (not groupIdentifier_)
   {
      LOG(error) << "Empty group identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(*groupIdentifier_);
   printHex("GI: ", *groupIdentifier_);

   if (not groupLength_)
   {
      LOG(error) << "Empty group length byte, returning empty frame";
      return {};
   }
   retVal.push_back(*groupLength_);
   printHex("GL: ", *groupLength_);

   for (const auto& it : parameters_)
   {
      retVal.push_back(it.parId);
      LOG(debug) << "--------------";
      printHex("PI: ", it.parId);

      retVal.push_back(it.parLength);
      printHex("PL: ", it.parLength);

      retVal.insert( retVal.end(), it.parValue.begin(), it.parValue.end() );
      printFrame("PV: ", it.parValue);
      LOG(debug) << "--------------";
   }

   LOG(info) << "HDLC': " << toString(retVal);
   return retVal;
}

frameType::BYTE_CTRL FrameXID::getType() const
{
   return frameType::BYTE_CTRL::XID;
}
