#pragma once

#include <string>
#include <memory>
#include <vector>
#include <HDLC/FrameBase.hpp>
#include <HDLC/HDLCParameters.hpp>
#include <HDLC/MessagesHelpers.hpp>

class HDLCFrameBody
{
public:
   HDLCFrameBody();
   virtual ~HDLCFrameBody();

   virtual Hexes build() const = 0;
   virtual frameType::BYTE_CTRL getType() const = 0;

protected:
   boost::optional<Hex> address_;
   boost::optional<Hex> ctrl_;
   boost::optional<Hex> formatIdentifier_;
   boost::optional<Hex> groupIdentifier_;
   boost::optional<Hex> groupLength_;
   std::vector<HDLCParameters> parameters_;
};

using HDLCFrameBodyPtr = std::shared_ptr<HDLCFrameBody>;
