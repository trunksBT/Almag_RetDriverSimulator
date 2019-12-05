#pragma once

#include <memory>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrame
{
public:
   explicit HDLCFrame(HDLCFrameBodyPtr inFrame);

   Hexes build() const;
   std::string getFrameFromSecondary() const;

private: 
   std::shared_ptr<HDLCFrameBody> hdlcPrimFrame_;
};

using HDLCFramePtr = std::shared_ptr<HDLCFrame>;
