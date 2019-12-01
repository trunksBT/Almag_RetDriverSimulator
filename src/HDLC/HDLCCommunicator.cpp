#include <HDLC/HDLCCommunicator.hpp>

#include <HDLC/MessagesHelpers.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>

#include <Utils/Logger.hpp>

using namespace funs;

bool HDLCCommunicator::send(
   const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames)
{
   LOG(trace) << "BEGIN";

   streamToSend.open(address);
   for (const auto& frame : frames)
   {
      streamToSend << toString(HDLCFrame(frame).build());
   }
   streamToSend.close();
   LOG(trace) << "END";
   return true;
}  // ofsFile << std::hex << std::uppercase << result.checksum() << std::flush;

boost::optional<HDLCFrame> HDLCCommunicator::receive(const std::string& address)
{
   LOG(trace) << "BEGIN";
   LOG(debug) << "Addres to open: " << address;
   std::string receivedFrameStr;

   streamToReceive.open(address);
   if (streamToReceive.is_open())
   {
      getline(streamToReceive, receivedFrameStr);
   }
   streamToReceive.close();

   std::shared_ptr<HDLCFrameBody> receivedFrame
      = std::make_shared<FrameSNRM>(receivedFrameStr);

   HDLCFrame validatedFrame(receivedFrame);
   // here should be validation of received frame

   LOG(trace) << "END";
   return validatedFrame;
}

boost::optional<std::string> HDLCCommunicator::receiveStr(const std::string &address)
{
   LOG(error) << "NOT IMPLEMENTED YET";
   return {};
}
