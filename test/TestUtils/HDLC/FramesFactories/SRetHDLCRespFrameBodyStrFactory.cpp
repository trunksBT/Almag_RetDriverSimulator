#include "SRetHDLCRespFrameBodyStrFactory.hpp"

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameI_Calibrate()
{
   throw std::runtime_error("Not implemented yet");
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameU_LinkEstablishment()
{
   return { "3 73 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_DummyScan()
{
   throw std::runtime_error("Redundant interface feed");
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AddressAssignment()
{
   return { "3 bf 81 f0 12 "
            "1 9 4e 4b 34 36 35 30 30 30 30 "
            "4 1 1 6 2 4e 4b "};
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_3GPPReleaseId()
{
   return { "3 bf 81 f0 3 5 1 8 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return { "3 bf 81 f0 3 14 1 2 " };
}
