#include "SRetFrameBodyStrFactory.hpp"

namespace
{
const std::string_view CALIBRATE_STR{ "3 fe 31 " };
const std::string_view LINK_ESTABLISHMENT{ "3 93 " };
const std::string_view DUMMY_SCAN_FRAME{ "ff bf 81 f0 8 1 2 33 33 3 2 ff ff " };
const std::string_view ADDRESS_ASSIGNMENT_FRAME{
   "ff bf 81 f0 "
   "1b "
   "1 13 41 4e 30 30 30 30 43 4e 31 30 31 32 33 33 32 32 34 36 31 "
   "2 1 3 "
   "4 1 1 "
};
const std::string THREEGPP_RELEASE_ID = "3 bf 81 f0 3 5 1 a ";
const std::string_view AISG_PROTOCOL_VERSION{ "3 bf 81 f0 3 14 1 2 " };
}

std::string_view SRetFrameBodyStrFactory::get_FrameI_Calibrate()
{
   return CALIBRATE_STR;
}

std::string_view SRetFrameBodyStrFactory::get_FrameSNRM_LinkEstablishment()
{
   return LINK_ESTABLISHMENT;
}

std::string_view SRetFrameBodyStrFactory::get_FrameXID_DummyScan()
{
   return DUMMY_SCAN_FRAME;
}

std::string_view SRetFrameBodyStrFactory::get_FrameXID_AddressAssignment()
{
   return ADDRESS_ASSIGNMENT_FRAME;
}

std::string_view SRetFrameBodyStrFactory::get_FrameXID_3GPPReleaseId()
{
   return THREEGPP_RELEASE_ID;
}

std::string_view SRetFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return AISG_PROTOCOL_VERSION;
}
