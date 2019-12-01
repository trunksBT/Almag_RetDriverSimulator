#pragma once

#include <TestUtils/HDLCCommunicators/ZMqCommunicator.hpp>

class ZMqReqRespCommunicator final: public ZMqCommunicator
{
public:
   ZMqReqRespCommunicator();
   virtual ~ZMqReqRespCommunicator();

   void setupSend(const std::string& address) override;
   void receiveSetup(const std::string& address) override;
   bool send(const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   boost::optional<std::string> receiveStr(const std::string &address) override;
   boost::optional<HDLCFrame> receive(const std::string &address) override;
};
