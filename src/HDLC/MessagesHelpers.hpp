#pragma once

#include <Utils/TypeAliases.hpp>

const Hex START_STOP_FLAG = 0x7E;
const Hex ZERO = 0x00;
const Hex ADDR_ALLSTATIONS = 0xFF;
const Hex NO_ADDRESS = 0x00;
const Hexes CRC = { 0x13, 0x37 };

enum BYTE_CONTROL : Hex
{
    XID = 0xBF,
    RETAP = 0xFE
};

namespace frameU
{
enum BYTE_CONTROL : Hex
{
   UA = 0x73,
   SNRM = 0x93,
};
}

namespace frameI
{
enum BYTE_CONTROL : Hex
{
   CALIBRATE_REQ = 0x10,
   CALIBRATE_RES = 0x30
};
}


enum FI : Hex
{
   ADDR_ASSIGNMENT = 0x81,
   FI_HDLC_PARAMETERS = 0x81
};

enum GI : Hex
{
   ADDRESS_ASSIGNMENT = 0xF0,
   GI_HDLC_PARAMETERS = 0x80
};

enum PI : Hex
{
   MAX_INF_FIELD_LEN_TRANSMIT = 0x05,
   MAX_INF_FIELD_LEN_RECEIVE = 0x06,
   WINDOW_SIZE_TRANSMIT = 0x07,
   WINDOW_SIZE_RECEIVE = 0x08,
};  // TS_25_462

enum PL : Hex
{
   MAX_INF_FIELD_LEN = 0x04,
   WINDOW_SIZE = 0x01
};  // TS_25_462

enum PV : Hex
{
    THREEGPP_RELEASE_ID_VAL_8 = 0x08,
    AISG_2_0= 0x02
};

enum class IDX_OF : int
{
    GL = 4
};

enum XID_PARAMS_ID : Hex
{
    UNIQUE_ID = 0x01,
    ASSIGNED_ADDRESS = 0x02,
    BIT_MASK = 0x03,
    DEVICE_TYPE = 0x04,
    THREEGPP_RELEASE_ID = 0x05,
    VENDOR_CODE = 0x06,
    AISG_PROTOCOL_VERSION = 0x14
};

enum DEVICE_TYPE : Hex
{
    SRET = 0x01
};

enum PROCEDURE_CODE : Hex
{
   CALIBRATE_SRET = 0x31
};
