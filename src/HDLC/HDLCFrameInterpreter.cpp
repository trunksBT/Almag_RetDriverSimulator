#include "HDLCFrameInterpreter.hpp"
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>

namespace
{
constexpr const char* SPACE = " ";
}

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
   const std::vector<std::string> lexedInput{ funs::lex(receivedPlainFrame, SPACE) };
   LOG(info) << funs::toString(lexedInput);

   const auto CALIBRATE_PRIM_FRAME = FrameI()
           .setAddressByte(0x03)
           .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   return std::make_shared<FrameI>(CALIBRATE_PRIM_FRAME);
}
