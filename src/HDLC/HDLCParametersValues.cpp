#include <HDLC/HDLCParametersValues.hpp>

HDLCParametersValues::HDLCParametersValues()
    : parId(ZERO), parLength(ZERO), parValue({})
{}

HDLCParametersValues::HDLCParametersValues(Hex inParId, Hex inParLength, Hexes inParValue)
    : parId(inParId), parLength(inParLength), parValue(inParValue)
{}

HDLCParametersValues HDLCParametersValues::build(Hex inParId, Hex inParLength, Hexes inParValue)
{
   if (inParLength != inParValue.size())
   {
      LOG(error) << "PL: " << static_cast<int>(inParLength)
                 << ", PV size: " << inParValue.size()
                 << ", returning empty parameters struct";
      return HDLCParametersValues();
   }
   return {inParId, inParLength, inParValue};
}
