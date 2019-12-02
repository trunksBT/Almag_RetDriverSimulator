#include "HDLCFrameBodyInterpreter.hpp"
#include <sstream>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
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
constexpr unsigned IDX_OF_FORMAT_ID_BYTE = 2;
constexpr unsigned IDX_OF_GROUP_ID_BYTE = 3;
constexpr unsigned IDX_OF_GROUP_LENGTH_BYTE = 4;
constexpr unsigned IDX_OF_HDLC_PARAMETERS_START = 5;
constexpr int HEX_BASE = 16;

HexInt toHex(const std::string receivedByteStr)
{
   std::istringstream byteStrStream{receivedByteStr};
   HexInt byteHex;
   byteStrStream >> std::hex >> byteHex;
   return byteHex;
}

int toInt(const std::string receivedByteStr)
{
   return stoi(receivedByteStr, 0, HEX_BASE);
}

Strings slice(const Strings& inVec, int idxOfStart, int length)
{
   auto first = inVec.cbegin() + idxOfStart;
   auto last  = inVec.cbegin() + idxOfStart + length;
   return Strings{first, last};
}

HexesInt toHexes(const Strings& plainFrames, int idxOfStart, int idxOfEnd)
{
   HexesInt retVal;
   for (std::size_t i = idxOfStart; i<idxOfEnd; i++)
   {
      retVal.push_back(toHex(plainFrames.at(i)));
   }
   return retVal;
}

//
//unsigned toInt(const std::string receivedGroupLengthByteStr)
//{
//   std::istringstream byteStrStream;
//   unsigned groupLengthInt;
//   byteStrStream << std::hex << static_cast<int>(receivedGroupLengthByteStr);
//   return byteHex;
//}

std::vector<HDLCParameters> getHdlcParameters(
        const Strings& receivedPlanFrame, unsigned idxOfGroupStart)
{
   std::vector<HDLCParameters> retVal;
   const auto groupLength = toInt(receivedPlanFrame.at(IDX_OF_GROUP_LENGTH_BYTE));
   LOG(debug) << "Group length: " << groupLength;

   for (int i = idxOfGroupStart; i < receivedPlanFrame.size(); i++)
   {
      LOG(debug) << "Str i = " << receivedPlanFrame.at(i);
      LOG(debug) << "Str i+1 = " << receivedPlanFrame.at(i+1);
      LOG(debug) << "int i = " << toInt(receivedPlanFrame.at(i));
      LOG(debug) << "int i+1 = " << toInt(receivedPlanFrame.at(i+1));
      int subGroupLength = toInt(receivedPlanFrame.at(i+1));
      LOG(debug) << "SubGroup length:" << subGroupLength;
//      retVal.push_back(HDLCParameters.build(
//         toHex(receivedPlanFrame.at(i)),
//         toHex(receivedPlanFrame.at(i+1)),
//         toHexes(receivedPlanFrame, i+2, )
//              ))
   }
//   receivedPlainFrame.at(idxOfGroupStart)
   return {};
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

HDLCFrameBodyPtr interpretBodyFrameXID(const Strings& receivedPlainFrame)
{
   auto retFrame = FrameXID()
       .setAddressByte(toHex(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHex(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)))
       .setFormatIdentifierByte(toHex(receivedPlainFrame.at(IDX_OF_FORMAT_ID_BYTE)))
       .setGroupIdentifierByte(toHex(receivedPlainFrame.at(IDX_OF_GROUP_ID_BYTE)));

   LOG(trace) << "SLICING Vec start";
   const auto groupLength = toInt(receivedPlainFrame.at(IDX_OF_GROUP_LENGTH_BYTE));
   LOG(debug) << "Group length: " << groupLength;
   const auto slicedVector = slice(receivedPlainFrame, IDX_OF_HDLC_PARAMETERS_START, groupLength);
   for (const auto& it : slicedVector)
   {
      LOG(trace) << it;
   }
   LOG(trace) << "SLICING Vec end";

//   for (const auto& hdlcParameters : getHdlcParameters(slice(receivedPlainFrame IDX_OF_HDLC_PARAMETERS_START))
//      retFrame.addParameters(hdlcParameters);

   return std::make_shared<FrameXID>(retFrame);
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
   else if (BYTE_CONTROL::XID == ctrlByte)
   {
      return interpretBodyFrameXID(lexedInput);
   }
   LOG(error) << "Frame of unknown type";
   return {};
}
