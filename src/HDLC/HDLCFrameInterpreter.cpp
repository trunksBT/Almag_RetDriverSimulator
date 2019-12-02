#include "HDLCFrameInterpreter.hpp"
#include <sstream>
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/MessagesHelpers.hpp>

using namespace funs;

namespace
{
constexpr const char* SPACE = " ";
constexpr unsigned IDX_OF_ADDR_BYTE = 0;
constexpr unsigned IDX_OF_CTRL_BYTE = 1;
constexpr unsigned IDX_OF_PROC_BYTE = 2;

HDLCFrameBodyPtr interpretFrameI(const Strings& receivedPlainFrame)
{
   std::istringstream strAdrr(receivedPlainFrame.at(IDX_OF_ADDR_BYTE));
   unsigned int addrByte;
   strAdrr >> std::hex >> addrByte;
   LOG(debug) << "Addr: " << std::hex << addrByte;

   std::istringstream strCtrl(receivedPlainFrame.at(IDX_OF_CTRL_BYTE));
   unsigned int ctrlByte;
   strCtrl >> std::hex >> ctrlByte;
   LOG(debug) << "Ctrl: " << std::hex << ctrlByte;

   std::istringstream strProc(receivedPlainFrame.at(IDX_OF_PROC_BYTE));
   unsigned int procByte;
   strProc >> std::hex >> procByte;
   LOG(debug) << "Proc: " << std::hex << procByte;

   const auto& retFrame = FrameI()
           .setAddressByte(addrByte)
           .setControlByte(ctrlByte)
           .setProcedureCode(procByte);

   return std::make_shared<FrameI>(retFrame);
}

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
   const std::vector<std::string> lexedInput{ lex(receivedPlainFrame, SPACE) };
   LOG(info) << "Input: " << toString(lexedInput);
   const auto interpretedFrame = interpretFrameI(lexedInput);
   printFrame("Interpreted frame: ", interpretedFrame->build());

   return interpretedFrame;
}
