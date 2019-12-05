#include "SRetHDLCFrameBodyStrFactory.hpp"

namespace
{
const std::string CALIBRATE_STR{ "3 fe 31 " };
const std::string LINK_ESTABLISHMENT{ "3 93 " };
const std::string DUMMY_SCAN_FRAME{ "ff bf 81 f0 8 1 2 33 33 3 2 ff ff " };
const std::string ADDRESS_ASSIGNMENT_FRAME{
   "ff bf 81 f0 11 1 9 4e 4b 34 "
   "36 35 30 30 30 30 2 1 3 4 1 1"
};
const std::string THREEGPP_RELEASE_ID = "3 bf 81 f0 3 5 1 a ";
const std::string AISG_PROTOCOL_VERSION{ "3 bf 81 f0 3 14 1 2 " };
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameI_Calibrate()
{
   return CALIBRATE_STR;
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameSNRM_LinkEstablishment()
{
   return LINK_ESTABLISHMENT;
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameXID_DummyScan()
{
   return DUMMY_SCAN_FRAME;
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameXID_AddressAssignment()
{
   return ADDRESS_ASSIGNMENT_FRAME;
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameXID_3GPPReleaseId()
{
   return THREEGPP_RELEASE_ID;
}

std::string SRetHDLCFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return AISG_PROTOCOL_VERSION;
}
