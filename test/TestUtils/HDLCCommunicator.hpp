//
// Created by pkorycin on 12.11.2019.
//

#pragma once

#include <HDLC/IHDLCCommunicator.hpp>

namespace test
{
class HDLCCommunicator : public IHDLCCommunicator
{
public:
   explicit HDLCCommunicator();

   virtual bool send(
           const std::string &address, std::shared_ptr<HDLCFrameBody> frame);

   virtual boost::optional<HDLCFrame> receive(const std::string &address);

   virtual ~HDLCCommunicator();

private:
   std::shared_ptr<HDLCFrameBody> hdlcFrame_;
};
}  // namespace test