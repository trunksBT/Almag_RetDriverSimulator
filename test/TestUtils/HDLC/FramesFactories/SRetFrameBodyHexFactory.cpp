#include "SRetFrameBodyHexFactory.hpp"

namespace
{
const std::string_view CALIBRATE_STR{ "3 fe 31 " };
const std::string_view LINK_ESTABLISHMENT{ "3 93 " };
const std::string_view DUMMY_SCAN_FRAME{ "ff bf 81 f0 8 1 2 33 33 3 2 ff ff " };
const std::string_view ADDRESS_ASSIGNMENT_FRAME{
        "ff bf 81 f0 1b 1 13 41 4e "
        "30 30 30 30 43 4e 31 30 31 32 "
        "33 33 32 32 34 36 31 2 1 3 4 1 1 " };
const std::string THREEGPP_RELEASE_ID = "3 bf 81 f0 3 5 1 a ";
const std::string_view AISG_PROTOCOL_VERSION{ "3 bf 81 f0 3 14 1 2 " };
}

Hexes SRetFrameBodyHexFactory::get_FrameI_Calibrate()
{
   throw std::runtime_error("Not implemented yet");
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_DummyScan()
{
   throw std::runtime_error("Not implemented yet");
}

Hexes SRetFrameBodyHexFactory::get_FrameSNRM_LinkEstablishment()
{
   throw std::runtime_error("Not implemented yet");
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_AddressAssignment()
{
   throw std::runtime_error("Not implemented yet");
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_3GPPReleaseId()
{
   throw std::runtime_error("Not implemented yet");
}

Hexes SRetFrameBodyHexFactory::get_FrameXID_AISGProtocolVersion()
{
   throw std::runtime_error("Not implemented yet");
}
