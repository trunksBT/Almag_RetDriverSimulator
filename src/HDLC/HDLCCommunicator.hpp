#pragma once

#include <memory>
#include <fstream>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommunicator : public IHDLCCommunicator
{
public:
   HDLCCommunicator() = default;

   void setupSend(const std::string& address) override {};
   void setupReceive(const std::string& address) override {};
   bool send(const std::string& address, const HDLCFrameBodyPtr frame) override;
   bool send(
     const std::string& address, const std::vector<HDLCFrameBodyPtr>& frames) override;
   std::queue<HDLCFrame> receive(const std::string& address) override;
   boost::optional<std::string> receiveStr(const std::string &address) override;
 
private:
   std::ifstream streamToReceive;
   std::ofstream streamToSend;
};
