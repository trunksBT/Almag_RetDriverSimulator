#include <HDLC/HDLCParameters.hpp>

HDLCParameters::HDLCParameters()
        : parId(static_cast<XID_PARAMS_ID>(ZERO)), parLength(ZERO), parValue({})
{}

HDLCParameters::HDLCParameters(XID_PARAMS_ID inParId, Hex inParLength, Hexes inParValue)
        : parId(inParId), parLength(inParLength), parValue(inParValue)
{}

HDLCParameters HDLCParameters::build(
        XID_PARAMS_ID inParId, Hex inParLength, Hexes inParValue)
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

