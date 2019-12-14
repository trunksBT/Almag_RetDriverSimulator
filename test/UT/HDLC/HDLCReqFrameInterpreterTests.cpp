#include <gmock/gmock.h>

#include <HDLC/HDLCFrameBodyInterpreter.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameU.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>

using testing::Eq;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
FrameStrFactoryPtr retDeviceStr = std::make_shared<SRetHDLCReqFrameBodyStrFactory>();
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
          FrameU::GET_TYPE,
          hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build(),
          retDeviceStr->get_FrameU_SNRM_LinkEstablishment()
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
