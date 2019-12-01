#pragma once

#include <string>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrameInterpreter
{
public:
   HDLCFrameInterpreter();
   ~HDLCFrameInterpreter();
   HDLCFrameBodyPtr apply(const std::string& receivedPlainFrame);
};
