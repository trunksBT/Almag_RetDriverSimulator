#include "MatcherUtils.hpp"

#include <sstream>
#include <HDLC/HDLCFrame.hpp>
#include <Utils/PrintUtils.hpp>

using namespace printUtils;

std::string toString(std::queue<HDLCFrame>& inQueue)
{
   std::stringstream retVal;
   while (not inQueue.empty()){
      retVal << toString(inQueue.front().build());
      inQueue.pop();
   }
   return retVal.str();
}
