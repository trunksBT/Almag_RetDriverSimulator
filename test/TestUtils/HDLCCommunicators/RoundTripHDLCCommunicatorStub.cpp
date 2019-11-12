//
// Created by pkorycin on 12.11.2019.
//

#include "RoundTripHDLCCommunicatorStub.hpp"
#include <Utils/Utils.hpp>

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

boost::optional<std::string> RoundTripHDLCCommunicatorStub::receiveStr(const std::string &address)
{
   if (const auto receivedHDLCFrame = receive(address))
   {
      return funs::toString(receivedHDLCFrame->build());
   }
   return {};
}

}  // namespace test
