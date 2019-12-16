#include <gmock/gmock.h>

#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <Utils/Functions.hpp>

using testing::Eq;
using namespace convert;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
FrameStrFactoryPtr retDeviceStrFactory = std::make_shared<SRetHDLCReqFrameBodyStrFactory>();
}

class HDLCReqFrameBodyTests :
   public ::testing::TestWithParam<BuiltFrameStr_ExpectedFrameStr>
{};

TEST_P(HDLCReqFrameBodyTests, BuiltFrame)
{
   ASSERT_THAT(GetParam().builtFrameStr,Eq(GetParam().expectedFrameStr));
}

INSTANTIATE_TEST_CASE_P(HDLCReqFrameBodyTests,
    HDLCReqFrameBodyTests,
    ::testing::Values(
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameXID_DummyScan()->build()),
            retDeviceStrFactory->get_FrameXID_DummyScan()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameXID_AddressAssignment()->build()),
            retDeviceStrFactory->get_FrameXID_AddressAssignment()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameU_LinkEstablishment()->build()),
            retDeviceStrFactory->get_FrameU_LinkEstablishment()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId()->build()),
            retDeviceStrFactory->get_FrameXID_3GPPReleaseId()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion()->build()),
            retDeviceStrFactory->get_FrameXID_AISGProtocolVersion()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameI_Calibrate()->build()),
            retDeviceStrFactory->get_FrameI_Calibrate()
        },
        BuiltFrameStr_ExpectedFrameStr{
            toString(hdlcFrameBodyFactory->get_FrameXID_HDLCParameters()->build()),
            retDeviceStrFactory->get_FrameXID_HDLCParameters()
        }
    )
);
