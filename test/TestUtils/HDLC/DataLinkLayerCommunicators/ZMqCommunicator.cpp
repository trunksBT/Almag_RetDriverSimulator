#include "ZMqCommunicator.hpp"

ZMqCommunicator::ZMqCommunicator(
   int numOfIoThreads, zmq::socket_type requestType, zmq::socket_type responseType)
   : context_{numOfIoThreads}
   , requestSocket_{context_, requestType}
   , responseSocket_{context_, responseType}
{
   LOG(trace);
}

ZMqCommunicator::~ZMqCommunicator()
{
   LOG(trace);
}
