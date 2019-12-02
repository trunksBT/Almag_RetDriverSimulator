#include "HDLCFrameBodyInterpreter.hpp"
#include <sstream>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>

using namespace funs;

namespace
{
constexpr const char* SPACE = " ";
constexpr unsigned IDX_OF_ADDR_BYTE = 0;
constexpr unsigned IDX_OF_CTRL_BYTE = 1;
constexpr unsigned IDX_OF_PROC_BYTE = 2;

HexInt toHex(const std::string receivedByteStr)
{
   std::istringstream byteStrStream{receivedByteStr};
   HexInt byteHex;
   byteStrStream >> std::hex >> byteHex;
   return byteHex;
}

HDLCFrameBodyPtr interpretBodyFrameI(const Strings& receivedPlainFrame)
{
   const auto retFrame = FrameI()
       .setAddressByte(toHex(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHex(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)))
       .setProcedureCode(toHex(receivedPlainFrame.at(IDX_OF_PROC_BYTE)));
   return std::make_shared<FrameI>(retFrame);
}

HDLCFrameBodyPtr interpretBodyFrameSNRM(const Strings& receivedPlainFrame)
{
   const auto retFrame = FrameSNRM()
       .setAddressByte(toHex(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHex(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)));
   return std::make_shared<FrameSNRM>(retFrame);
}

}

HDLCFrameBodyInterpreter::HDLCFrameBodyInterpreter()
{
   LOG(trace);
}

HDLCFrameBodyInterpreter::~HDLCFrameBodyInterpreter()
{
   LOG(trace);
}

HDLCFrameBodyPtr HDLCFrameBodyInterpreter::apply(const std::string& receivedPlainFrame)
{
   const std::vector<std::string> lexedInput{ lex(receivedPlainFrame, SPACE) };
   LOG(info) << "Input: " << toString(lexedInput);
   HexInt ctrlByte = toHex(lexedInput.at(IDX_OF_CTRL_BYTE));

//   printFrame("Interpreted frame: ", interpretedFrame->build());

   if (BYTE_CONTROL::RETAP == ctrlByte)
   {
      return interpretBodyFrameI(lexedInput);
   }
   else if (BYTE_CONTROL::SNRM == ctrlByte)
   {
      return interpretBodyFrameSNRM(lexedInput);
   }
}
