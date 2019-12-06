#pragma once

#include <memory>
#include <boost/optional.hpp>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrame
{
public:
   explicit HDLCFrame(HDLCFrameBodyPtr inFrame);

   Hexes build() const;
   HDLCFrameBodyPtr getFrameBody() const;

private: 
   HDLCFrameBodyPtr hdlcFrameBody_;
};

using HDLCFramePtr = std::shared_ptr<HDLCFrame>;
