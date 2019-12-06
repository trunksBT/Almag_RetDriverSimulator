#include <HDLC/HDLCFrame.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

HDLCFrame::HDLCFrame(HDLCFrameBodyPtr hdlcPrimFrame)
   : hdlcFrameBody_(hdlcPrimFrame)
{}

Hexes HDLCFrame::build() const
{
   Hexes retVal;

   retVal.push_back(START_STOP_FLAG);
   printHex("START: ", START_STOP_FLAG);

   const auto primFrame = hdlcFrameBody_->build();

   retVal.insert( retVal.end(),
      primFrame.begin(), primFrame.end() );

   retVal.insert( retVal.end(),
      CRC.begin(), CRC.end() );

   retVal.push_back(START_STOP_FLAG);
   printHex("STOP: ", START_STOP_FLAG);

   LOG(debug) << "HDLC: " << toString(retVal);
   return retVal; 
}

HDLCFrameBodyPtr HDLCFrame::getFrameBody() const
{
   return hdlcFrameBody_;
}
