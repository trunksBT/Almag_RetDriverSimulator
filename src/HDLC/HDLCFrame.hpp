#pragma once

#include <memory>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrame
{
public:
   explicit HDLCFrame(HDLCFrameBodyPtr inFrame);

   Hexes build() const;
   HDLCFrameBodyPtr getFrameBody() const;
   std::string getFrameFromSecondary() const;

private: 
   HDLCFrameBodyPtr hdlcFrameBody_;
};

using HDLCFramePtr = std::shared_ptr<HDLCFrame>;
