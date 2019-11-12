#include <HDLC/MessagesHelpers.hpp>

#include <sstream>
#include <Utils/Logger.hpp>
#include <Utils/Utils.hpp>

namespace funs
{

void printHex(const char* msg, Hex input)
{
   LOG(trace) << msg << std::hex << static_cast<int>(input);
}

void printFrame(const char* msg, const Hexes& input)
{
   std::stringstream stream;
   stream << msg;

   for (const auto& it : input)
   {
      stream << std::hex << static_cast<int>(it) << " ";
   }

   LOG(trace) << stream.str();
}

std::string toString(const Hexes& value)
{
   std::stringstream stream;
   for (const auto& it : value)
   {
      stream << std::hex << static_cast<int>(it) << defaultVals::SPACE_AS_SEPARATOR;
   }
   return stream.str();
}  /// TODO remove the last space
}

