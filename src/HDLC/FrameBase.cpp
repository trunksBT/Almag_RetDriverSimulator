#include <HDLC/FrameBase.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

FrameBase::FrameBase()
{}

FrameBase::FrameBase(const std::string& value)
   : value_(value)
{}

std::string FrameBase::toString() const
{
   if (value_)
   {
      return *value_;
   }
   else
   {
      LOG(error) << defaultVals::FOR_STRING;
      return defaultVals::FOR_STRING;
   }
}

