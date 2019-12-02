#pragma once

#include <string>
#include <HDLC/HDLCFrameBody.hpp>

class HDLCFrameBodyInterpreter
{
public:
   HDLCFrameBodyInterpreter();
   ~HDLCFrameBodyInterpreter();
   HDLCFrameBodyPtr apply(const std::string& receivedPlainFrame);
};
