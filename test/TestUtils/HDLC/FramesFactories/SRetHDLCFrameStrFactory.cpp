#include "SRetHDLCFrameStrFactory.hpp"

namespace
{
const std::string_view CALIBRATE_STR = "7e 3 fe 31 13 37 7e ";
const std::string_view LINK_ESTABLISHMENT = "7e 3 93 13 37 7e ";
const std::string_view DUMMY_SCAN_FRAME = "7e ff bf 81 f0 8 1 2 33 33 3 2 ff ff 13 37 7e ";
const std::string_view ADDRESS_ASSIGNMENT_FRAME =
        "7e ff bf 81 f0 1b 1 13 41 4e "
        "30 30 30 30 43 4e 31 30 31 32 "
        "33 33 32 32 34 36 31 2 1 3 4 1 1 13 37 7e ";
const std::string_view THREEGPP_RELEASE_ID = "7e 3 bf 81 f0 3 5 1 a 13 37 7e ";
const std::string_view AISG_PROTOCOL_VERSION = "7e 3 bf 81 f0 3 14 1 2 13 37 7e ";
}

std::string_view SRetHDLCFrameStrFactory::get_FrameI_Calibrate()
{
   return CALIBRATE_STR;
}

std::string_view SRetHDLCFrameStrFactory::get_FrameSNRM_LinkEstablishment()
{
   return LINK_ESTABLISHMENT;
}

std::string_view SRetHDLCFrameStrFactory::get_FrameXID_DummyScan()
{
   return DUMMY_SCAN_FRAME;
}

std::string_view SRetHDLCFrameStrFactory::get_FrameXID_AddressAssignment()
{
   return ADDRESS_ASSIGNMENT_FRAME;
}

std::string_view SRetHDLCFrameStrFactory::get_FrameXID_3GPPReleaseId()
{
   return THREEGPP_RELEASE_ID;
}

std::string_view SRetHDLCFrameStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return AISG_PROTOCOL_VERSION;
}
