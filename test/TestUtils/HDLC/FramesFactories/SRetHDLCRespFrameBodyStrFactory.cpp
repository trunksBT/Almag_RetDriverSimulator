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
   throw std::runtime_error("Not implemented yet");
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_3GPPReleaseId()
{
   throw std::runtime_error("Not implemented yet");
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion()
{
   throw std::runtime_error("Not implemented yet");
}
