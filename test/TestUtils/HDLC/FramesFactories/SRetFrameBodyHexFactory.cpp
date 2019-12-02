#include "SRetFrameBodyHexFactory.hpp"
#include <HDLC/MessagesHelpers.hpp>

Hexes SRetFrameBodyHexFactory::get_FrameI_Calibrate()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::RETAP,
       PROCEDURE_CODE::CALIBRATE_SRET
   }};
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_DummyScan()
{
   return std::vector<Hex>{{
       ADDR_ALLSTATIONS,
       BYTE_CONTROL::XID,
       FI::ADDR_ASSIGNMENT,
       GI::ADDRESS_ASSIGNMENT,

       0x08,
       XID_PARAMS_ID::UNIQUE_ID, 0x02, 0x33, 0x33,
       XID_PARAMS_ID::BIT_MASK, 0x02, 0xFF, 0xFF
   }};
}

Hexes SRetFrameBodyHexFactory::get_FrameSNRM_LinkEstablishment()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::SNRM
   }};
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_AddressAssignment()
{
   return std::vector<Hex>{{
       ADDR_ALLSTATIONS,
       BYTE_CONTROL::XID,
       FI::ADDR_ASSIGNMENT,
       GI::ADDRESS_ASSIGNMENT,
       0x1B,

       XID_PARAMS_ID::UNIQUE_ID, 0x13,
       0x41, 0x4E, 0x30, 0x30, 0x30, 0x30, 0x43, 0x4E, 0x31, 0x30,
       0x31, 0x32, 0x33, 0x33, 0x32, 0x32, 0x34, 0x36, 0x31,

       XID_PARAMS_ID::ASSIGNED_ADDRESS, 0x01, 0x03,

       XID_PARAMS_ID::DEVICE_TYPE, 0x01,
       DEVICE_TYPE::SRET,
   }};
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_3GPPReleaseId()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::XID,
       FI::ADDR_ASSIGNMENT,
       GI::ADDRESS_ASSIGNMENT,

       0x03,
       XID_PARAMS_ID::THREEGPP_RELEASE_ID, 0x01,
       PV::THREEGPP_RELEASE_ID_HIGHEST_AVAILABLE
    }};
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_AISGProtocolVersion()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::XID,
       FI::ADDR_ASSIGNMENT,
       GI::ADDRESS_ASSIGNMENT,

       0x03,
       XID_PARAMS_ID::AISG_PROTOCOL_VERSION, 0x01,
       PV::AISG_2_0
   }};
}
