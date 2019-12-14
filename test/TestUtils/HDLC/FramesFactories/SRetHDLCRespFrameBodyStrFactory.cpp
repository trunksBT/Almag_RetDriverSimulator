#include "SRetHDLCRespFrameBodyStrFactory.hpp"

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameI_Calibrate()
{
   return { "3 fe 31 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameU_LinkEstablishment()
{
   return { "3 93 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_DummyScan()
{
   return { "ff bf 81 f0 8 1 2 33 33 3 2 ff ff " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AddressAssignment()
{
   return {"ff bf 81 f0 11 1 9 4e 4b 34 "
           "36 35 30 30 30 30 2 1 3 4 1 1 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_3GPPReleaseId()
{
   return { "3 bf 81 f0 3 5 1 a " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion()
{
   return { "3 bf 81 f0 3 14 1 2 " };
}
