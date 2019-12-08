#include <HDLC/ConcreteFrames/FrameSNRM.hpp>
#include <Utils/PrintUtils.hpp>
#include <Utils/Functions.hpp>

using namespace convert;
using namespace printUtils;

FRAME_TYPE FrameSNRM::GET_TYPE=FRAME_TYPE::SNRM;

FrameSNRM::FrameSNRM()
   : FrameU()
{
   setControlByte(BYTE_CONTROL::SNRM);
}

FrameSNRM::FrameSNRM(const std::string& value)
   : FrameU(value)
{
   setControlByte(BYTE_CONTROL::SNRM);
}

FRAME_TYPE FrameSNRM::getType() const
{
   return FRAME_TYPE::SNRM;
}
