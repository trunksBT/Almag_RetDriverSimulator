#pragma once

#include <memory>
#include <fstream>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommunicator : public IHDLCCommunicator
{
public:
   HDLCCommunicator() = default;

   void setupSend(const std::string& address) override {};
   void receiveSetup(const std::string& address) override {};
   bool send(
     const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   boost::optional<HDLCFrame> receive(const std::string& address) override;
   boost::optional<std::string> receiveStr(const std::string &address) override;
 
private:
   std::ifstream streamToReceive;
   std::ofstream streamToSend;
};
