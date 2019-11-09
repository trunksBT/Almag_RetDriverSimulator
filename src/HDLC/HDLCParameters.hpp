#pragma once

#include <vector>
#include <HDLC/MessagesHelpers.hpp>
#include <Utils/Logger.hpp>
#include <Utils/TypeAliases.hpp>

struct HDLCParameters
{
private:
   HDLCParameters();
   HDLCParameters(XID_PARAMS_ID inParId, Hex inParLength, Hexes inParValue);

public:
   static HDLCParameters build(XID_PARAMS_ID inParId, Hex inParLength, Hexes inParValue);

   XID_PARAMS_ID parId;
   Hex parLength;
   Hexes parValue;
};

