//
// Created by pkorycin on 12.11.2019.
//

#include "RoundTripHDLCCommunicatorStub.hpp"

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

bool RoundTripHDLCCommunicatorStub::send(const std::string &address, std::shared_ptr<HDLCFrameBody> frame)
{
   LOG(debug);
   hdlcFrame_ = frame;
   return true;
}

boost::optional<HDLCFrame> RoundTripHDLCCommunicatorStub::receive(const std::string &address)
{
   LOG(debug);
   return HDLCFrame(hdlcFrame_);
}
}  // namespace test
