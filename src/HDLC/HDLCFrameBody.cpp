#include <HDLC/HDLCFrameBody.hpp>

#include <Utils/Logger.hpp>

HDLCFrameBody::HDLCFrameBody(const std::string& frameBodyNotParsed)
   : frameBodyNotParsed_(frameBodyNotParsed)
{
   LOG(trace);
}

HDLCFrameBody::~HDLCFrameBody()
{
   LOG(trace);
}
