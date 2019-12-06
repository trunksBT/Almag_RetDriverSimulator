#pragma once

#include <memory>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommunicator : public IHDLCCommunicator
{
public:
   HDLCCommunicator() = default;

   void setupSend(const std::string& address) override;
   void setupReceive(const std::string& address) override;
   bool send(const std::string& address, HDLCFrameBodyPtr frame) override;
   HDLCFramePtr receive(const std::string& address) override;
};
