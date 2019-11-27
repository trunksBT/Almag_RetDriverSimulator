#include <Utils/Utils.hpp>
#include <sstream>
#include <iostream>
#include <Utils/Logger.hpp>
#include <PluginSpecifics/CmdConstraints/AlmagConstraints.hpp>

using namespace defaultVals;
using namespace constraints::almag;

namespace ui
{

std::string actionHelp()
{
   std::stringstream stream;
   stream << "Executing Almag Commands " << END_LINE;
   stream << "L1" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L1::SET_LINK_SPEED << " PathOfRS485Port" << END_LINE;
   stream << "L2" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L2::ADDRESS_ASSIGNMENT << " PathOfRS485Port" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L2::LINK_ESTABLISHMENT << " PathOfRS485Port" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L2::THREEGPP_RELEASE_ID << " PathOfRS485Port" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L2::AISG_PROTOCOL_VERSION << " PathOfRS485Port" << END_LINE;
   stream << "L7" << END_LINE;
   stream << INDENT_OF_SIZE_ONE << SPACE_AS_SEPARATOR << L7::CALIBRATE << " PathOfRS485Port" << END_LINE;
   return stream.str();
}

bool validateUserInput(const Strings& userInput, uint32_t numberOfExpectedArgs)
{
   if (userInput.size() < numberOfExpectedArgs)
   {
      LOG(warning) << "Zbyt mala liczba argumentow "
         << "wpisz 'help' aby zobaczyc liste dostepnych pozycji";
      return false;
   }
   LOG(debug) << "Poprawna liczba argumentow";
   return true;
}

}

std::string multiplyString(int times, const std::string& phrase)
{
   std::stringstream retVal;
   for (int i = 0 ; i<times; i++)
   {
      retVal << phrase;
   }
   return retVal.str();
}

