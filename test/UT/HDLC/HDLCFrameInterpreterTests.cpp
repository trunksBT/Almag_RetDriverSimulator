#include <gmock/gmock.h>

#include <HDLC/HDLCFrameBodyInterpreter.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameHexFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyHexFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyStrFactory.hpp>

using testing::Eq;

namespace
{
FrameHexFactoryPtr retDeviceHexFactory = std::make_shared<SRetHDLCFrameBodyHexFactory>();
FrameStrFactoryPtr retDeviceStr = std::make_shared<SRetHDLCFrameBodyStrFactory>();
}


class HDLCFrameInterpreterTests:
   public ::testing::TestWithParam<ExpectedFrameType_ExpectedValue_ReceivedString>
{
protected:
   HDLCFrameBodyInterpreter frameInterpreter;
};

TEST_P(HDLCFrameInterpreterTests, InterpretFrame)
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
          retDeviceHexFactory->get_FrameI_Calibrate(),
          retDeviceStr->get_FrameI_Calibrate()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameSNRM::GET_TYPE,
          retDeviceHexFactory->get_FrameSNRM_LinkEstablishment(),
          retDeviceStr->get_FrameSNRM_LinkEstablishment()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          retDeviceHexFactory->get_FrameXID_DummyScan(),
          retDeviceStr->get_FrameXID_DummyScan()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          retDeviceHexFactory->get_FrameXID_AddressAssignment(),
          retDeviceStr->get_FrameXID_AddressAssignment()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          retDeviceHexFactory->get_FrameXID_3GPPReleaseId(),
          retDeviceStr->get_FrameXID_3GPPReleaseId()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          retDeviceHexFactory->get_FrameXID_AISGProtocolVersion(),
          retDeviceStr->get_FrameXID_AISGProtocolVersion()
       }
   )
);
