#pragma once

#include <Utils/TypeAliases.hpp>

const Hex START_STOP_FLAG = 0x7E;
const Hex ZERO = 0x00;
const Hex ADDR_ALLSTATIONS = 0xFF;
const Hexes CRC = { 0x13, 0x37 };

enum BYTE_CONTROL : Hex
{
    XID = 0xBF,
    UA = 0x73,
    SNRM = 0x93,
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

enum FI : Hex
{
    ADDR_ASSIGNMENT = 0x81
};

enum GI : Hex
{
    ADDRESS_ASSIGNMENT = 0xF0
};

enum PV : Hex
{
    THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE = 0x0A,
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
