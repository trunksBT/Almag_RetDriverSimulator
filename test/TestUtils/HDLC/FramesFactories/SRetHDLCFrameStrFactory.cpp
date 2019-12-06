#include "SRetHDLCFrameStrFactory.hpp"
#include <TestUtils/HDLC/FramesFactories/SRetHDLCFrameBodyStrFactory.hpp>
#include <string>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Functions.hpp>
#include <Utils/PrintUtils.hpp>

using namespace std::string_literals;
using namespace convert;
using namespace printUtils;

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
   return toString(START_STOP_FLAG)
          + sRetHdlcFrameBodyStrFactory_->get_FrameSNRM_LinkEstablishment()
          + toString(CRC) + toString(START_STOP_FLAG);
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_DummyScan()
{
   return toString(START_STOP_FLAG)
          + sRetHdlcFrameBodyStrFactory_->get_FrameXID_DummyScan()
          + toString(CRC) + toString(START_STOP_FLAG);
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_AddressAssignment()
{
   return toString(START_STOP_FLAG)
          + sRetHdlcFrameBodyStrFactory_->get_FrameXID_AddressAssignment()
          + toString(CRC) + toString(START_STOP_FLAG);
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_3GPPReleaseId()
{
   return toString(START_STOP_FLAG)
          + sRetHdlcFrameBodyStrFactory_->get_FrameXID_3GPPReleaseId()
          + toString(CRC) + toString(START_STOP_FLAG);
}

std::string SRetHDLCFrameStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return toString(START_STOP_FLAG)
          + sRetHdlcFrameBodyStrFactory_->get_FrameXID_AISGProtocolVersion()
          + toString(CRC) + toString(START_STOP_FLAG);
}
