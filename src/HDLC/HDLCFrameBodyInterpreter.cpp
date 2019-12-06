#include "HDLCFrameBodyInterpreter.hpp"
#include <sstream>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Logger.hpp>
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace convert;
using namespace funs;
using namespace printUtils;

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
constexpr unsigned IDX_OF_SUBGROUP_PAR_ID = 0;
constexpr unsigned IDX_OF_SUBGROUP_LENGTH_BYTE = 1;
constexpr unsigned IDX_OF_SUBGROUP_VALUES_START = 2;
constexpr unsigned OFFSET_FOR_IDX_OF_SUBGROUP_VALUES = 2;
constexpr int HEX_BASE = 16;

HexInt toHexInt(const std::string receivedByteStr)
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

HexesInt toHexesInt(const Strings& plainFrames)
{
   std::vector<HexInt> retVal;
   for (const auto& it : plainFrames)
   {
      retVal.push_back(toHexInt(it));
   }
   return retVal;
}

Hexes toHexes(const HexesInt& plainFrames)
{
   std::vector<Hex> retVal;
   for (const auto& it : plainFrames)
   {
      retVal.push_back(it);
   }
   return retVal;
}

HDLCFrameBodyPtr interpretBodyFrameI(const Strings& receivedPlainFrame)
{
   const auto retFrame = FrameI()
       .setAddressByte(toHexInt(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHexInt(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)))
       .setProcedureCode(toHexInt(receivedPlainFrame.at(IDX_OF_PROC_BYTE)));
   return std::make_shared<FrameI>(retFrame);
}

HDLCFrameBodyPtr interpretBodyFrameSNRM(const Strings& receivedPlainFrame)
{
   const auto retFrame = FrameSNRM()
       .setAddressByte(toHexInt(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHexInt(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)));
   return std::make_shared<FrameSNRM>(retFrame);
}

int addHdlcParametersAndReturnPosition(std::vector<HDLCParameters> &parameters, const Strings &slicedVector, int i)
{
   auto parId = toHexInt(slicedVector.at(i + IDX_OF_SUBGROUP_PAR_ID));
   auto parLen = toInt(slicedVector.at(i + IDX_OF_SUBGROUP_LENGTH_BYTE));
   auto parVals = slice(slicedVector, i + IDX_OF_SUBGROUP_VALUES_START, parLen);
   LOG(debug) << "ParId: " << parId;
   LOG(debug) << "ParLen: " << parLen;
   LOG(debug) << "ParVals: ";
   printStrings(parVals);
   i+=(parLen+OFFSET_FOR_IDX_OF_SUBGROUP_VALUES);
   parameters.push_back(HDLCParameters::build(parId, parLen, toHexes(toHexesInt(parVals))));
   return i;
}

HDLCFrameBodyPtr interpretBodyFrameXID(const Strings& receivedPlainFrame)
{
   auto retFrame = FrameXID()
       .setAddressByte(toHexInt(receivedPlainFrame.at(IDX_OF_ADDR_BYTE)))
       .setControlByte(toHexInt(receivedPlainFrame.at(IDX_OF_CTRL_BYTE)))
       .setFormatIdentifierByte(toHexInt(receivedPlainFrame.at(IDX_OF_FORMAT_ID_BYTE)))
       .setGroupIdentifierByte(toHexInt(receivedPlainFrame.at(IDX_OF_GROUP_ID_BYTE)))
       .setGroupLengthByte(toHexInt(receivedPlainFrame.at(IDX_OF_GROUP_LENGTH_BYTE)));

   std::vector<HDLCParameters> parameters;
   const auto groupLength = toInt(receivedPlainFrame.at(IDX_OF_GROUP_LENGTH_BYTE));
   const auto slicedVector = slice(receivedPlainFrame, IDX_OF_HDLC_PARAMETERS_START, groupLength);
   unsigned int idxOfSubgroupStart = 0;

   while (idxOfSubgroupStart != slicedVector.size())
      idxOfSubgroupStart = addHdlcParametersAndReturnPosition(parameters, slicedVector, idxOfSubgroupStart);

   for (const auto& hdlcParameters : parameters)
      retFrame.addParameters(hdlcParameters);

   return std::make_shared<FrameXID>(retFrame);
}

}  // namespace

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
   HexInt ctrlByte = toHexInt(lexedInput.at(IDX_OF_CTRL_BYTE));

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
