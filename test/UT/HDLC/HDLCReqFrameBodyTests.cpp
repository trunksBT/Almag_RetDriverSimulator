#include <gmock/gmock.h>

#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <PluginSpecifics/HDLCReqFrameBodyFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCReqFrameBodyStrFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameStrFactory.hpp>
#include <TestUtils/StructsForParametrizedTests.hpp>
#include <Utils/Functions.hpp>

using testing::StrEq;
using namespace convert;

namespace
{
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
FrameStrFactoryPtr retDeviceStrFactory = std::make_shared<SRetHDLCReqFrameBodyStrFactory>();
}

class HDLCReqFrameBodyTests :
   public ::testing::TestWithParam<BuiltFrame_ExpectedFrameStr>
{};

TEST_P(HDLCReqFrameBodyTests, BuiltFrame)
{
   const auto hdlcFrameBody = GetParam().builtFrame;
   ASSERT_THAT(toString(hdlcFrameBody->build()),StrEq(GetParam().expectedFrameStr));
}

INSTANTIATE_TEST_CASE_P(HDLCReqFrameBodyTests,
    HDLCReqFrameBodyTests,
    ::testing::Values(
        BuiltFrame_ExpectedFrameStr{
            hdlcFrameBodyFactory->get_FrameXID_DummyScan(),
            retDeviceStrFactory->get_FrameXID_DummyScan()
        }
    )
);

//TEST_F(HDLCReqFrameBodyTests, L2_XID_AddressAssignment)
//{
//   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_AddressAssignment();
//   ASSERT_THAT(toString(hdlcFrameBody->build()),
//       StrEq(retDeviceStrFactory->get_FrameXID_AddressAssignment()));
//}
//
//TEST_F(HDLCReqFrameBodyTests, L2_U_SNRM_LinkEstablishment)
//{
//   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameU_LinkEstablishment();
//   ASSERT_THAT(toString(hdlcFrameBody->build()),
//       StrEq(retDeviceStrFactory->get_FrameU_LinkEstablishment()));
//}
//
//TEST_F(HDLCReqFrameBodyTests, L2_XID_3GPPReleaseID)
//{
//   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId();
//   ASSERT_THAT(toString(hdlcFrameBody->build()),
//       StrEq(retDeviceStrFactory->get_FrameXID_3GPPReleaseId()));
//}
//
//TEST_F(HDLCReqFrameBodyTests, L2_XID_AISGProtocolVersion)
//{
//   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion();
//   ASSERT_THAT(toString(hdlcFrameBody->build()),
//       StrEq(retDeviceStrFactory->get_FrameXID_AISGProtocolVersion()));
//}
//
//TEST_F(HDLCReqFrameBodyTests, L7_Calibrate)
//{
//   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameI_Calibrate();
//   ASSERT_THAT(toString(hdlcFrameBody->build()),
//       StrEq(retDeviceStrFactory->get_FrameI_Calibrate()));
//}
