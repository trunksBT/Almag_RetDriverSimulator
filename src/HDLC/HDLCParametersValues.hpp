#pragma once

#include <vector>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Logger.hpp>
#include <Utils/TypeAliases.hpp>

struct HDLCParametersValues
{
private:
   HDLCParametersValues();
   HDLCParametersValues(Hex inParId, Hex inParLength, Hexes inParValue);

public:
   static HDLCParametersValues build(Hex inParId, Hex inParLength, Hexes inParValue);

   Hex parId;
   Hex parLength;
   Hexes parValue;
};

