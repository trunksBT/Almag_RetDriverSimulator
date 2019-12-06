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
   std::string getFrameFromSecondary() const;

private: 
   HDLCFrameBodyPtr hdlcFrameBody_;
};

using MaybeHDLCFrame = boost::optional<HDLCFrame>;
using HDLCFramePtr = std::shared_ptr<HDLCFrame>;
