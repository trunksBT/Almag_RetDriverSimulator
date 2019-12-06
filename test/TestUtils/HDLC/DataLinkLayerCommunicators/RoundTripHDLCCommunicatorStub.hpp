#pragma once

#include <HDLC/IHDLCCommunicator.hpp>
#include <queue>

namespace test
{
class RoundTripHDLCCommunicatorStub final: public IHDLCCommunicator
{
public:
   explicit RoundTripHDLCCommunicatorStub();

   void setupSend(const std::string& address) override {};
   void setupReceive(const std::string& address) override {};
   bool send(const std::string &address, HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string &address) override;

   virtual ~RoundTripHDLCCommunicatorStub();

private:
   HDLCFrameBodyPtr hdlcFrameBody_;
};
}  // namespace test