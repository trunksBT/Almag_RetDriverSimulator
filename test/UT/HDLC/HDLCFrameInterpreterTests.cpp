#include <gmock/gmock.h>

#include <HDLC/HDLCFrameBodyInterpreter.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyStrFactory.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <HDLC/HDLCReqFrameBodyFactory.hpp>

using testing::Eq;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
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
          hdlcFrameBodyFactory->get_FrameI_Calibrate()->build(),
          retDeviceStr->get_FrameI_Calibrate()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameSNRM::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameSNRM_LinkEstablishment()->build(),
          retDeviceStr->get_FrameSNRM_LinkEstablishment()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build(),
          retDeviceStr->get_FrameXID_DummyScan()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build(),
          retDeviceStr->get_FrameXID_AddressAssignment()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build(),
          retDeviceStr->get_FrameXID_3GPPReleaseId()
       },
       ExpectedFrameType_ExpectedValue_ReceivedString{
          FrameXID::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build(),
          retDeviceStr->get_FrameXID_AISGProtocolVersion()
       }
   )
);
