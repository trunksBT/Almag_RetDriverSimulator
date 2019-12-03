#include <gmock/gmock.h>

#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>
#include <TestUtils/HDLC/FramesFactories/FrameHexFactory.hpp>
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyHexFactory.hpp>

using testing::Eq;

namespace
{
FrameHexFactoryPtr retDeviceHexFactory = std::make_shared<SRetHDLCFrameBodyHexFactory>();
}

class HDLCFrameBodyTests : public testing::Test
{};

TEST_F(HDLCFrameBodyTests, Transceive_L1_XID_DummyScan)
{
   const auto dummyScanFrameBody = FrameXID()
      .setAddressByte(ADDR_ALLSTATIONS)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x08)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::UNIQUE_ID,
         0x02,
         Hexes({ 0x33, 0x33 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::BIT_MASK,
         0x02,
         Hexes({ 0xFF, 0xFF })));

   ASSERT_THAT(dummyScanFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameXID_DummyScan()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AddressAssignment)
{
   const auto addressAssignmentFrameBody = FrameXID()
      .setAddressByte(ADDR_ALLSTATIONS)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x1B)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::UNIQUE_ID,
         0x13,
         Hexes{{
            0x41, 0x4E, 0x30, 0x30, 0x30, 0x30, 0x43, 0x4E, 0x31, 0x30,
            0x31, 0x32, 0x33, 0x33, 0x32, 0x32, 0x34, 0x36, 0x31 }}))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::ASSIGNED_ADDRESS,
         0x01,
         Hexes{{ 0x03 }}))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::DEVICE_TYPE,
         0x01,
         Hexes{{ DEVICE_TYPE::SRET }}
      ));

   ASSERT_THAT(addressAssignmentFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameXID_AddressAssignment()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_SNRM_LinkEstablishment)
{
   const auto linkEstablishmentFrameBody = FrameSNRM()
      .setAddressByte(0x03);

   ASSERT_THAT(linkEstablishmentFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameSNRM_LinkEstablishment()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_3GPPReleaseID)
{
   const auto threeGPPReleaseIDFrameBody = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::THREEGPP_RELEASE_ID,
         0x01,
         Hexes({ PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE })
      ));

   ASSERT_THAT(threeGPPReleaseIDFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameXID_3GPPReleaseId()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AISGProtocolVersion)
{
   const auto aisgProtocolVersionFrameBody = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::AISG_PROTOCOL_VERSION,
         0x01,
         Hexes({ PV::AISG_2_0 })
      ));

   ASSERT_THAT(aisgProtocolVersionFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameXID_AISGProtocolVersion()));
}

TEST_F(HDLCFrameBodyTests, Transceive_L7_Calibrate)
{
   const auto calibrateFrameBody = FrameI()
      .setAddressByte(0x03)
      .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   ASSERT_THAT(calibrateFrameBody.build(),
       Eq(retDeviceHexFactory->get_FrameI_Calibrate()));
}
