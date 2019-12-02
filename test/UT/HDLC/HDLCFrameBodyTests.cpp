#include <gmock/gmock.h>

#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/FrameTypes/FrameI.hpp>
#include <HDLC/FrameTypes/FrameSNRM.hpp>
#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/MessagesHelpers.hpp>

using testing::Eq;

class HDLCFrameBodyTests : public testing::Test
{};

TEST_F(HDLCFrameBodyTests, Transceive_L1_XID_DummyScan)
{
   const auto DUMMY_SCAN_HDLC_FRAME_BODY = FrameXID()
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

   ASSERT_THAT(DUMMY_SCAN_HDLC_FRAME_BODY.build(), Eq(
         std::vector<Hex>({
            ADDR_ALLSTATIONS,
            BYTE_CONTROL::XID,
            FI::ADDR_ASSIGNMENT,
            GI::ADDRESS_ASSIGNMENT,
            0x08,
            XID_PARAMS_ID::UNIQUE_ID, 0x02, 0x33, 0x33,
            XID_PARAMS_ID::BIT_MASK, 0x02, 0xFF, 0xFF
         }))); 
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AddressAssignment)
{
   const auto ADDRESS_ASSIGNMENT_HDLC_FRAME_BODY = FrameXID()
      .setAddressByte(ADDR_ALLSTATIONS)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x1B)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::UNIQUE_ID,
         0x13,
         Hexes({ 0x41, 0x4E, 0x30, 0x30, 0x30, 0x30, 0x43, 0x4E, 0x31, 0x30,
                 0x31, 0x32, 0x33, 0x33, 0x32, 0x32, 0x34, 0x36, 0x31 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::ASSIGNED_ADDRESS,
         0x01,
         Hexes({ 0x03 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::DEVICE_TYPE,
         0x01,
         Hexes({ DEVICE_TYPE::SRET })
      ));

   ASSERT_THAT(ADDRESS_ASSIGNMENT_HDLC_FRAME_BODY.build(), Eq(
         std::vector<Hex>({
            ADDR_ALLSTATIONS,
            BYTE_CONTROL::XID,
            FI::ADDR_ASSIGNMENT,
            GI::ADDRESS_ASSIGNMENT,
            0x1B,

            XID_PARAMS_ID::UNIQUE_ID, 0x13,
            0x41, 0x4E, 0x30, 0x30, 0x30, 0x30, 0x43, 0x4E, 0x31, 0x30,
                 0x31, 0x32, 0x33, 0x33, 0x32, 0x32, 0x34, 0x36, 0x31,

            XID_PARAMS_ID::ASSIGNED_ADDRESS, 0x01, 0x03,

            XID_PARAMS_ID::DEVICE_TYPE, DEVICE_TYPE::SRET,
            DEVICE_TYPE::SRET,
         }))); 
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_SNRM_LinkEstablishment)
{
   const auto LINK_ESTABLISHMENT_PRIM_FRAME = FrameSNRM()
      .setAddressByte(0x03);

   ASSERT_THAT(LINK_ESTABLISHMENT_PRIM_FRAME.build(), Eq(
         std::vector<Hex>({
            0x03, 
            BYTE_CONTROL::SNRM
         }))); 
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_3GPPReleaseID)
{
   const auto LINK_ESTABLISHMENT_PRIM_FRAME = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::THREEGPP_RELEASE_ID,
         0x01,
         Hexes({ PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE })
      ));

   ASSERT_THAT(LINK_ESTABLISHMENT_PRIM_FRAME.build(), Eq(
         std::vector<Hex>({
            0x03, 
            BYTE_CONTROL::XID,
            FI::ADDR_ASSIGNMENT,
            GI::ADDRESS_ASSIGNMENT,
            0x03,

            XID_PARAMS_ID::THREEGPP_RELEASE_ID, 0x01,
            PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE
         }))); 
}

TEST_F(HDLCFrameBodyTests, Transceive_L2_XID_AISGProtocolVersion)
{
   const auto LINK_ESTABLISHMENT_PRIM_FRAME = FrameXID()
      .setAddressByte(0x03)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDRESS_ASSIGNMENT)
      .setGroupLengthByte(0x03)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::AISG_PROTOCOL_VERSION,
         0x01,
         Hexes({ PV::AISG_2_0 })
      ));

   ASSERT_THAT(LINK_ESTABLISHMENT_PRIM_FRAME.build(), Eq(
         std::vector<Hex>({
            0x03, 
            BYTE_CONTROL::XID,
            FI::ADDR_ASSIGNMENT,
            GI::ADDRESS_ASSIGNMENT,
            0x03,

            XID_PARAMS_ID::AISG_PROTOCOL_VERSION, 0x01,
            PV::AISG_2_0
         }))); 
}

TEST_F(HDLCFrameBodyTests, Transceive_L7_Calibrate)
{
   const auto CALIBRATE_PRIM_FRAME = FrameI()
      .setAddressByte(0x03)
      .setProcedureCode(PROCEDURE_CODE::CALIBRATE_SRET);

   ASSERT_THAT(CALIBRATE_PRIM_FRAME.build(), Eq(
         std::vector<Hex>({
            0x03,
            BYTE_CONTROL::RETAP,
            PROCEDURE_CODE::CALIBRATE_SRET
         })));
}
