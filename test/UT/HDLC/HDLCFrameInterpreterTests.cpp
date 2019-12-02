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
   public ::testing::TestWithParam<ExpectedFrameType_ExpectedValue_ReceivedString>
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

INSTANTIATE_TEST_CASE_P(HDLCFrameInterpreterTests,
   HDLCFrameInterpreterTests,
   ::testing::Values(
         ExpectedFrameType_ExpectedValue_ReceivedString{
         FrameI::GET_TYPE,
         std::vector<Hex>({
            0x03,
            BYTE_CONTROL::RETAP,
            PROCEDURE_CODE::CALIBRATE_SRET
         }),
         retDevice->get_FrameI_Calibrate().data()
      }
   )
);
