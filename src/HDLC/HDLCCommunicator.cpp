#include "HDLC/HDLCCommunicator.hpp"
#include <Utils/Logger.hpp>

void HDLCCommunicator::setupSend(const std::string& address)
{
   LOG(warning) << "Empty communicator";
}

void HDLCCommunicator::setupReceive(const std::string& address)
{
   LOG(warning) << "Empty communicator";
}

bool HDLCCommunicator::send(
   const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames)
{
   LOG(warning) << "Empty communicator";
   return true;
}

bool HDLCCommunicator::send(const std::string& address, HDLCFrameBodyPtr frame)
{
   LOG(warning) << "Empty communicator";
   return true;
}

MaybeHDLCFrame HDLCCommunicator::receive(const std::string& address)
{
   LOG(warning) << "Empty communicator";
   return {};
}
