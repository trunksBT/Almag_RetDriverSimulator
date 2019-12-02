#include <gmock/gmock.h>

#include <HDLC/HDLCFrameInterpreter.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetFrameBodyStrFactory.hpp>

using testing::Eq;

namespace
{
FrameStrFactoryPtr retDevice = std::make_shared<SRetFrameBodyStrFactory>();
}

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
         retDevice->get_FrameI_Calibrate().data()
      }
   )
);
