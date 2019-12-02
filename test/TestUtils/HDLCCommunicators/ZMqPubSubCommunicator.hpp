#pragma once

#include <TestUtils/HDLCCommunicators/ZMqCommunicator.hpp>

class ZMqPubSubCommunicator final: public ZMqCommunicator
{
public:
   ZMqPubSubCommunicator();
   virtual ~ZMqPubSubCommunicator();

   void setupSend(const std::string& address) override;
   void setupReceive(const std::string& address) override;
   bool send(const std::string &address, HDLCFrameBodyPtr frame) override;
   bool send(const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   std::queue<HDLCFrame> receive(const std::string &address) override;
   boost::optional<std::string> receiveStr(const std::string &address) override;
};
