#include <gmock/gmock.h>

#include <HDLC/MessagesHelpers.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameHexFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyHexFactory.hpp>
#include <CommandPattern/IHDLCFrameBodyFactory.hpp>
#include <HDLC/HDLCReqFrameBodyFactory.hpp>

using testing::Eq;

namespace
{
FrameHexFactoryPtr retDeviceHexFactory = std::make_shared<SRetHDLCFrameBodyHexFactory>();
IHDLCFrameBodyFactoryPtr hdlcFrameBodyFactory = std::make_shared<HDLCReqFrameBodyFactory>();
}

class HDLCFrameBodyTests : public testing::Test
{};

TEST_F(HDLCFrameBodyTests, Transceive_L1_XID_DummyScan)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_DummyScan();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameXID_DummyScan()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AddressAssignment)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_AddressAssignment();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameXID_AddressAssignment()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_SNRM_LinkEstablishment)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameSNRM_LinkEstablishment();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameSNRM_LinkEstablishment()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_3GPPReleaseID)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_3GPPReleaseId();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameXID_3GPPReleaseId()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AISGProtocolVersion)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameXID_AISGProtocolVersion();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameXID_AISGProtocolVersion()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L7_Calibrate)
{
   const auto hdlcFrameBody = hdlcFrameBodyFactory->get_FrameI_Calibrate();
   ASSERT_THAT(hdlcFrameBody->build(),
       Eq(retDeviceHexFactory->get_FrameI_Calibrate()));
}
