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
   virtual Hexes build() const = 0;
   std::string getFrameFromSecondary() const;
   virtual ~HDLCFrameBody() = default;
   virtual FRAME_TYPE getType() const = 0;

protected:
   HDLCFrameBody() = default;
   explicit HDLCFrameBody(const std::string& value);

   boost::optional<std::string> frameFromSecondary_;
   boost::optional<Hex> address_;
   boost::optional<Hex> ctrl_;
   boost::optional<Hex> formatIdentifier_;
   boost::optional<Hex> groupIdentifier_;
   boost::optional<Hex> groupLength_;
   std::vector<HDLCParameters> parameters_;
};

using HDLCFrameBodyPtr = std::shared_ptr<HDLCFrameBody>;
