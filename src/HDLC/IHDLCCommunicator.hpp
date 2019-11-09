#pragma once

#include <memory>
#include <string>
#include <boost/optional.hpp>

#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/HDLCFrame.hpp>

class IHDLCCommunicator
{
public:
    virtual bool send(
      const std::string& address, std::shared_ptr<HDLCFrameBody> frame) = 0;

    virtual boost::optional<HDLCFrame> receive(const std::string& address) = 0;
    virtual ~IHDLCCommunicator() = default;
};

