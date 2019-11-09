#pragma once

#include <memory>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrame
{
public:
   explicit HDLCFrame(std::shared_ptr<HDLCFrameBody> inFrame);

   Hexes build() const;
   std::string getFrameFromSecondary() const;

private: 
   std::shared_ptr<HDLCFrameBody> hdlcPrimFrame_;
};

