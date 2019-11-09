#include <gmock/gmock.h>

#include <boost/crc.hpp>
#include <boost/cstdint.hpp>
#include <HDLC/HDLCFrame.hpp>
#include <HDLC/HDLCFrameBody.hpp>

#include <Utils/Logger.hpp>

using testing::StrEq;
using namespace std::string_literals;

class CRC16Tests : public testing::Test
{
protected:
   //boost::crc_basic<16> crc16_( 0x1021, 0xFFFF, 0, false, false );
   //boost::crc_basic<16> crc16_;
   //boost::crc_basic<16> crc16_( 0x1021, 0xFFFF, 0, false, false );
   boost::crc_ccitt_type crc16_;
};

// Docelowo *****************
// 0xCC49

/*
TEST_F(CRC16Tests, FromDummyScanHardcoded_CRC16_TYPE)
{
   boost::crc_16_type crc16_;

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_BIG_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_LITTLE_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();
}

TEST_F(CRC16Tests, FromDummyScanHardcoded_CRC_CCITT_TYPE)
{
   boost::crc_ccitt_type crc16_;
   //boost::crc_basic<16> crc_ccitt1( 0x1021, 0xFFFF, 0, false, false ); // the same

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_BIG_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_LITTLE_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();
} 

TEST_F(CRC16Tests, FromDummyScanHardcoded_3)
{
   boost::crc_basic<16> crc16_( 0x0F47, 0xFFFF, 0, false, false);

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_BIG_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();

   crc16_.process_bytes(
      DUMMY_SCAN_FRAME_BYTES_LITTLE_ENDIAN, 13);
   LOG(debug) << std::hex << crc16_.checksum();
} 
*/

/*
AFTER its bits have already been inverted and reversed, to the "magic remainder" value 0x0F47 (C/C++ literal value for the ones-complement of 0xF0B8, which is in turn the byte-wise bit-reversal of the literal value 0x1021 given in binary form by the HDLC specification). Accept the HDLC message frame as valid if the comparison is equal. 
*/

