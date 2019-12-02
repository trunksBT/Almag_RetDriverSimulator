#include <HDLC/HDLCParameters.hpp>

HDLCParameters::HDLCParameters()
    : parId(ZERO), parLength(ZERO), parValue({})
{}

HDLCParameters::HDLCParameters(Hex inParId, Hex inParLength, Hexes inParValue)
    : parId(inParId), parLength(inParLength), parValue(inParValue)
{}

HDLCParameters HDLCParameters::build(Hex inParId, Hex inParLength, Hexes inParValue)
{
   if (inParLength != inParValue.size())
   {
      LOG(error) << "PL: " << static_cast<int>(inParLength)
                 << ", PV size: " << inParValue.size()
                 << ", returning empty parameters struct";
      return HDLCParameters();
   }
   return {inParId, inParLength, inParValue};
}

