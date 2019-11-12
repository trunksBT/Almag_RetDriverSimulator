//
// Created by pkorycin on 12.11.2019.
//

#include "HDLCCommunicator.hpp"

namespace test
{
HDLCCommunicator::HDLCCommunicator()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

HDLCCommunicator::~HDLCCommunicator()
{
   LOG(trace) << "MT_HDLC_ROUND_LOOP";
}

bool HDLCCommunicator::send(const std::string &address, std::shared_ptr<HDLCFrameBody> frame)
{
   LOG(debug);
   hdlcFrame_ = frame;
   return true;
}

boost::optional<HDLCFrame> HDLCCommunicator::receive(const std::string &address)
{
   LOG(debug);
   return HDLCFrame(hdlcFrame_);
}
}  // namespace test
