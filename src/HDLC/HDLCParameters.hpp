#pragma once

#include <vector>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Logger.hpp>
#include <Utils/TypeAliases.hpp>

struct HDLCParameters
{
private:
   HDLCParameters();
   HDLCParameters(Hex inParId, Hex inParLength, Hexes inParValue);

public:
   static HDLCParameters build(Hex inParId, Hex inParLength, Hexes inParValue);

   Hex parId;
   Hex parLength;
   Hexes parValue;
};

