#include <HDLC/HDLCCommunicator.hpp>

#include <HDLC/MessagesHelpers.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>

#include <Utils/Logger.hpp>
#include <Utils/PrintUtils.hpp>

using namespace printUtils;

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

std::queue<HDLCFrame> HDLCCommunicator::receive(const std::string& address)
{
   LOG(warning) << "Empty communicator";
   return {};
}
