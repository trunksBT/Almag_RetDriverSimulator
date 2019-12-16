#include "SRetHDLCRespFrameBodyStrFactory.hpp"

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameI_Calibrate() const
{
   return { "3 30 31 1 0 0 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameU_LinkEstablishment() const
{
   return { "3 73 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_DummyScan() const
{
   throw std::runtime_error("Redundant interface feed");
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_DeviceScan() const
{
   return { "0 bf 81 f0 15 1 9 4e 4b 34 36 35 30 30 30 30 "
            "4 1 1 "
            "6 2 4e 4b "
            "14 1 2 "};
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AddressAssignment() const
{
   return { "3 bf 81 f0 12 "
            "1 9 4e 4b 34 36 35 30 30 30 30 "
            "4 1 1 "
            "6 2 4e 4b "};
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_3GPPReleaseId() const
{
   return { "3 bf 81 f0 3 5 1 8 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_AISGProtocolVersion() const
{
   return { "3 bf 81 f0 3 14 1 2 " };
}

std::string SRetHDLCRespFrameBodyStrFactory::get_FrameXID_HDLCParameters() const
{
   return { "3 bf 81 80 12 5 4 0 0 2 50 6 4 0 0 2 50 7 1 1 8 1 1 "};
}
