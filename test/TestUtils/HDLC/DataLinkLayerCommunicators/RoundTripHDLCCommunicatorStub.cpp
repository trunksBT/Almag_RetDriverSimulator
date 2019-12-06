#include "RoundTripHDLCCommunicatorStub.hpp"
#include <Utils/Utils.hpp>
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace convert;
using namespace printUtils;

namespace test
{

RoundTripHDLCCommunicatorStub::RoundTripHDLCCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

RoundTripHDLCCommunicatorStub::~RoundTripHDLCCommunicatorStub()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

bool RoundTripHDLCCommunicatorStub::send(
        const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames)
{
   LOG(debug);
   for (const auto& frame : frames)
   {
      printFrame("Frame: ", frame->build());
      hdlcFrames_.push_back(frame);
   }
   return true;
}

bool RoundTripHDLCCommunicatorStub::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   send(address, std::vector<HDLCFrameBodyPtr>{{frame}});
   return true;
}

std::queue<HDLCFrame> RoundTripHDLCCommunicatorStub::receive(const std::string &address)
{
   std::queue<HDLCFrame> retVal;
   for (const auto& hdlcFrameBody : hdlcFrames_)
   {
      retVal.push(HDLCFrame(hdlcFrameBody));
   }
   hdlcFrames_.clear();
   return retVal;
}

}
