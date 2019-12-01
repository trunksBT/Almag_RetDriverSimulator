#include <gmock/gmock.h>

#include <HDLC/HDLCFrameInterpreter.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <boost/variant.hpp>

using testing::Eq;

namespace
{
const std::string LINK_ESTABLISHMENT = "3 93 ";
const std::string CALIBRATE_STR = "3 fe 31 ";
}

struct StringToRecognizedFrameType
{
   const std::string receivedString;
   const FRAME_TYPE recognizedFrameType;
};

class HDLCFrameInterpreterTests:
   public ::testing::TestWithParam<StringToRecognizedFrameType>
{
protected:
   HDLCFrameInterpreter frameInterpreter;
};

TEST_P(HDLCFrameInterpreterTests, InterpretFrameSNRM)
{
   const auto CALIBRATE_PRIM_FRAME = FrameI()
           .setAddressByte(0x03)
           .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   ASSERT_EQ(FRAME_TYPE::I, CALIBRATE_PRIM_FRAME.getType());
}

INSTANTIATE_TEST_CASE_P(InstantiationName,
   HDLCFrameInterpreterTests,
   ::testing::Values(
      StringToRecognizedFrameType{
         CALIBRATE_STR,
         FRAME_TYPE::I
      }
   )
);
