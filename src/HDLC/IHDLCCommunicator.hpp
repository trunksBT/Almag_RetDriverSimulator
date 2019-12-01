#pragma once

#include <memory>
#include <string>
#include <boost/optional.hpp>

#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/HDLCFrame.hpp>

class IHDLCCommunicator
{
public:
   virtual void setupSend(const std::string& address) = 0;
   virtual void receiveSetup(const std::string& address) = 0;
   virtual bool send(const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames) = 0;
   virtual boost::optional<HDLCFrame> receive(const std::string& address) = 0;
   virtual boost::optional<std::string> receiveStr(const std::string &address) = 0;
   virtual ~IHDLCCommunicator() = default;
};

using IHDLCCommunicatorPtr = std::shared_ptr<IHDLCCommunicator>;
