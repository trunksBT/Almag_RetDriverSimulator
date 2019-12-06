#include "MatcherUtils.hpp"

#include <sstream>
#include <HDLC/HDLCFrame.hpp>
#include <Utils/Functions.hpp>

using namespace convert;

std::string toString(std::queue<HDLCFrame>& inQueue)
{
   std::stringstream retVal;
   while (not inQueue.empty()){
      retVal << toString(inQueue.front().build());
      inQueue.pop();
   }
   return retVal.str();
}
