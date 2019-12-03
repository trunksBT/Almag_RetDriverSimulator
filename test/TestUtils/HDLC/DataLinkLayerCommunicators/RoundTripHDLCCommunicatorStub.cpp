#include "RoundTripHDLCCommunicatorStub.hpp"
#include <Utils/Utils.hpp>
#include <Utils/PrintUtils.hpp>

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
   hdlcFrames_.clear();
   hdlcFrames_.reserve(frames.size());
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

boost::optional<std::string> RoundTripHDLCCommunicatorStub::receiveStr(const std::string &address)
{
   std::string retVal;
   for (const auto& hdlcFrame : hdlcFrames_)
   {
      retVal += toString(hdlcFrame->build());
   }
   hdlcFrames_.clear();
   return retVal;
}

}
