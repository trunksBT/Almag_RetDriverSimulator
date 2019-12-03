#include "ZMqReqRespCommunicator.hpp"
#include <TestUtils/HDLC/DataLinkLayerCommunicators/ZeroMqUtils.hpp>
#include <Utils/PrintUtils.hpp>

using namespace printUtils;

namespace
{
constexpr int NUM_OF_IO_THREADS = 1;
}

ZMqReqRespCommunicator::ZMqReqRespCommunicator()
: ZMqCommunicator{NUM_OF_IO_THREADS, zmq::socket_type::req, zmq::socket_type::rep}
{
   LOG(trace);
}

ZMqReqRespCommunicator::~ZMqReqRespCommunicator()
{
   LOG(trace);
}

void ZMqReqRespCommunicator::setupSend(const std::string& address)
{
   LOG(debug) << "on " << address;
   requestSocket_.connect("ipc://" + address);
}

void ZMqReqRespCommunicator::setupReceive(const std::string& address)
{
   LOG(debug) << "from " << address;
   responseSocket_.bind ("ipc://" + address);
}

bool ZMqReqRespCommunicator::send(const std::string &address, HDLCFrameBodyPtr frame)
{
   return send(address, std::vector<HDLCFrameBodyPtr>{{frame}});
}

bool ZMqReqRespCommunicator::send(
        const std::string &address, const std::vector<HDLCFrameBodyPtr>& frames)
{
   bool sentState = true;
   for (const auto& frame : frames)
   {
      const std::string sentMessage = toString(frame->build());
      LOG(debug) << "Sending on " << address << " " << sentMessage;
      sentState &= s_send(requestSocket_, sentMessage);
   }
   return sentState;
}

std::queue<HDLCFrame> ZMqReqRespCommunicator::receive(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(error) << "Received Message: " << message;
   return {};//HDLCFrame(HDLCFrameBody(message));  /// TODO
}

boost::optional<std::string> ZMqReqRespCommunicator::receiveStr(const std::string &address)
{
   std::string message = s_recv(responseSocket_);
   LOG(info) << "Received Message: " << message;
   return "7e " + message + "13 37 7e ";
}
