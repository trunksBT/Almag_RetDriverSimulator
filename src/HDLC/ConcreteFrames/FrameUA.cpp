#include <HDLC/ConcreteFrames/FrameUA.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

FRAME_TYPE FrameUA::GET_TYPE=FRAME_TYPE::UA;

FrameUA::FrameUA()
   : FrameU()
{
   setControlByte(BYTE_CONTROL::UA);
}

FrameUA::FrameUA(const std::string& value)
   : FrameU(value)
{
   setControlByte(BYTE_CONTROL::UA);
}

FRAME_TYPE FrameUA::getType() const
{
   return FRAME_TYPE::UA;
}
