#include <HDLC/FrameTypes/FrameXID.hpp>

using namespace funs;

FRAME_TYPE FrameXID::GET_TYPE=FRAME_TYPE::XID;

FrameXID::FrameXID()
   : HDLCFrameBody()
{
   setControlByte(BYTE_CONTROL::XID);
}

FrameXID::FrameXID(const std::string& value)
   : HDLCFrameBody(value)
{
   setControlByte(BYTE_CONTROL::XID);
}

FrameXID& FrameXID::setAddressByte(Hex value)
{
   address_ = value;
   return *this;
}

FrameXID& FrameXID::setControlByte(BYTE_CONTROL value)
{
   ctrl_ = value;
   return *this;
}

FrameXID& FrameXID::setFormatIdentifierByte(FI value)
{
   formatIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupIdentifierByte(GI value)
{
   groupIdentifier_ = value;
   return *this;
}

FrameXID& FrameXID::setGroupLengthByte(Hex value)
{
   groupLength_ = value;
   return *this;
}

FrameXID& FrameXID::addParameters(HDLCParameters value)
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
   retVal.push_back(static_cast<Hex>(*ctrl_));
   printHex("CTRL: ", static_cast<Hex>(*ctrl_));

   if (not formatIdentifier_)
   {
      LOG(error) << "Empty format identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(static_cast<Hex>(*formatIdentifier_));
   printHex("FI: ", static_cast<Hex>(*formatIdentifier_));

   if (not groupIdentifier_)
   {
      LOG(error) << "Empty group identifier byte, returning empty frame";
      return {};
   }
   retVal.push_back(static_cast<Hex>(*groupIdentifier_));
   printHex("GI: ", static_cast<Hex>(*groupIdentifier_));

   if (not groupLength_)
   {
      LOG(error) << "Empty group length byte, returning empty frame";
      return {};
   }
   retVal.push_back(*groupLength_);
   printHex("GL: ", *groupLength_);

   for (const auto& it : parameters_)
   {
      retVal.push_back(static_cast<Hex>(it.parId));
      LOG(trace) << "--------------";
      printHex("PI: ", static_cast<Hex>(it.parId));

      retVal.push_back(it.parLength);
      printHex("PL: ", static_cast<Hex>(it.parLength));

      retVal.insert( retVal.end(),
         it.parValue.begin(), it.parValue.end() );
      printFrame("PV: ", it.parValue);
      LOG(trace) << "--------------";
   }

   LOG(info) << "HDLC': " << funs::toString(retVal);
   return retVal;
}

FRAME_TYPE FrameXID::getType() const
{
   return FRAME_TYPE::XID;
}