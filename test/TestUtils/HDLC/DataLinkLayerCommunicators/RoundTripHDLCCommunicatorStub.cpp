#include "RoundTripHDLCCommunicatorStub.hpp"
#include <Utils/Functions.hpp>

using namespace convert;

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

bool RoundTripHDLCCommunicatorStub::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   hdlcFrameBody_ = frame;
   const std::string sentMessage = toString(hdlcFrameBody_->build());
   LOG(info) << "Sending on " << address << " " << sentMessage;
   return true;
}

HDLCFramePtr RoundTripHDLCCommunicatorStub::receive(const std::string &address)
{
   return std::make_shared<HDLCFrame>(hdlcFrameBody_);
}
}
