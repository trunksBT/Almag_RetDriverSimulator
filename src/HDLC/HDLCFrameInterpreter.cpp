#include "HDLCFrameInterpreter.hpp"
#include <Utils/Logger.hpp>
#include <Utils/UserCommandParser.hpp>

HDLCFrameInterpreter::HDLCFrameInterpreter()
{
   LOG(trace);
}

HDLCFrameInterpreter::~HDLCFrameInterpreter()
{
   LOG(trace);
}

HDLCFrameBodyPtr HDLCFrameInterpreter::apply(const std::string& receivedPlainFrame)
{
   performLexer(receivedPlainFrame)
}
