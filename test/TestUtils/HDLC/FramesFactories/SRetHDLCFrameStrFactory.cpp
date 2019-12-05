#include "SRetHDLCFrameStrFactory.hpp"
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyStrFactory.hpp>
#include <string>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/PrintUtils.hpp>

using namespace std::string_literals;
using namespace printUtils;

namespace
{
const std::string CALIBRATE_STR = "7e 3 fe 31 13 37 7e ";
const std::string LINK_ESTABLISHMENT = "7e 3 93 13 37 7e ";
const std::string DUMMY_SCAN_FRAME = "7e ff bf 81 f0 8 1 2 33 33 3 2 ff ff 13 37 7e ";
const std::string ADDRESS_ASSIGNMENT_FRAME =
        "7e ff bf 81 f0 11 1 9 4e 4b 34 "
        "36 35 30 30 30 30 2 1 3 4 1 1 13 37 7e ";
const std::string THREEGPP_RELEASE_ID_HDLC_FRAME_STR = "7e 3 bf 81 f0 3 5 1 a 13 37 7e ";
const std::string AISG_PROTOCOL_VERSION_HDLC_FRAME_STR = "7e 3 bf 81 f0 3 14 1 2 13 37 7e ";
}

SRetHDLCFrameStrFactory::SRetHDLCFrameStrFactory()
: sRetHdlcFrameBodyStrFactory_(std::make_shared<SRetHDLCFrameBodyStrFactory>())
{}

std::string SRetHDLCFrameStrFactory::get_FrameI_Calibrate()
{
   return toString(START_STOP_FLAG)
      + sRetHdlcFrameBodyStrFactory_->get_FrameI_Calibrate()
      + toString(CRC) + toString(START_STOP_FLAG);
}

std::string SRetHDLCFrameStrFactory::get_FrameSNRM_LinkEstablishment()
{
   return "7e "s + sRetHdlcFrameBodyStrFactory_->get_FrameSNRM_LinkEstablishment() + "13 37 7e "s;
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_DummyScan()
{
   return DUMMY_SCAN_FRAME;
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_AddressAssignment()
{
   return ADDRESS_ASSIGNMENT_FRAME;
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_3GPPReleaseId()
{
   return THREEGPP_RELEASE_ID_HDLC_FRAME_STR;
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return AISG_PROTOCOL_VERSION_HDLC_FRAME_STR;
}
