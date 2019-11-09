#include <gmock/gmock.h>

#include <HDLC/FrameTypes/FrameXID.hpp>
#include <HDLC/HDLCFrameBody.hpp>
#include <HDLC/HDLCFrame.hpp>
#include <HDLC/MessagesHelpers.hpp>

using testing::Eq;

class HDLCFrameTests : public testing::Test
{};

TEST_F(HDLCFrameTests, Transceive_DummyScan)
{
   const auto hdlcPrimFrame = FrameXID()
      .setAddressByte(ADDR_ALLSTATIONS)
      .setFormatIdentifierByte(FI::ADDR_ASSIGNMENT)
      .setGroupIdentifierByte(GI::ADDR_ASSIGNMENT)
      .setGroupLengthByte(0x08)
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::UNIQUE_ID,
         0x02,
         Hexes({ 0x33, 0x33 })))
      .addParameters(HDLCParameters::build(
         XID_PARAMS_ID::BIT_MASK,
         0x02,
         Hexes({ 0xFF, 0xFF })));

   const auto hdlcFrame = HDLCFrame(std::make_shared<FrameXID>(hdlcPrimFrame));

   ASSERT_THAT(hdlcFrame.build(), Eq(
         std::vector<Hex>({
            START_STOP_FLAG,
            ADDR_ALLSTATIONS,
            static_cast<Hex>(BYTE_CONTROL::XID),
            static_cast<Hex>(FI::ADDR_ASSIGNMENT),
            static_cast<Hex>(GI::ADDR_ASSIGNMENT),
            0x08,
            static_cast<Hex>(XID_PARAMS_ID::UNIQUE_ID), 0x02, 0x33, 0x33,
            static_cast<Hex>(XID_PARAMS_ID::BIT_MASK), 0x02, 0xFF, 0xFF,
            CRC.at(0), CRC.at(1),
            START_STOP_FLAG
         })));
}

