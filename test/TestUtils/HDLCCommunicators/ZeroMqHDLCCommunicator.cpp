#include "ZeroMqHDLCCommunicator.hpp"
#include <TestUtils/HDLCCommunicators/ZeroMqUtils.hpp>

ZeroMqHDLCCommunicator::ZeroMqHDLCCommunicator()
: context_(1)
, requestSocket_(context_, ZMQ_REQ)
, responseSocket_(context_, ZMQ_REP)
{
   LOG(trace);
}

ZeroMqHDLCCommunicator::~ZeroMqHDLCCommunicator()
{
   responseSocket_.close();
   requestSocket_.close();
   LOG(trace);
}

bool ZeroMqHDLCCommunicator::send(const std::string &address, std::shared_ptr<HDLCFrameBody> frame)
{
   LOG(debug) << "on " << address;
   requestSocket_.connect("ipc://" + address);

   const std::string sentMessage = funs::toString(frame->build());
   LOG(debug) << "Sending on " << address << " " << sentMessage;

   return s_send(requestSocket_, sentMessage);
}

boost::optional<HDLCFrame> ZeroMqHDLCCommunicator::receive(const std::string &address)
{
   LOG(debug) << "from " << address;
   responseSocket_.bind ("ipc://" + address);

   std::string message = s_recv(responseSocket_);
   LOG(info) << "Received Message: " << message;

   return {};//HDLCFrame(HDLCFrameBody(message));  /// TODO
}

boost::optional<std::string> ZeroMqHDLCCommunicator::receiveStr(const std::string &address)
{
   LOG(debug) << "from " << address;
   responseSocket_.bind ("ipc://" + address);

   std::string message = s_recv(responseSocket_);
   LOG(info) << "Received Message: " << message;

   return "7e " + message + "13 37 7e ";
}
