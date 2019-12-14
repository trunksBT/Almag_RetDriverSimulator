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
   HDLCFrameBody() = default;
   explicit HDLCFrameBody(const std::string& frameBodyNotParsed);
   virtual ~HDLCFrameBody();

   virtual Hexes build() const {};
   virtual frameType::BYTE_CTRL getType() const {};

   boost::optional<Hex> address_;
   boost::optional<Hex> ctrl_;
   boost::optional<Hex> formatIdentifier_;
   boost::optional<Hex> groupIdentifier_;
   boost::optional<Hex> groupLength_;
   std::vector<HDLCParameters> parameters_;
   
private:
   boost::optional<std::string> frameBodyNotParsed_;
};

using HDLCFrameBodyPtr = std::shared_ptr<HDLCFrameBody>;
