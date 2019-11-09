#pragma once

#include <string>
#include <boost/optional.hpp>
#include <Utils/TypeAliases.hpp>

class FrameBase
{
public:
   FrameBase();
   FrameBase(const std::string& value);

   std::string toString() const;  // only to use after build
   virtual Hexes build() = 0;

   virtual ~FrameBase() = default;

public: 
   boost::optional<std::string> value_;
};

