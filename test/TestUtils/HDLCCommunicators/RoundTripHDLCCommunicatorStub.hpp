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
   bool send(
           const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   bool send(const std::string &address, HDLCFrameBodyPtr frame) override;
   std::queue<HDLCFrame> receive(const std::string &address) override;
   boost::optional<std::string> receiveStr(const std::string &address) override;

   virtual ~RoundTripHDLCCommunicatorStub();

private:
   std::vector<HDLCFrameBodyPtr> hdlcFrames_;
};
}  // namespace test