#pragma once

#include <HDLC/IHDLCCommunicator.hpp>
#include "ZeroMqUtils.hpp"

class ZeroMqHDLCCommunicator : public IHDLCCommunicator
{
public:
   ZeroMqHDLCCommunicator();
   virtual ~ZeroMqHDLCCommunicator();

   bool send(const std::string &address, std::shared_ptr<HDLCFrameBody> frame);
   boost::optional<std::string> receiveStr(const std::string &address);
   boost::optional<HDLCFrame> receive(const std::string &address);
private:
   zmq::context_t context_;
   zmq::socket_t requestSocket_;
   zmq::socket_t responseSocket_;
};
