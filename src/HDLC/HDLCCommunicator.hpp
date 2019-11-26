#pragma once

#include <memory>
#include <fstream>
#include <HDLC/IHDLCCommunicator.hpp>

class HDLCCommunicator : public IHDLCCommunicator
{
public:
    HDLCCommunicator() = default;

    bool send(
      const std::string& address, std::shared_ptr<HDLCFrameBody> framePrim) override;
    boost::optional<HDLCFrame> receive(const std::string& address) override;
    virtual boost::optional<std::string> receiveStr(const std::string &address) override;
 
private:
   std::ifstream streamToReceive;
   std::ofstream streamToSend;
};

