#include <gmock/gmock.h>

#include <HDLC/HDLCFrameInterpreter.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>

using testing::Eq;

namespace
{
const std::string LINK_ESTABLISHMENT = "3 93 ";
const std::string CALIBRATE_STR = "3 fe 31 ";
}

struct StringToRecognizedFrameType
{
   const FRAME_TYPE expectedFrameType;
   const Hexes expectedHexes;
   const std::string receivedString;
};

class HDLCFrameInterpreterTests:
   public ::testing::TestWithParam<StringToRecognizedFrameType>
{
protected:
   HDLCFrameInterpreter frameInterpreter;
};

TEST_P(HDLCFrameInterpreterTests, InterpretFrameSNRM)
{
   const auto interpretedFrame = frameInterpreter.apply(GetParam().receivedString);

   ASSERT_EQ(GetParam().expectedFrameType,
             interpretedFrame->getType());
   ASSERT_EQ(GetParam().expectedHexes,
             interpretedFrame->build());
}

INSTANTIATE_TEST_CASE_P(InstantiationName,
   HDLCFrameInterpreterTests,
   ::testing::Values(
      StringToRecognizedFrameType{
         FrameI::GET_TYPE,
         std::vector<Hex>({
            0x03,
            BYTE_CONTROL::RETAP,
            static_cast<Hex>(PROCEDURE_CODE::CALIBRATE_SRET)
         }),
         CALIBRATE_STR
      }
   )
);