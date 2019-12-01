#include "ZMqPubSubCommunicator.hpp"
#include <TestUtils/HDLCCommunicators/ZeroMqUtils.hpp>

namespace
{
constexpr int NUM_OF_IO_THREADS{ 1 };
constexpr uint8_t IS_ON{ 1 };
inline bool isLastMessage(int msgCount, int numberOfMessages)
{
   return msgCount == numberOfMessages-1;
}
}

ZMqPubSubCommunicator::ZMqPubSubCommunicator()
        : ZMqCommunicator{NUM_OF_IO_THREADS, zmq::socket_type::pub, zmq::socket_type::sub}
{
   LOG(trace);
}

ZMqPubSubCommunicator::~ZMqPubSubCommunicator()
{
   LOG(trace);
}

void ZMqPubSubCommunicator::setupSend(const std::string& address)
{
   LOG(debug) << "on " << address;
   requestSocket_.bind("ipc://" + address);
   s_send(requestSocket_, address, zmq::send_flags::sndmore);
}

void ZMqPubSubCommunicator::receiveSetup(const std::string& address)
{
   requestSocket_.connect(address);
   requestSocket_.setsockopt(zmq::socket_type::sub, address.data(), IS_ON);
}

bool ZMqPubSubCommunicator::send(const std::string& address, const std::vector<HDLCFrameBody>& frames)
{
   bool sentState = true;
   for (int msgCount = 0; msgCount < frames.size(), msgCount++)
   {
      const std::string sentMessage = funs::toString(frame.at(msgCount)->build());
      LOG(debug) << "Sending on " << address << " " << sentMessage;
      if (isLastMessage(msgCount, frames.size()))
      {
         sentState &= s_send(requestSocket_, sentMessage);
      }
      else
      {
         sentState &= s_send(requestSocket_, sentMessage, zmq::send_flags::sndmore);
      }
   }
   return sentState;
}

boost::optional<HDLCFrame> ZMqPubSubCommunicator::receive(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(info) << "Received Message: " << message;
   return {};//HDLCFrame(HDLCFrameBody(message));  /// TODO
}

boost::optional<std::string> ZMqPubSubCommunicator::receiveStr(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(info) << "Received Message: " << message;
   return "7e " + message + "13 37 7e ";
}
