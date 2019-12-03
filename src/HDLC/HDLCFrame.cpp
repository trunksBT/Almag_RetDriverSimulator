#include <HDLC/HDLCFrame.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/PrintUtils.hpp>

using namespace printUtils;

HDLCFrame::HDLCFrame(HDLCFrameBodyPtr hdlcPrimFrame)
   : hdlcPrimFrame_(hdlcPrimFrame)
{}

Hexes HDLCFrame::build() const
{
   Hexes retVal;

   retVal.push_back(START_STOP_FLAG);
   printHex("START: ", START_STOP_FLAG);

   const auto primFrame = hdlcPrimFrame_->build();

   retVal.insert( retVal.end(),
      primFrame.begin(), primFrame.end() );

   retVal.insert( retVal.end(),
      CRC.begin(), CRC.end() );

   retVal.push_back(START_STOP_FLAG);
   printHex("STOP: ", START_STOP_FLAG);

   LOG(debug) << "HDLC: " << toString(retVal);
   return retVal; 
}

std::string HDLCFrame::getFrameFromSecondary() const
{
   return hdlcPrimFrame_->getFrameFromSecondary();
}

