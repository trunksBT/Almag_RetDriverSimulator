#include "SRetHDLCFrameBodyHexFactory.hpp"
#include <HDLC/MessagesHelpers.hpp>

Hexes SRetHDLCFrameBodyHexFactory::get_FrameI_Calibrate()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::RETAP,
       PROCEDURE_CODE::CALIBRATE_SRET
   }};
}

Hexes SRetHDLCFrameBodyHexFactory::get_FrameXID_DummyScan()
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

Hexes SRetHDLCFrameBodyHexFactory::get_FrameSNRM_LinkEstablishment()
{
   return std::vector<Hex>{{
       0x03,
       BYTE_CONTROL::SNRM
   }};
}

Hexes SRetHDLCFrameBodyHexFactory::get_FrameXID_AddressAssignment()
{
   return std::vector<Hex>{{
       ADDR_ALLSTATIONS,
       BYTE_CONTROL::XID,
       FI::ADDR_ASSIGNMENT,
       GI::ADDRESS_ASSIGNMENT,
       0x11,

       XID_PARAMS_ID::UNIQUE_ID, 0x09,
       0x4E, 0x4B, 0x34, 0x36, 0x35, 0x30, 0x30, 0x30, 0x30,

       XID_PARAMS_ID::ASSIGNED_ADDRESS, 0x01, 0x03,

       XID_PARAMS_ID::DEVICE_TYPE, 0x01,
       DEVICE_TYPE::SRET,
   }};
}

Hexes SRetHDLCFrameBodyHexFactory::get_FrameXID_3GPPReleaseId()
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

Hexes SRetHDLCFrameBodyHexFactory::get_FrameXID_AISGProtocolVersion()
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
