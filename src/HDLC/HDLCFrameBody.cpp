#include <HDLC/HDLCFrameBody.hpp>

#include <boost/optional/optional_io.hpp>
#include <boost/range/join.hpp>

#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

using namespace funs;

HDLCFrameBody::HDLCFrameBody(const std::string& value)
   : frameFromSecondary_(value)
{}

std::string HDLCFrameBody::getFrameFromSecondary() const
{
   if (frameFromSecondary_)
   {
      return *frameFromSecondary_;
   }
   else
   {
      LOG(error) << defaultVals::FOR_STRING;
      return defaultVals::FOR_STRING;
   }
}

