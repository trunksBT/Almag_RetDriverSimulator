#pragma once

#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZMqCommunicator.hpp>

class ZMqReqRespCommunicator final: public ZMqCommunicator
{
public:
   ZMqReqRespCommunicator();
   virtual ~ZMqReqRespCommunicator();

   void setupSend(const std::string& address) override;
   void setupReceive(const std::string& address) override;
   bool send(const std::string &address, const HDLCFrameBodyPtr frame) override;
   bool send(
           const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   std::queue<HDLCFrame> receive(const std::string &address) override;
};
