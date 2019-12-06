#pragma once

#include <HDLC/IHDLCCommunicator.hpp>
#include "ZeroMqUtils.hpp"

class ZMqCommunicator : public IHDLCCommunicator
{
public:
   ZMqCommunicator(int numOfIoThreads,
      zmq::socket_type requestType, zmq::socket_type responseType);

   virtual void setupSend(const std::string& address) = 0;
   virtual void setupReceive(const std::string& address) = 0;
   virtual bool send(const std::string& address, HDLCFrameBodyPtr frame) = 0;
   virtual bool send(
           const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames) = 0;
   virtual std::queue<HDLCFrame> receive(const std::string& address) = 0;

   virtual ~ZMqCommunicator();

protected:
   zmq::context_t context_;
   zmq::socket_t requestSocket_;
   zmq::socket_t responseSocket_;
};
